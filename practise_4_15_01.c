#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 题目：实现有序表的递归折半查找算法

typedef int KeyType;

// 在有序数组中递归折半查找关键字
int BinarySearch(KeyType a[], int low, int high, KeyType key)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    else if (key < a[mid])
    {
        return BinarySearch(a, low, mid - 1, key);
    }
    else
    {
        return BinarySearch(a, mid + 1, high, key);
    }
}

int main()
{
    KeyType a[] = { 5,13,18,27,34,42,56 };
    int n = sizeof(a) / sizeof(KeyType);
    KeyType key = 27;

    int pos = BinarySearch(a, 0, n - 1, key);
    if (pos != -1)
    {
        printf("找到关键字 %d，位置为 %d\n", key, pos);
    }
    else
    {
        printf("未找到关键字 %d\n", key);
    }

    return 0;
}
