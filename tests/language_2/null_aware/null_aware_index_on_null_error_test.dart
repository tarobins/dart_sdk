// Copyright (c) 2022, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

// @dart = 2.9

main() {
  null?[0];
  //  ^
  // [analyzer] SYNTACTIC_ERROR.EXPERIMENT_NOT_ENABLED
  //   ^
  // [cfe] Null safety features are disabled for this library.
  // [cfe] The operator '[]' isn't defined for the class 'Null'.
}
