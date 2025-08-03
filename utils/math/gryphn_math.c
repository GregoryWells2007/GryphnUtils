#include "gryphn_math.h"

float gnRadians(const float degrees) { return degrees * (3.14159265358979323846f / 180.0f); }
float gnRoot(const float input, const float n) { return pow(input, 1./n); }
