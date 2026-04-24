#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void ShellSort(int arr[], int n)
{
    int gap;
    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        int i;
        for (i = gap; i < n; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= gap; j = j - gap)
            {
                if (arr[j - gap] > tmp)
                {
                    arr[j] = arr[j - gap];
                }
                else
                {
                    break;
                }
            }
            arr[j] = tmp;
        }
    }
}

int main()
{
    int arr[] = {3,1,4,2,7,5,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    ShellSort(arr, len);
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
