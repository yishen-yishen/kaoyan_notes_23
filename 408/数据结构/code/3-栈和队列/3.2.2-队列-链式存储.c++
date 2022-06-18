#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// 链式队列的一个结点
typedef struct LinkNode
{
    int data;
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
void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;    // 创建新结点
    s->next = NULL; // 插入的链尾
    Q.rear->next = s;
    Q.rear = s;
}

int main()
{
}