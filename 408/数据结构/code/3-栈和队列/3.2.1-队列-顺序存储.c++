#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    // 队头指针和队尾指针
    // front 指向队头元素 index小的那端(非循环状态下)
    // rear 指向队尾元素的后一个位置/下一个应该插入的位置
    int front, rear;
} SqQueue; // 顺序方式实现队列 sequence queue

void InitSqQueue(SqQueue &Q)
{
    Q.rear = 0;
    Q.front = 0;
}

bool QueueEmpty(SqQueue Q)
{
    return Q.rear == Q.front;
}

// 入队
bool EnQueue(SqQueue &Q, int value)
{
    // 判读队列是否已满
    if ((Q.rear + 1) % MaxSize == Q.front)
    {
        return false;
    }
    Q.data[Q.rear] = value;
    // 循环队列(队尾在数组index值大的地方。)
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, int &beDeletedElem)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    beDeletedElem = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int main()
{
    SqQueue Q;
    initSqQueue(Q);
}
