#pragma once
#include "stdint.h"
#include "stdlib.h"

#define GN_ARRAY_LIST(type)\
typedef struct type##ArrayList { \
uint32_t count; \
uint32_t maxSize; \
type* data; \
} type##ArrayList; \
inline static type##ArrayList type##ArrayListCreate() { \
type##ArrayList list;\
list.maxSize = 1; \
list.count = 0;\
list.data = malloc(sizeof(type) * list.maxSize); \
return list; \
}\
inline static void type##ArrayListReserve(type##ArrayList* list, int count) { \
int newCount = count - (list->maxSize - list->count);\
list->data = realloc(list->data, sizeof(type) * (newCount + list->maxSize)); \
list->maxSize += newCount; \
}\
inline static void type##ArrayListExpand(type##ArrayList* list, int count) { \
list->data = realloc(list->data, sizeof(type) * (count + list->maxSize)); \
list->maxSize += count; \
}\
inline static void type##ArrayListAdd(type##ArrayList* list, type data) { \
if (list->count >= list->maxSize) {\
    list->maxSize *= 2; \
    list->data = realloc(list->data, sizeof(type) * list->maxSize); \
} \
list->data[list->count] = data;\
list->count++;\
}\
inline static void type##ArrayListResize(type##ArrayList* list, int count) { \
int newCount = count - (list->maxSize - list->count);\
list->data = realloc(list->data, sizeof(type) * (newCount + list->maxSize)); \
list->maxSize += newCount; \
list->count += count; \
} \
inline static void type##ArrayListRemove(type##ArrayList* list) { \
if (list->count == 0) return; \
list->count--; \
} \
inline static void type##ArrayListPopHead(type##ArrayList* list) { \
if (list->count == 0) return; \
list->count--; \
for (int i = 0; i < list->count; i++) { \
list->data[i] = list->data[i + 1];\
} \
}



//metalAvaliableTextureArrayListPopHead

GN_ARRAY_LIST(int);
GN_ARRAY_LIST(uint32_t);
