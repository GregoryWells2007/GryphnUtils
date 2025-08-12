#include "gryphn_array_list.h"
#include <stdlib.h>

GN_ARRAY_LIST_DEFINITION(uint32_t)
GN_ARRAY_LIST_DEFINITION(int)


void tester() {
    uint32_tArrayList list = uint32_tArrayListCreate();
    uint32_tArrayListResize(list, 1);

    malloc(0);
}
