#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// A 要排序的数组，n 数组长度
void ShellSort(int A[], int n)
{
    int d, i, j;
    // 步长变化
    for (d = n / 2; d >= 1; d = d / 2)
    {

        for (i = d + 1; i <= n; ++i)
        {
            if (A[i] < A[i - d])
            {
                A[0] = A[i - d];
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
                {
                    A[j + d] = A[j];
                }
                A[j + d] = A[0];
            }
        }
    }
}