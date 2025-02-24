// Copyright (c) 2022, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include <emscripten.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

struct MyStruct {
    double x;
    int16_t y;
} s = { 1.0, 2 }, a[10];

EMSCRIPTEN_KEEPALIVE
struct MyStruct* getStruct() {
    return &s;
}

EMSCRIPTEN_KEEPALIVE
void clearStruct(struct MyStruct* s) {
    s->x = 0.0;
    s->y = 0;
}

EMSCRIPTEN_KEEPALIVE
void empty() {}

EMSCRIPTEN_KEEPALIVE
int8_t addInt8(int8_t a, int8_t b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
uint8_t addUint8(uint8_t a, uint8_t b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
int16_t addInt16(int16_t a, int16_t b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
uint16_t addUint16(uint16_t a, uint16_t b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
int32_t addInt32(int32_t a, int32_t b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
uint32_t addUint32(uint32_t a, uint32_t b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
int64_t addInt64(int64_t a, int64_t b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
uint64_t addUint64(uint64_t a, uint64_t b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
bool negateBool(bool a) {
    return !a;
}

static bool b = true;

EMSCRIPTEN_KEEPALIVE
void toggleBool() {
    b = !b;
}

EMSCRIPTEN_KEEPALIVE
bool boolReturn(int a) {
    if (a == 123) {
        return true;
    } else if (a == 456) {
        return false;
    } else {
        return b;
    }
}
