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
list.maxSize = 2; \
list.count = 0;\
list.data = malloc(sizeof(type) * list.maxSize); \
return list; \
}\
inline static void type##ArrayListReserve(type##ArrayList* list, int count) { \
int newCount = count - (list->maxSize - list->count);\
list->data = realloc(list->data, sizeof(type) * (newCount + list->maxSize)); \
list->maxSize += newCount; \
}\
inline static void type##ArrayListResize(type##ArrayList* list, int count) { \
int newCount = count - (list->maxSize - list->count);\
list->data = realloc(list->data, sizeof(type) * (newCount + list->maxSize)); \
list->maxSize += newCount; \
list->count += count; \
}

GN_ARRAY_LIST(int);
