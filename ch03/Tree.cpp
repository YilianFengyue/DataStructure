#include <iostream>
using namespace std;


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
    // 你来补全
    if (T != nullptr) {
        InOrderTraversal(T->Left); // 访问左子树
        cout << T->Data << " ";     // 访问根结点
        InOrderTraversal(T->Right); // 访问右子树
    }
}

/* 示例：创建一棵简单的树并遍历 */
int main() {
    BinTree root = CreateNode(1);
    InsertLeft(root, 2);
    InsertRight(root, 3);
    InsertLeft(root->Left, 4);
    InsertRight(root->Left, 5);

    printf("中序遍历结果：");
    InOrderTraversal(root);
    printf("\n");

    return 0;
}
