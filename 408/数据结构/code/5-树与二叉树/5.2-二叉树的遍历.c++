#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 链式存储
typedef struct BiTNode
{
    // 结点数据
    int data;
    // 结点的左右孩子指针
    struct BiTNode *lchild, *rchild;
} BitNode, *BiTree;

BiTree InitBiTree()
{
    // 插入根结点
    BiTree root = NULL;
    root = (BiTree)malloc(sizeof(BitNode));
    root->data = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}
int visit(BiTree T)
{
    cout << T->data;
}

// 先序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
// 中序遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}
// 后序遍历
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}

int main() {}