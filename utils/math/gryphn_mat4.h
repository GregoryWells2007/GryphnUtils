#pragma once
#include "math.h"
#include "gryphn_vec3.h"

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

static inline const gnMat4x4 gnTranslate(gnVec3 translation) {
    return (gnMat4x4) {
        .mat = {
            { 1.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 1.0f, 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f, 0.0f },
            { translation.x, translation.y, translation.z, 1.0f }
        }
    };
}

static inline const gnMat4x4 gnRotate(gnVec3 axis, float rotation) {
    float c = cos(rotation), s = sin(rotation);

    axis = gnVec3Normalize(axis);
	gnVec3 temp = {
    	((1.0f - c) * axis.x),
    	((1.0f - c) * axis.y),
    	((1.0f - c) * axis.z)
	};

	gnMat4 rotate = {
	    .mat = {
			{ c + temp.x * axis.x, temp.x * axis.y + s * axis.z, temp.x * axis.z - s * axis.y, 0.0f },
			{ temp.y * axis.x - s * axis.z, c + temp.y * axis.y, temp.y * axis.z + s * axis.x, 0.0f },
			{ temp.z * axis.x + s * axis.y, temp.z * axis.y - s * axis.x, c + temp.z * axis.z, 0.0f },
			{ 0.0f, 0.0f, 0.0f, 1.0f },
		}
	};
	return rotate;
}

// used GLMs lookAtLH from /glm/ext/matrix_transform.inl as a base
static inline const gnMat4x4 gnLookAt(gnVec3 eye, gnVec3 center, gnVec3 up) {
    const gnVec3 f = gnVec3Normalize(gnVec3Subtract(center, eye));
    const gnVec3 s = gnVec3Normalize(gnVec3Cross(f, up));
    const gnVec3 u = gnVec3Cross(s, f);

    return (gnMat4x4) {
        .mat = {
            { s.x, u.x, -f.x, 0.0f },
            { s.y, u.y, -f.y, 0.0f },
            { s.z, u.z, -f.z, 0.0f },
            { -gnVec3Dot(s, eye), -gnVec3Dot(u, eye), gnVec3Dot(f, eye), 1.0f }
        }
    };
}
