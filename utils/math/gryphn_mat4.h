#pragma once
#include "math.h"

typedef struct gnMat4x4 {
    float mat[4][4];
} gnMat4x4;
typedef gnMat4x4 gnMat4;

static inline const gnMat4x4 gnIdentity() {
    return (gnMat4x4){
        .mat = {
            { 1.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 1.0f, 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f, 0.0f },
            { 0.0f, 0.0f, 0.0f, 1.0f }
        }
    };
}


static inline const gnMat4x4 gnOrthographic(
    float left, float right, float top, float bottom, float near, float far
) {
    return (gnMat4x4){
        .mat = {
            { (2)/(right-left), 0.0f, 0.0f, -((right+left)/(right-left)) },
            { 0.0f, 2/(top-bottom), 0.0f, -((top+bottom)/(top-bottom)) },
            { 0.0f, 0.0f, -2/(far-near), -((far+near)/(far-near)) },
            { 0.0f, 0.0f, 0.0f, 1.0f }
        }
    };
}

static inline const gnMat4x4 gnProjection(
    float fov, float aspect, float near, float far
) {
    float f = 1.0f / tan(fov * 0.5f);

    return (gnMat4x4){
        .mat = {
            { f / aspect, 0.0f, 0.0f,                             0.0f },
            { 0.0f      , f   , 0.0f,                             0.0f },
            { 0.0f      , 0.0f, (far + near) / (near - far),     -1.0f },
            { 0.0f      , 0.0f, (2 * far * near) / (near - far),  0.0f }
        }
    };
}
