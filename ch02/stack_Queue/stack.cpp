#include <cstdlib>
#include <iostream>
// #include "stack.h"

using namespace std;
typedef int Position;
typedef int ElementType;
ElementType ERROR=9999;
struct SNode
{
    ElementType *Data;
    Position Top;
    int MaxSize;
};

typedef struct SNode *Stack;
Stack CreateStack(int MaxSize){
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
    S->Top=-1;
    S->MaxSize=MaxSize;
    return S;
}

bool IsFull(Stack S)
{
    return(S->Top==S->MaxSize-1);
}

bool Push(Stack S,ElementType X)
{
    if(IsFull(S)){
        cout<<"堆栈已满！"<<endl;
        return false;
    }else{
        S->Data[++(S->Top)]=X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return (S->Top==-1);
}

ElementType Pop(Stack S)
{
    if(IsEmpty(S)){
        cout<<"堆栈空！"<<endl;
        return ERROR;
    }else{
        return (S->Data[(S->Top)--]);
    }
}
int main() {
    Stack s = CreateStack(5);
    Push(s, 10);
    Push(s, 20);
    Push(s,2222);
    cout << Pop(s) << endl; // 输出 20
    cout << Pop(s) << endl; // 输出 10
    cout << Pop(s) << endl; // 栈空，输出 9999（ERROR）
    return 0;
}
