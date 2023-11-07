#ifndef MAIN_H
#define MAIN_H

#include <limits.h>

typedef int Elem_t;
#define SPECIFIER "%d"
const Elem_t POISON_ELEMENT = 666;

struct Node {
    Elem_t  Value;
    struct Node* Next;
    struct Node* Prev;
};

typedef struct Node Node_t;

typedef struct LinkList {
    Node_t* Head;
    Node_t* Tail;
} LinkList_t;

#endif
