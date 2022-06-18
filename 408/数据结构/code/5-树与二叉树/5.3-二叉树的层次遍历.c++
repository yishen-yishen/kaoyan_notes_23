#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// 链式存储的二叉树结点
typedef struct BiTNode
{
    // 结点数据
    int data;
    // 结点的左右孩子指针
    struct BiTNode *lchild, *rchild;
} BitNode, *BiTree;

// 链式队列的一个结点
typedef struct LinkNode
{
    // 队列值存储二叉树结点的指针
    BitNode *data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    // 链式队列的队头和队尾指针
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode)); // 建立头结点
    Q.front->next = NULL;                                    // 初始为空
}

bool IsEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
}

// Q 队列。x 要入队的元素
void EnQueue(LinkQueue &Q, BiTree x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;    // 创建新结点
    s->next = NULL; // 插入的链尾
    Q.rear->next = s;
    Q.rear = s;
}

void LevelOrder()
{
    LinkQueue Q;
    InitQueue(Q); // 初始化辅助队列
    BiTree p;
    EnQueue(Q, p); // 根节点入队
    while (!IsEmpty(Q))
    {
        //
        //
        //
        //
        //
        //
    }
}