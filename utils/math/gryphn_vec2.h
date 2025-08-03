#pragma once
#include "stdint.h"

typedef struct gnVec2 {
    union {
        struct { float a, b; };
        struct { float x, y; };
    };
} gnVec2;
typedef gnVec2 gnFVec2;
typedef gnVec2 gnFloat2;
gnVec2 gnVec2Subtract(gnVec2 a, gnVec2 b);

typedef struct gnUInt2 {
    union {
        struct { uint32_t a, b; };
        struct { uint32_t x, y; };
    };
} gnUInt2;

typedef struct gnInt2 {
    union {
        struct { int a, b; };
        struct { int x, y; };
    };
} gnInt2;
