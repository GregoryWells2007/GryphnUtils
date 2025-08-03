#pragma once
#include "gryphn_vec3.h"

typedef struct gnMat4x4 {
    float mat[4][4];
} gnMat4x4;
typedef gnMat4x4 gnMat4;

gnMat4x4 gnIdentity(void);
gnMat4x4 gnOrthographic(float left, float right, float top, float bottom, float near, float far);
gnMat4x4 gnProjection(float fov, float aspect, float near, float far);
gnMat4x4 gnTranslate(gnVec3 translation);
gnMat4x4 gnRotate(gnVec3 axis, float rotation);
gnMat4x4 gnScale(gnVec3 amount);
gnMat4x4 gnLookAt(gnVec3 eye, gnVec3 center, gnVec3 up);
gnMat4x4 gnMultiply(gnMat4 a, gnMat4 b);
gnVec3 gnMat4MultiplyVec3(gnMat4 m, gnVec3 v);
