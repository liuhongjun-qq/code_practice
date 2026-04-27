#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 快速排序
void quickSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    int pivot = arr[left];
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main()
{
    int a[] = {8, 4, 5, 7, 1, 3, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
