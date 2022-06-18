#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    // 左右线索标志，可定义tag==0 指针指向孩子。
    // tag==1 指向 线索
    int ltag, rtag;
};
