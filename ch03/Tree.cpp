#include <iostream>
using namespace std;
#include <stack>

typedef struct TNode *Position;
typedef int ElementType;
typedef Position BinTree;

struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/* 创建一个新结点（提示） */
BinTree CreateNode(ElementType data) {
    // 你来补全
    BinTree newNode = new TNode;
    newNode->Data = data;
    newNode->Left = nullptr;
    newNode->Right = nullptr;
    return newNode;
}

/* 插入结点到左子树（提示） */
void InsertLeft(BinTree parent, ElementType data) {
    // 你来补全
    if(parent->Left==NULL){
        parent->Left=CreateNode(data);
    }else{
       cout<<"左子树已存在结点，无法插入！"<<endl;
    }

}

/* 插入结点到右子树（提示） */
void InsertRight(BinTree parent, ElementType data) {
    // 你来补全
    if(parent->Right==NULL){
        parent->Right=CreateNode(data);
    }else{
       cout<<"右子树已存在结点，无法插入！"<<endl;
    }
}

/* 中序遍历（提示） */
void InOrderTraversal(BinTree T) {
    stack<BinTree> s;
    while (T != NULL || !s.empty()) {
        while (T != NULL) {
            s.push(T->Data);
            T = T->Left;
        }
        if (!s.empty()) {
            T = s.top();
            s.pop();
            cout << T->Data << " ";
            T = T->Right;
        }
    }
    
}
struct PyPrintConfig {
    string sep = " ";
    string end = "\n";
};


/* 示例：创建一棵简单的树并遍历 */
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();
    cout<<s.top()<<endl;
    
    return 0;
    
}
