#ifndef FUNC_H
#define FUNC_H

int     ListCtor  (LinkList_t* myLinkList);
int     ListDtor  (LinkList_t* myLinkList);
int     InitNode  (Node_t* NewNode);

Node_t* PushFront (Elem_t Value, LinkList_t* myLinkList);
Node_t* PushBack  (Elem_t Value, LinkList_t* myLinkList);

int     PopFront  (LinkList_t* myLinkList);
int     PopBack   (LinkList_t* myLinkList);

Node_t* Insert    (Node_t* InsertNode, Elem_t InsertValue);
int     Erase     (Node_t* EraseNode);

#endif