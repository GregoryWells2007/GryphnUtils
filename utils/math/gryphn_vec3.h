#pragma once
#include "stdint.h"
#include "math.h"

typedef struct gnVec3 {
    union {
        struct { float a, b, c; };
        struct { float x, y, z; };
    };

#ifdef GN_UTILS_CPP
    gnVec3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
    gnVec3(float s) { this->x = s; this->y = s; this->z = s; }
    gnVec3() {};

    gnVec3 operator-(const gnVec3& other) {
        gnVec3 returnGnVec3;
        returnGnVec3.x = this->x - other.x;
        returnGnVec3.y = this->y - other.y;
        returnGnVec3.z = this->z - other.z;
        return returnGnVec3;
    }

    bool operator==(const gnVec3& other) const {
        return this->a == other.a && this->b == other.b && this->c == other.c;
    }
#endif
} gnVec3;

static const inline gnVec3 gnVec3Subtract(gnVec3 a, gnVec3 b) { return (gnVec3){ a.x - b.x, a.y - b.y, a.z - b.z }; }
static const inline gnVec3 gnVec3Add(gnVec3 a, gnVec3 b) { return (gnVec3){ a.x + b.x, a.y + b.y, a.z + b.z }; }
static const inline gnVec3 gnVec3Normalize(gnVec3 in) {
    float lengthOfVector = sqrt((in.x * in.x) + (in.y * in.y) + (in.z * in.z));
    return (gnVec3){in.x / lengthOfVector, in.y / lengthOfVector, in.z / lengthOfVector};
}
static const inline gnVec3 gnVec3Cross(gnVec3 a, gnVec3 b) { return (gnVec3){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x}; }
static const inline float gnVec3Dot(gnVec3 a, gnVec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
static const inline gnVec3 gnVec3Multiply(gnVec3 a, gnVec3 b) { return (gnVec3){ a.x * b.x, a.y * b.y, a.z * b.z }; }
static const inline gnVec3 gnVec3MultiplyBy(gnVec3 a, float b) { return (gnVec3){ a.x * b, a.y * b, a.z * b }; }

typedef gnVec3 gnFVec3;
typedef gnVec3 gnFloat3;

typedef struct gnUInt3 {
    union {
        struct { uint32_t a, b, c; };
        struct { uint32_t x, y, z; };
        struct { uint32_t width, height, depth; };
    };

#ifdef GN_UTILS_CPP
    gnUInt3(uint32_t x, uint32_t y, uint32_t z) { this->x = x; this->y = y; this->z = z; }
    gnUInt3(uint32_t s) { this->x = s; this->y = s; this->z = s; }
    gnUInt3() {};

    gnUInt3 operator-(const gnUInt3& other) {
        gnUInt3 returnGnVec3;
        returnGnVec3.x = this->x - other.x;
        returnGnVec3.y = this->y - other.y;
        returnGnVec3.z = this->z - other.z;
        return returnGnVec3;
    }

    bool operator==(const gnUInt3& other) const {
        return this->a == other.a && this->b == other.b && this->c == other.c;
    }
#endif
} gnUInt3;

typedef gnUInt3 gnUVec3;
typedef gnUInt3 gnExtent3D;

typedef struct gnInt3 {
    union {
        struct { int a, b, c; };
        struct { int x, y, z; };
    };

#ifdef GN_UTILS_CPP
    gnInt3(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }
    gnInt3(int s) { this->x = s; this->y = s; this->z = s; }
    gnInt3() {};

    gnInt3 operator-(const gnInt3& other) {
        gnInt3 returnGnVec3;
        returnGnVec3.x = this->x - other.x;
        returnGnVec3.y = this->y - other.y;
        returnGnVec3.z = this->z - other.z;
        return returnGnVec3;
    }

    bool operator==(const gnInt3& other) const {
        return this->a == other.a && this->b == other.b && this->c == other.c;
    }
#endif
} gnInt3;
