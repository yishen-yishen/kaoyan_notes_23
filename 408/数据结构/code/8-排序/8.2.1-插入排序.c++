#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void InsertSort(int A[], int n)
{
    // i 原始数组的index
    // j 第i个元素，比前面j个元素大吗(递增排序)
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            temp = A[i];
            for (j = i - 1; j > 0 && A[j] > temp; --j)
            {
                A[j + 1] = A[j];
            }
            A[j + 1] = temp;
        }
    }
}

// 折半插入排序-哨兵模式
void HalfInsertSort(int A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++)
    {
        A[0] = A[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
            {
                high = mid - 1;
            }
            else
            {
                // 当A[mid]==A[0]时，为了保证算法的 稳定性，应继续在mid所指位置右边寻找插入位置
                low = mid + 1;
            }
            for (j = i - 1; j > high + 1; --j)
            {
                A[j + 1] = A[j];
            }
            A[high + 1] = A[0];
        }
        {
            /* code */
        }
    }
}