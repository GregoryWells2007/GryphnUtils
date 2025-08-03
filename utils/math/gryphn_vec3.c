#include "gryphn_vec3.h"
#include "math.h"

gnVec3 gnVec3Subtract(gnVec3 a, gnVec3 b) { return (gnVec3){
    .x = a.x - b.x,
    .y = a.y - b.y,
    .z = a.z - b.z };
}
gnVec3 gnVec3Add(gnVec3 a, gnVec3 b) { return (gnVec3){
    .x = a.x + b.x,
    .b = a.y + b.y,
    .c = a.z + b.z };
}
gnVec3 gnVec3Normalize(gnVec3 in) {
    float lengthOfVector = sqrt((in.x * in.x) + (in.y * in.y) + (in.z * in.z));
    return (gnVec3){
        .a = in.x / lengthOfVector,
        .b = in.y / lengthOfVector,
        .c = in.z / lengthOfVector};
}
gnVec3 gnVec3Cross(gnVec3 a, gnVec3 b) { return (gnVec3){
    .x = a.y * b.z - a.z * b.y,
    .y = a.z * b.x - a.x * b.z,
    .z = a.x * b.y - a.y * b.x};
}
float gnVec3Dot(gnVec3 a, gnVec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
gnVec3 gnVec3Multiply(gnVec3 a, gnVec3 b) { return (gnVec3){
    .x = a.x * b.x,
    .y = a.y * b.y,
    .z = a.z * b.z };
}
gnVec3 gnVec3MultiplyBy(gnVec3 a, float b) { return (gnVec3){
    .x = a.x * b,
    .y= a.y * b,
    .z = a.z * b };
}
