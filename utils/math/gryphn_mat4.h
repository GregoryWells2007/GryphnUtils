#pragma once

typedef struct gnMat4x4 {
    float mat[4][4];
} gnMat4x4;
typedef gnMat4x4 gnMat4;

gnMat4x4 gnIdentity() {
    return (gnMat4x4){
        .mat = {
            { 1.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 1.0f, 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f, 0.0f },
            { 0.0f, 0.0f, 0.0f, 1.0f }
        }
    };
}
