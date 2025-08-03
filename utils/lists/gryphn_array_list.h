#pragma once
#include "stdlib.h"

#define GN_ARRAY_LIST_HEADER(type)\
typedef struct type##ArrayList_t* type##ArrayList; \
type##ArrayList type##ArrayListCreate(void); \
void type##ArrayListReserve(type##ArrayList list, int count); \
void type##ArrayListExpand(type##ArrayList list, int count); \
void type##ArrayListAdd(type##ArrayList list, type data); \
void type##ArrayListResize(type##ArrayList list, int count); \
void type##ArrayListRemove(type##ArrayList list); \
void type##ArrayListPopHead(type##ArrayList list); \
uint32_t type##ArrayListCount(type##ArrayList list); \
type type##ArrayListAt(type##ArrayList list, int i); \
type* type##ArrayListRefAt(type##ArrayList list, int i); \
type* type##ArrayListData(type##ArrayList list)

#define GN_ARRAY_LIST_DEFINITION(type)\
typedef struct type##ArrayList_t { \
uint32_t count; \
uint32_t maxSize; \
type* data; \
} type##ArrayList_t; \
type##ArrayList type##ArrayListCreate(void) { \
type##ArrayList list = malloc(sizeof(type##ArrayList_t));\
list->maxSize = 1; \
list->count = 0;\
list->data = malloc(sizeof(type) * list->maxSize); \
return list; \
}\
void type##ArrayListReserve(type##ArrayList list, int count) { \
int newCount = count - (list->maxSize - list->count);\
list->data = realloc(list->data, sizeof(type) * (newCount + list->maxSize)); \
list->maxSize += newCount; \
}\
void type##ArrayListExpand(type##ArrayList list, int count) { \
list->data = realloc(list->data, sizeof(type) * (count + list->maxSize)); \
list->maxSize += count; \
}\
void type##ArrayListAdd(type##ArrayList list, type data) { \
if (list->count >= list->maxSize) {\
    list->maxSize *= 2; \
    list->data = realloc(list->data, sizeof(type) * list->maxSize); \
} \
list->data[list->count] = data;\
list->count++;\
}\
void type##ArrayListResize(type##ArrayList list, int count) { \
int newCount = count - (list->maxSize - list->count);\
list->data = realloc(list->data, sizeof(type) * (newCount + list->maxSize)); \
list->maxSize += newCount; \
list->count += count; \
} \
void type##ArrayListRemove(type##ArrayList list) { \
if (list->count == 0) return; \
list->count--; \
} \
void type##ArrayListPopHead(type##ArrayList list) { \
if (list->count == 0) return; \
list->count--; \
for (uint32_t i = 0; i < list->count; i++) { \
list->data[i] = list->data[i + 1];\
} \
} \
uint32_t type##ArrayListCount(type##ArrayList list) { \
    return list->count; \
} \
type type##ArrayListAt(type##ArrayList list, int i) { \
    return list->data[i]; \
} \
type* type##ArrayListRefAt(type##ArrayList list, int i) { \
    return &list->data[i]; \
} \
type* type##ArrayListData(type##ArrayList list) { \
    return &list->data[0]; \
}


GN_ARRAY_LIST_HEADER(uint32_t);
GN_ARRAY_LIST_HEADER(int);
