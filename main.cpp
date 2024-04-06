#include <stdio.h>
#include <ctype.h>

#include "DLinkList.h"

int main()
{
    DLL_LinkList_t myLinkList = {};
    DLL_Ctor (&myLinkList);

    DLL_PushFront(10, &myLinkList);
    DLL_PushBack(9, &myLinkList);

    printf("%p\n", DLL_Find(9, &myLinkList));
    printf("%p\n", DLL_Find(11, &myLinkList));
    printf("%p\n", DLL_Find(10, &myLinkList));

    DLL_Dtor (&myLinkList);
    return 0;
}