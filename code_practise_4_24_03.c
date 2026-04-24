#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void HeapAdjust(int arr[], int n, int parent)
{
    int max = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    if (left < n && arr[left] > arr[max])
    {
        max = left;
    }
    if (right < n && arr[right] > arr[max])
    {
        max = right;
    }
    if (max != parent)
    {
        int tmp = arr[parent];
        arr[parent] = arr[max];
        arr[max] = tmp;
        HeapAdjust(arr, n, max);
    }
}

void HeapSort(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        HeapAdjust(arr, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        HeapAdjust(arr, i, 0);
    }
}

int main()
{
    int arr[] = {3,1,4,2,7,5,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, len);
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
