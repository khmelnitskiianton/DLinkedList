#include <stdio.h>
#include <ctype.h>

#include "main.h"
#include "func.h"

int main()
{
    LinkList_t myLinkList = {};
    ListCtor (&myLinkList);

    PushFront(10, &myLinkList);
    PushBack(9, &myLinkList);

    ListDtor (&myLinkList);
    return 0;
}