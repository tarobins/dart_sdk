// Copyright (c) 2020, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "vm/compiler/ffi/callback.h"

#include "vm/canonical_tables.h"
#include "vm/class_finalizer.h"
#include "vm/object_store.h"
#include "vm/symbols.h"

namespace dart {

namespace compiler {

namespace ffi {

FunctionPtr NativeCallbackFunction(const FunctionType& c_signature,
                                   const Function& dart_target,
                                   const Instance& exceptional_return,
                                   bool register_function) {
  Thread* const thread = Thread::Current();
  Zone* const zone = thread->zone();
  Function& function = Function::Handle(zone);
  ASSERT(c_signature.IsCanonical());
  ASSERT(exceptional_return.IsSmi() || exceptional_return.IsCanonical());

  // Create a new Function named '<target>_FfiCallback' and stick it in the
  // 'dart:ffi' library. Note that these functions will never be invoked by
  // Dart, so they may have duplicate names.
  const auto& name = String::Handle(
      zone, Symbols::FromConcat(thread, Symbols::FfiCallback(),
                                String::Handle(zone, dart_target.name())));
  const Library& lib = Library::Handle(zone, Library::FfiLibrary());
  const Class& owner_class = Class::Handle(zone, lib.toplevel_class());
  auto& signature = FunctionType::Handle(zone, FunctionType::New());
  function =
      Function::New(signature, name, UntaggedFunction::kFfiTrampoline,
                    /*is_static=*/true,
                    /*is_const=*/false,
                    /*is_abstract=*/false,
                    /*is_external=*/false,
                    /*is_native=*/false, owner_class, TokenPosition::kNoSource);
  function.set_is_debuggable(false);

  // Set callback-specific fields which the flow-graph builder needs to generate
  // the body.
  function.SetFfiCSignature(c_signature);
  function.SetFfiCallbackTarget(dart_target);

  // We need to load the exceptional return value as a constant in the generated
  // function. Even though the FE ensures that it is a constant, it could still
  // be a literal allocated in new space. We need to copy it into old space in
  // that case.
  //
  // Exceptional return values currently cannot be pointers because we don't
  // have constant pointers.
  ASSERT(exceptional_return.IsNull() || exceptional_return.IsNumber() ||
         exceptional_return.IsBool());
  if (!exceptional_return.IsSmi() && exceptional_return.IsNew()) {
    function.SetFfiCallbackExceptionalReturn(Instance::Handle(
        zone, exceptional_return.CopyShallowToOldSpace(thread)));
  } else {
    function.SetFfiCallbackExceptionalReturn(exceptional_return);
  }

  // The dart type of the FfiCallback has no arguments or type arguments and
  // has a result type of dynamic, as the callback is never invoked via Dart,
  // only via native calls that do not use this information. Having no Dart
  // arguments ensures the scope builder does not add inappropriate parameter
  // variables.
  signature.set_result_type(Object::dynamic_type());
  // Finalize (and thus canonicalize) the signature.
  signature ^= ClassFinalizer::FinalizeType(signature);
  function.SetSignature(signature);

  if (register_function) {
    ObjectStore* object_store = thread->isolate_group()->object_store();
    if (object_store->ffi_callback_functions() == Array::null()) {
      FfiCallbackFunctionSet set(
          HashTables::New<FfiCallbackFunctionSet>(/*initial_capacity=*/4));
      object_store->set_ffi_callback_functions(set.Release());
    }
    FfiCallbackFunctionSet set(object_store->ffi_callback_functions());
    function ^= set.InsertOrGet(function);
    object_store->set_ffi_callback_functions(set.Release());
  }

  return function.ptr();
}

}  // namespace ffi

}  // namespace compiler

}  // namespace dart
