#pragma once
#include "stdint.h"

typedef struct gnVec3 {
    union {
        struct { float a, b, c; };
        struct { float x, y, z; };
    };
} gnVec3;

gnVec3 gnVec3Subtract(gnVec3 a, gnVec3 b);
gnVec3 gnVec3Add(gnVec3 a, gnVec3 b);
gnVec3 gnVec3Normalize(gnVec3 in);
gnVec3 gnVec3Cross(gnVec3 a, gnVec3 b);
float gnVec3Dot(gnVec3 a, gnVec3 b);
gnVec3 gnVec3Multiply(gnVec3 a, gnVec3 b);
gnVec3 gnVec3MultiplyBy(gnVec3 a, float b);

typedef gnVec3 gnFVec3;
typedef gnVec3 gnFloat3;

typedef struct gnUInt3 {
    union {
        struct { uint32_t a, b, c; };
        struct { uint32_t x, y, z; };
        struct { uint32_t width, height, depth; };
    };
} gnUInt3;

typedef gnUInt3 gnUVec3;
typedef gnUInt3 gnExtent3D;

typedef struct gnInt3 {
    union {
        struct { int a, b, c; };
        struct { int x, y, z; };
    };
} gnInt3;
