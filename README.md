# Double Link List

Realization of double linked list

[DLinkList.cpp](https://github.com/khmelnitskiianton/DLinkedList/DLinkList.cpp)
[DLinkList.h](https://github.com/khmelnitskiianton/DLinkedList/DLinkList.h)

*Functions*:

- `int         DLL_Ctor        (DLL_LinkList_t* myLinkList);`
- `int         DLL_Dtor        (DLL_LinkList_t* myLinkList);`
- `int         DLL_InitNode    (DLL_Node_t* NewNode);`
- `DLL_Node_t* DLL_PushFront   (DLL_Elem_t Value, DLL_LinkList_t* myLinkList);`
- `DLL_Node_t* DLL_PushBack    (DLL_Elem_t Value, DLL_LinkList_t* myLinkList);`
- `int         DLL_PopFront    (DLL_LinkList_t* myLinkList);`
- `int         DLL_PopBack     (DLL_LinkList_t* myLinkList); `
- `DLL_Node_t* DLL_Insert      (DLL_Node_t* InsertNode, DLL_Elem_t InsertValue);`
- `int         DLL_Erase       (DLL_Node_t* EraseNode);`
- `DLL_Node_t* DLL_Find        (DLL_Elem_t Value, DLL_LinkList_t* myLinkList);`

