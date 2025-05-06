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

//插入
bool Insert(List L,ElementType X,Position P)
{
	Position i;
	if(L->Last==MAXSIZE-1)
	{
		cout<<"已满"<<endl;
		return false;
	}
	if(P<0 || P>L->Last+1)
	{
		cout<<"位置不合法"<<endl;
		return false;
	}
	for(i=L->Last;i>=P;i--)
	{
		// L->Data[i-1]=L->Data[i];错误！
		L->Data[i + 1] = L->Data[i]; 

	}
	L->Data[P]=X;
	L->Last++;
	cout<<"插入成功！"<<endl;
	return true;
}
void PrintList(List L){
	for(int i=0;i<=L->Last;i++)
	{
		cout<<L->Data[i]<<endl;
	}
}
//删除
bool Delete(List L,Position P){
	Position i;
	if (P<0 || P> L->Last)
	{
		cout<<"位置"<<P<<"不存在元素"<<endl;
		return false;
	}
	for(i=P+1;i<= L->Last;i++)
	{
		L->Data[i-1]=L->Data[i];
	}
	L->Last--;
	return true;
}
int main() {
	List myList=MakeEmpty();
	// 插入几个元素
    Insert(myList, 100, 0);  
    Insert(myList, 200, 1);  
    Insert(myList, 300, 2);  
    Insert(myList, 25, 2); 
	//打印
	PrintList(myList);
	//删除
	Delete(myList,1);
	PrintList(myList);
	//查找
	int a=Find(myList,200);
	cout<<a<<endl;
	return 0;
}