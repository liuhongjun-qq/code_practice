#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
 题目：
 设二维数组 a[1...m, 1...n] 含有 m*n 个整数。
 设计算法判断 a 中所有元素是否互不相同，输出相关信息 (yes/no)。
*/

// 输入数组
void inputArray(int a[100][100], int* m, int* n)
{
    printf("请输入行数 m：");
    scanf("%d", m);

    printf("请输入列数 n：");
    scanf("%d", n);

    printf("请输入数组元素：\n");

    int i, j;
    for (i = 1; i <= *m; i++)
    {
        for (j = 1; j <= *n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// 判断是否全部不同
void checkUnique(int a[100][100], int m, int n)
{
    int i, j, p, q;
    int flag = 1; 

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (p = i; p <= m; p++)
            {
                int start;
                if (p == i)
                {
                    start = j + 1;
                }
                else
                {
                    start = 1;
                }

                for (q = start; q <= n; q++)
                {
                    if (a[i][j] == a[p][q])
                    {
                        flag = 0;
                    }
                }
            }
        }
    }
    if (flag == 1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

int main()
{
    int a[100][100];
    int m, n;

    inputArray(a, &m, &n);
    checkUnique(a, m, n);

    return 0;
}