#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
题目：给定仅含0、1、2的数组，使用一次遍历三指针法完成三色旗排序，0在前、1居中、2在后
*/
void DutchFlag(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main()
{
    int a[] = {2, 0, 1, 0, 2, 1, 0};
    int n = 7;
    DutchFlag(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
