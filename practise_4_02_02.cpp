#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
 题目：
 设任意n个整数存放于数组A[1...n]中，设计算法将所有正数排在所有负数前面，
 要求算法时间复杂度为O(n)。
*/

// 输入数组元素
void inputArray(int A[], int* n) {
    printf("请输入数组元素个数 n：");
    scanf("%d", n);
    printf("请输入 %d 个整数（以空格分隔）：\n", *n);
    int i;
    for (i = 1; i <= *n; i++) {
        scanf("%d", &A[i]);
    }
}

// 正数排前、负数排后
void reorderArray(int A[], int n) {
    int left = 1;    
    int right = n;  
    int temp;

    while (left < right) {
        while (left < right && A[left] > 0) {
            left = left + 1;

        while (left < right && A[right] < 0) {
            right = right - 1;
        }
      
        if (left < right) {
            temp = A[left];
            A[left] = A[right];
            A[right] = temp;
            left = left + 1;
            right = right - 1;
        }
    }
}

// 打印数组
void printArray(int A[], int n) {
    printf("排序后的数组：");
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

/
int main() {
    int A[100]; 
    int n;

    inputArray(A, &n);
    reorderArray(A, n);
    printArray(A, n);

    return 0;
}