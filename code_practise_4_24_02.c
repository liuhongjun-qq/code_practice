#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    while (left <= right)
    {
        arr[left] = temp[left];
        left++;
    }
}

void MergeSort(int arr[], int temp[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(arr, temp, left, mid);
    MergeSort(arr, temp, mid + 1, right);
    Merge(arr, temp, left, mid, right);
}

int main()
{
    int arr[] = {3,1,4,2,7,5,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int temp[100];
    MergeSort(arr, temp, 0, len - 1);
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
