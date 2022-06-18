#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// 定义单链表结点类型
typedef struct LNode
{
    // 每个结点存放一个数据类型
    int data;
    // 指针指向下一个结点
    struct LNode *next;
} LNode, *LinkList;

// 初始化一个空的单链表
bool InitListNotHead(LinkList &L)
{
    L = NULL;
    return true;
}

// 初始化一个带头结点的单链表
bool InitListHaveHead(LinkList &L)
{
    // 分配一个头结点
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    // 头结点之后暂时还没有结点
    L->next = NULL;
    return true;
}

// 按位序插入(带头结点)
// @params L 单链表；
// index 位序
// value 要插入的新值
bool ListInsertHaveHead(LinkList &L, int index, int value)
{
    if (index < 1)
        return false;
    // 指针p执行当前扫描到的结点
    LNode *p;
    //  当前p指向的是第几个结点
    int j = 0;
    //  L指向头结点
    p = L;
    // 循环找到 第i-1个结点
    while (p != NULL && j < index - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false; // 插入失败

    // 申请新内存区域，s为新的结点，存放value 和指向 index 的指针
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = value;
    s->next = p->next;
    p->next = s;
    return true; // 插入成功
}
bool ListInsertNotHead(LinkList &L, int index, int value)
{
    if (index < 1)
        return false;
    // 在第一个结点插入新结点
    // 1.将新结点指向头指针
    // 2.将头指针修改为新结点
    if (index == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = value;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1;
    p = L;
    // 循环找到 第i-1个结点
    while (p != NULL && j < index - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false; // 插入失败

    // 申请新内存区域，s为新的结点，存放value 和指向 index 的指针
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = value;
    s->next = p->next;
    p->next = s;
    return true; // 插入成功
}
// 按位序删除
// L 单链表；index 位序；&value 被删除的结点值；
bool ListDelete(LinkList &L, int index, int &value)
{
    // 思路，将index前面一个结点的 next 指向 index 后面一个结点。
    // 释放 index 结点
    if (index < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    // 循环找到 index-1 结点
    while (p != NULL && j < index - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    // q 指向被删除的结点
    LNode *q = q->next;
    value = q->data;
    p->next = q->next;
    free(q);
    return true;
}
// 按位查找
LNode *GetElem(LinkList L, int index)
{
    if (index < 0)
    {
        return NULL;
    }
    // 当前扫描到的指针
    LNode *p;
    int j = 0; // 当前p指向第一个结点
    p = L;
    while ((p != NULL && j < index))
    {
        p = p->next;
        j++;
    }
    return p;
}
// 按值查找
LNode *LocateElem(LinkList L, int target)
{
    LNode *p = L->next;
    int j = 0; // 当前p指向第一个结点
    p = L;
    while ((p != NULL && p->data != target))
    {
        p = p->next;
    }
    return p;
}
// 单链表的建立
// 尾插法
LinkList List_TailInsert(LinkList &L)
{
    int input;
    // 建立头结点
    L = (LinkList)malloc(sizeof(LNode));
    // end 执行表尾
    LNode *temp, *end = L;
    scanf("%d", &input);
    while (input != 9999)
    {
        temp = (LNode *)malloc(sizeof(LNode));
        temp->data = input;
        end->next = temp;
        end = temp;
        scanf("%d", &input);
    }
    end->next = NULL;
    return L;
}

void main()
{
    LinkList L;
    // InitListNotHead(L);
    // InitListHaveHead(L);
    // ListInsertHaveHead(L, 1, 20);
    List_TailInsert(L);

    printf("=========");
}