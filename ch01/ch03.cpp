#include <iostream>
using namespace std;
//预定义
#define MAXSIZE 100
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	Position Last;
};
//初始化
List MakeEmpty()
{
	List L;
	L=(List)malloc(sizeof(struct LNode));
	L->Last=-1;
	return L;
}
// 查找
#define ERROR -1
Position Find(List L,ElementType X)
{
	Position i=0;
	while (i<= L->Last && L->Data[i]!=X)
		i++;
	if(i>L->Last)return ERROR;
	else return i;
}

void PrintList(List L){
	for(int i=0;i<=L->Last;i++)
	{
		if(i>0 && L->Data[i]>0)
        {
            cout<<"+";
            cout<<L->Data[i];
        };
        if(i<L->Last)
        cout<<"x^"<<i<<" ";
	}
    cout<<endl;
}
//插入系数
bool Insert(List L,ElementType X,Position P)
{
    Position i;
    if(L->Last==MAXSIZE-1){
        cout<<"已满，不能插入！"<<endl;
        return false;
    };
    if (P < 0 || P > L->Last + 1) {
        cout << "位置不合法" << endl;
        return false;
    }
    for (i = L->Last; i >= P; i--) {
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[P] = X;
    L->Last++;
    return true;
}
//做加法
void Add(List L1,List L2,List L3)
{
    Position i;
    for(int i=0;i<=L1->Last || i<=L2->Last;i++){
        int x=(i<=L1->Last)? L1->Data[i]:0;
        int y=(i<=L2->Last)? L2->Data[i]:0;
        Insert(L3,x+y,i);
    }
}
int main() {
	List L1=MakeEmpty();
    List L2=MakeEmpty();
    List L3=MakeEmpty();

    int n,s;
    cout<<"多项式1项数:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"多项式1系数";
        cin>>s;
        Insert(L1,s,i);
    }
    cout<<"多项式2项数:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"多项式2系数";
        cin>>s;
        Insert(L2,s,i);
    }
    PrintList(L1);
    PrintList(L2);
    Add(L1,L2,L3);
    PrintList(L3);
    return 0;
}