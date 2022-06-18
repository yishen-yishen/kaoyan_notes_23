
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

// S 主串、T 模式串 、next[] 模式串的 KMP next 数组
int Index_KMP(SString S, SString T, int next[])
{
    // i 主串index j 模式串index
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            // 模式串向右移动
            j = next[j];
        }
        if (j > T.length)
            return i - T.length;
        else
            return 0;
    }
}