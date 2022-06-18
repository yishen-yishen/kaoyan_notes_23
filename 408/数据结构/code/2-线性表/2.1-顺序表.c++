#include <iostream>
#include <iomanip>

#define MaxSize 50

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

// 静态初始化
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

void ListInsert(SqList &L, int i, int e)
{
    // 待插入位置的所有元素后移
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
}

int main()
{
    SqList L;
    InitList(L);
    ListInsert(L, 3, 3);
    // L;
    printf("删除成功");
}
