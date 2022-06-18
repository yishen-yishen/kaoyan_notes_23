#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// 双链表数据结构
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *Dlinklist;
// DNode 强调当前为结点；
// *DLinklist 强调当前为链表

// 初始化(带头结点)
bool InitDLinkList(Dlinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false; // 内存分配失败
    L->prior = NULL;
    L->next = NULL;
    return true;
}

// 插入
// 在p结点之后插入temp结点
bool InsertNextDNode(DNode *p, DNode *temp)
{
    if (p == NULL || temp == NULL)
        return false;
    temp->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = temp;
    }
    temp->prior = p;
    p->next = temp;
}

// 删除
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

int main()
{
    Dlinklist L;
    InitDLinkList(L);
    return 0;
}