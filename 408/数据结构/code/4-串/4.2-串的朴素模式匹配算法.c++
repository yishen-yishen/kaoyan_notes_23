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

// 定位操作 主串 S 模式串 T。返回T在S中第一次出现的位置，否则返回0；
int Index(SString S, SString T)
{
    // 主串的index
    int sIndex = 1;
    // subIndex 子串的index。tIndex 模式串的index
    int subIndex = sIndex, tIndex = 1;
    while (sIndex < S.length && tIndex < T.length)
    {
        // 模式串和子串是否相等
        if (S.ch[subIndex] == T.ch[tIndex])
        {
            ++subIndex;
            ++tIndex;
        }
        else
        {
            // 子串向右移动(sIndex++)
            sIndex++;
            subIndex = sIndex;
            tIndex = 1;
        }
    }
    if (tIndex > T.length)
    {
        return sIndex;
    }
    else
    {
        return 0;
    }
}

int main()
{
}