// Copyright (c) 2018, the Dart project authors. Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

import 'package:analysis_server/src/services/correction/fix.dart';
import 'package:analyzer_plugin/utilities/fixes/fixes.dart';
import 'package:test_reflective_loader/test_reflective_loader.dart';

import 'fix_processor.dart';

void main() {
  defineReflectiveSuite(() {
    defineReflectiveTests(RemoveDeadCodeTest);
  });
}

@reflectiveTest
class RemoveDeadCodeTest extends FixProcessorTest {
  @override
  FixKind get kind => DartFixKind.REMOVE_DEAD_CODE;

  Future<void> test_catch_afterCatchAll_catch() async {
    await resolveTestCode('''
void f() {
  try {
  } catch (e) {
    print('a');
  } catch (e) {
    print('b');
  }
}
''');
    await assertHasFix('''
void f() {
  try {
  } catch (e) {
    print('a');
  }
}
''');
  }

  Future<void> test_catch_afterCatchAll_on() async {
    await resolveTestCode('''
void f() {
  try {
  } on Object {
    print('a');
  } catch (e) {
    print('b');
  }
}
''');
    await assertHasFix('''
void f() {
  try {
  } on Object {
    print('a');
  }
}
''');
  }

  Future<void> test_catch_subtype() async {
    await resolveTestCode('''
class A {}
class B extends A {}
void f() {
  try {
  } on A {
    print('a');
  } on B {
    print('b');
  }
}
''');
    await assertHasFix('''
class A {}
class B extends A {}
void f() {
  try {
  } on A {
    print('a');
  }
}
''');
  }

  Future<void> test_condition() async {
    await resolveTestCode('''
void f(int p) {
  if (true || p > 5) {
    print(1);
  }
}
''');
    await assertHasFix('''
void f(int p) {
  if (true) {
    print(1);
  }
}
''');
  }

  @failingTest
  Future<void> test_do_returnInBody() async {
    // https://github.com/dart-lang/sdk/issues/43511
    await resolveTestCode('''
void f(bool c) {
  do {
    print(c);
    return;
  } while (c);
}
''');
    await assertHasFix('''
void f(bool c) {
  print(c);
}
''');
  }

  Future<void> test_doWhile_atDo() async {
    await resolveTestCode('''
void f(bool c) {
  do {
    print(c);
    return;
  } while (c);
}
''');
    await assertHasFix('''
void f(bool c) {
    print(c);
    return;
}
''', errorFilter: (err) => err.problemMessage.length == 4);
  }

  Future<void> test_doWhile_atDo_noBrackets() async {
    await resolveTestCode('''
void f(bool c) {
  do
    return;
  while (c);
}
''');
    await assertHasFix('''
void f(bool c) {
  return;
}
''', errorFilter: (err) => err.problemMessage.length == 2);
  }

  Future<void> test_doWhile_atWhile() async {
    await resolveTestCode('''
void f(bool c) {
  do {
    print(c);
    return;
  } while (c);
}
''');
    await assertHasFix('''
void f(bool c) {
    print(c);
    return;
}
''', errorFilter: (err) => err.problemMessage.length == 12);
  }

  Future<void> test_doWhile_atWhile_noBrackets() async {
    await resolveTestCode('''
void f(bool c) {
  do
    return;
  while (c);
}
''');
    await assertHasFix('''
void f(bool c) {
  return;
}
''', errorFilter: (err) => err.problemMessage.length == 10);
  }

  Future<void> test_emptyStatement() async {
    await resolveTestCode('''
void f() {
  for (var i = 0; false; i++);
}
''');
    await assertNoFix();
  }

  @failingTest
  Future<void> test_for_returnInBody() async {
    // https://github.com/dart-lang/sdk/issues/43511
    await resolveTestCode('''
void f() {
  for (int i = 0; i < 2; i++) {
    print(i);
    return;
  }
}
''');
    await assertHasFix('''
void f() {
  print(0);
}
''');
  }

  Future<void> test_statements_one() async {
    await resolveTestCode('''
int f() {
  print(0);
  return 42;
  print(1);
}
''');
    await assertHasFix('''
int f() {
  print(0);
  return 42;
}
''');
  }

  Future<void> test_statements_two() async {
    await resolveTestCode('''
int f() {
  print(0);
  return 42;
  print(1);
  print(2);
}
''');
    await assertHasFix('''
int f() {
  print(0);
  return 42;
}
''');
  }
}
