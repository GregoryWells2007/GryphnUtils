#include "../math/gryphn_vec4.h"

#ifdef GN_UTILS_CPP
struct gnColor {
public:
    union {
        struct {
            int r, g, b;
            float a;
        };

        struct {
            int red, green, blue;
            float alpha;
        };
    };
public:
    gnColor(int red, int green, int blue, float alpha = 1.0) {
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->alpha = alpha;
    }

    gnColor(int color, float alpha = 1.0) {
        this->red = color;
        this->green = color;
        this->blue = color;
        this->alpha = alpha;
    }
};
#else
typedef struct gnColor {
    union {
        struct {
            int r, g, b;
            float a;
        };

        struct {
            int red, green, blue;
            float alpha;
        };
    };
} gnColor;
#endif
