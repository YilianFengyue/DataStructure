#ifndef STACK_H
#define STACK_H

typedef int ElementType;
typedef int Position;
extern ElementType ERROR;

struct SNode{
    ElementType* Data;
    Position Top;
    int MaxSize;
};


typedef struct SNode* Stack;

Stack CreateStack(int MaxSize);
bool IsFull(Stack S);
bool Push(Stack S, ElementType X);
bool IsEmpty(Stack S);
ElementType Pop(Stack S);

#endif