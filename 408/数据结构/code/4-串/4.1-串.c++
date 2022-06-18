#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255

// 静态数组实现/定长顺序存储
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString; // sequence string

// 动态数组实现/堆分配存储
typedef struct
{
    // 按串长分配存储区，ch指向串的基地址(串中第一个字符的地址)
    char *ch;
    int length;
} HString;

void initHString()
{
    HString S;
    S.ch = (char *)malloc(MAXLEN * sizeof(char));
    S.length = 0;
}

// 比较两个字符串，若S>T 返回大于0；若S==T 返回0；若S<T 返回小于0
int StrCompare(SString S, SString T)
{
    for (int i = 0; i < S.length && i < T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    // 前方所有字符串都相同，长度更长的串更大
    return S.length - T.length;
}

// 定位操作。在主串S中，查找与T相同的子串，并返回位置，否则返回0
int Index(SString S, SString T)
{
    // int i = 1, n = S.length, m = T.length;
    // SString sub; // 暂存子串
    // while (i <= n0m + 1)
    // {
    // }
}

int main()
{
}
