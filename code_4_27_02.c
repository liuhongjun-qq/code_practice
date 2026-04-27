#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp)
{
    int temp[100];
    int count[10] = {0};
    int i;
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

// 基数排序
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    int exp;
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int main()
{
    int a[] = {8, 4, 5, 7, 1, 3, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);
    radixSort(a, n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
