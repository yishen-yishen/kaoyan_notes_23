#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// 初始化栈 stack
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    // 栈顶指针
    int top;
    // sequence stack 顺序栈
} SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        // 栈空
        return true;
    }
    else
    {
        return false;
    }
}

bool Push(SqStack &S, int value)
{
    if (S.top == MaxSize - 1)
    {
        // 栈满了
        return false;
    }
    // 栈顶指针+1
    S.top = S.top + 1;
    // 新元素入栈
    S.data[S.top] = value;
}

bool Pop(SqStack &S, int &value)
{
    if (S.top == -1)
    {
        return false;
    }
    // 栈顶元素出栈
    value = S.data[S.top];
    // 指针-1
    S.top = S.top - 1;
    return true;
}

int main()
{
    SqStack S;
    InitStack(S);
    return 0;
}