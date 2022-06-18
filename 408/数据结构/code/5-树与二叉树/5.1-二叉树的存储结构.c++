#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
// 二叉树的顺序存储
struct TreeNode
{
    int value;
    bool isEmpty;
};

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

BiTree AddBiTNode(BiTree &t)
{
    BitNode *p = (BitNode *)malloc(sizeof(BiTNode));
    p->data = 2;
    p->lchild = NULL;
    p->rchild = NULL;
    t->lchild = p;
    return t;
}

int main()
{
    TreeNode t[MaxSize];

    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;
    }
    //
    InitBiTree();
}