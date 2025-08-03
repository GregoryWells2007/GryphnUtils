#include "gryphn_vec2.h"

gnVec2 gnVec2Subtract(gnVec2 a, gnVec2 b) {
    gnVec2 ret;
    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    return ret;
}
