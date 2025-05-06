#include <iostream>
using namespace std;

#define ERROR NULL
typedef int ElementType;

typedef struct LNode *PtrToNode;
struct LNode{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
typedef PtrToNode List;
//初始化
List MakeEmpty() {
    List L = (List)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}
//查找
Position Find(List L,ElementType X)
{
    Position p=L;
    while (p&&p->Data!=X)
        p=p->Next;
    if (p)
        return p;
    else
        return ERROR;
}

//插入
bool Insert(List L,ElementType X,Position P)
{
    Position tmp,pre;
    for(pre=L;pre&&pre->Next!=P;pre=pre->Next);
    if(pre ==NULL)
    {
        cout<<"插入位置错误"<<endl;
        return false;
    }else{
        tmp=(Position)malloc(sizeof(struct LNode));
        tmp->Data=X;
        tmp->Next=P;
        pre->Next=tmp;
        return true;
    }
}

//删除
bool Delete (List L,Position P)
{
    Position pre;
    for(pre=L;pre&&pre->Next!=P;pre=pre->Next);
    if(pre==NULL||P==NULL)
    {
        cout<<"位置错误"<<endl;
    }else{
        pre->Next=P->Next;
        free(P);
        return true;
    }
}
void PrintList(List L) {
    Position p = L->Next; // 跳过头结点
    while (p) {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout << endl;
}
int main()
{
    List list = MakeEmpty();
    Insert(list,200,list->Next);
    Insert(list,300,list->Next);
    PrintList(list);
    Position a=Find(list,300);
    cout<<a<<endl;
    Position p = Find(list, 200);
    if (p)
        Delete(list, p);
    PrintList(list);
    return 0;
}