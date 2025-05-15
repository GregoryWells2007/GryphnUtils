#pragma once

// why would one use a linked list
typedef struct gnLinkedList {
    void* data;
    gnLinkedList* nextNode;
} gnLinkedList;
