#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 查找 返回值带* 。返回值是引用类型/指针
// 最坏空间复杂度 1
BSTNode *BST_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key)
    {
        if (key < T->key)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

// 递归查找
// 最坏空间复杂度 O(h) h 树高
BSTNode *BST_Search_Recursion(BSTree T, int key)
{
    if (T == NULL)
        return NULL; // 查找失败，退出递归
    if (key == T->key)
        return T; // 查找成功。退出递归
    else if (key < T->key)
        return BST_Search_Recursion(T->lchild, key);
    else
        return BST_Search_Recursion(T->rchild, key);
}

// 递归插入
bool BST_Insert_Recursion(BSTree &T, int k)
{
    if (T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = NULL;
        T->rchild = NULL;
        return true;
    }
    else if (k == T->key)
        return false; // 此值已经存在，插入失败
    else if (k < T->key)
        return BST_Insert_Recursion(T->lchild, k);
    else
        return BST_Insert_Recursion(T->rchild, k);
}

// 构造二叉排序树
void Creat_BST(BSTree &T, int str[], int strLength)
{
    T = NULL;
    int i = 0;
    while (i < strLength)
    {
        BST_Insert_Recursion(T, str[i]);
        i++;
    }
}

// 二叉排序树的删除


int main()
{
    BSTree T;
    int strLength = 8;
    int array1[] = {50, 66, 60, 26, 21, 30, 70, 68};
    Creat_BST(T, array1, strLength);
    return 0;
}