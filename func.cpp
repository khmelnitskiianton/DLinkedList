#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "main.h"
#include "func.h"
#include "myassert.h"

int ListCtor (LinkList_t* myLinkList)
{
    MYASSERT(myLinkList, BAD_POINTER_PASSED_IN_FUNC, return 0)

    myLinkList -> Head = NULL;
    myLinkList -> Tail = NULL;

    return 1;
}

int ListDtor (LinkList_t* myLinkList)
{
    MYASSERT(myLinkList, BAD_POINTER_PASSED_IN_FUNC, return 0)

    Node_t* NextNode = NULL;
    
    NextNode = (myLinkList -> Head) -> Next;

    while(NextNode != NULL)
    {
        PopFront(myLinkList);
        NextNode = (myLinkList -> Head) -> Next;
    }

    return 1;
}

int InitNode  (Node_t* NewNode)
{
    MYASSERT(NewNode, BAD_POINTER_PASSED_IN_FUNC, return 0)

    NewNode -> Next = NULL;
    NewNode -> Prev = NULL;
    NewNode -> Value = POISON_ELEMENT;

    return 1;
}

Node_t* PushFront (Elem_t Value, LinkList_t* myLinkList)
{
    MYASSERT(myLinkList, BAD_POINTER_PASSED_IN_FUNC, return 0)
    Node_t* NewNode = (Node_t*) calloc (1,sizeof (Node_t));
    MYASSERT(NewNode, CRASH_IN_CALLOC_OF_NODE, return 0)
    
    InitNode(NewNode);

    if ((myLinkList -> Head == NULL) && (myLinkList -> Tail == NULL))
    {
        myLinkList -> Head = NewNode;
        myLinkList -> Tail = NewNode;
        NewNode -> Value = Value;
        return NULL;
    }

    Node_t* OldHead = myLinkList -> Head;
    myLinkList -> Head = NewNode;
    
    NewNode -> Value = Value;
    NewNode -> Prev = NULL;
    NewNode -> Next = OldHead;

    OldHead -> Prev = NewNode;

    return NewNode;
}

Node_t* PushBack  (Elem_t Value, LinkList_t* myLinkList)
{
    MYASSERT(myLinkList, BAD_POINTER_PASSED_IN_FUNC, return 0)
    Node_t* NewNode = (Node_t*) calloc (1, sizeof (Node_t));
    MYASSERT(NewNode, CRASH_IN_CALLOC_OF_NODE, return 0)

    InitNode(NewNode);

    if ((myLinkList -> Head == NULL) && (myLinkList -> Tail == NULL))
    {
        myLinkList -> Head = NewNode;
        myLinkList -> Tail = NewNode;
        NewNode -> Value = Value;
        return NULL;
    }

    Node_t* OldTail = myLinkList -> Tail;
    myLinkList -> Tail = NewNode;
    
    NewNode -> Value = Value;
    NewNode -> Next = NULL;
    NewNode -> Prev = OldTail;

    OldTail -> Next = NewNode;

    return NewNode;
}

int PopFront  (LinkList_t* myLinkList)
{
    MYASSERT(myLinkList, BAD_POINTER_PASSED_IN_FUNC, return 0)
    MYASSERT(myLinkList -> Head, POP_FRONT_BUT_HEAD_NULL, return 0)

    Node_t* PopNode = myLinkList -> Head;
    myLinkList -> Head = PopNode -> Next;
    (myLinkList -> Head) -> Prev = NULL;

    free(PopNode);
    
    return 1;
}

int PopBack   (LinkList_t* myLinkList)
{
    MYASSERT(myLinkList, BAD_POINTER_PASSED_IN_FUNC, return 0)
    MYASSERT(myLinkList -> Tail, POP_FRONT_BUT_TAIL_NULL, return 0)

    Node_t* PopNode = myLinkList -> Tail;
    myLinkList -> Tail = PopNode -> Prev;
    (myLinkList -> Head) -> Next = NULL;

    free(PopNode);
    
    return 1;
}

Node_t* Insert (Node_t* InsertNode, Elem_t InsertValue)
{
    MYASSERT(InsertNode,  BAD_POINTER_PASSED_IN_FUNC, return 0)

    Node_t* NewNode = (Node_t*) calloc (1, sizeof (Node_t));
    MYASSERT(NewNode, CRASH_IN_CALLOC_OF_NODE, return 0)

    InitNode(NewNode);

    NewNode -> Value = InsertValue;
    NewNode -> Next = InsertNode -> Next;
    NewNode -> Prev = InsertNode;

    (InsertNode -> Next) -> Prev = NewNode;
    InsertNode -> Next = NewNode;

    return NewNode;
}

int Erase (Node_t* EraseNode)
{
    MYASSERT(EraseNode, BAD_POINTER_PASSED_IN_FUNC, return 0)
    MYASSERT((EraseNode -> Next != NULL) && (EraseNode -> Prev != NULL), ERASE_HEAD_OR_TALE,return 0)

    Node_t* PrevNode = EraseNode -> Prev;
    Node_t* NextNode = EraseNode -> Next;

    PrevNode -> Next = NextNode;
    NextNode -> Prev = PrevNode;
    free(EraseNode);

    return 1;
}