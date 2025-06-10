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
    return (gnMat4x4){
        .mat = {
            { 1/(aspect * tan(fov/2)), 0.0f, 0.0f, 0.0f },
            { 0.0f, 1/tan(fov/2), 0.0f, 0.0f },
            { 0.0f, 0.0f, -((far+near)/(far-near)), -((2*far*near)/(far-near)) },
            { 0.0f, 0.0f, -1.0f, 1.0f }
            // { 1/(aspect * tan(fov/2)), 0.0f, 0.0f, 0.0f },
            // { 0.0f, 1/tan(fov/2), 0.0f, 0.0f },
            // { 0.0f, 0.0f, -((far+near)/(far-near)), -((2*far*near)/(far-near)) },
            // { 0.0f, 0.0f, -1.0f, 0.0f }
        }
    };
}
