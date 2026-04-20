#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAXSIZE 20
typedef int KeyType;

typedef struct {
    KeyType key;
    int otherinfo;
} RedType;

typedef struct {
    RedType r[MAXSIZE + 1];
    int length;
} SqList;

// 直接插入排序
void InsertSort(SqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) {
        if (L->r[i].key < L->r[i-1].key) {
            L->r[0] = L->r[i];
            for (j = i - 1; L->r[0].key < L->r[j].key; j--) {
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
}

// 折半插入排序
void BInsertSort(SqList *L) {
    int i, j, low, high, mid;
    for (i = 2; i <= L->length; i++) {
        L->r[0] = L->r[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (L->r[0].key < L->r[mid].key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--) {
            L->r[j + 1] = L->r[j];
        }
        L->r[high + 1] = L->r[0];
    }
}

// 希尔排序（一趟）
void ShellInsert(SqList *L, int dk) {
    int i, j;
    for (i = dk + 1; i <= L->length; i++) {
        if (L->r[i].key < L->r[i - dk].key) {
            L->r[0] = L->r[i];
            for (j = i - dk; j > 0 && L->r[0].key < L->r[j].key; j -= dk) {
                L->r[j + dk] = L->r[j];
            }
            L->r[j + dk] = L->r[0];
        }
    }
}

// 希尔排序（完整）
void ShellSort(SqList *L, int dt[], int t) {
    int k;
    for (k = 0; k < t; k++) {
        ShellInsert(L, dt[k]);
    }
}

// 冒泡排序
void BubbleSort(SqList *L) {
    int i, j, flag;
    RedType temp;
    for (i = 1; i <= L->length - 1; i++) {
        flag = 0;
        for (j = 1; j <= L->length - i; j++) {
            if (L->r[j].key > L->r[j + 1].key) {
                temp = L->r[j];
                L->r[j] = L->r[j + 1];
                L->r[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    int i;
    int dt[] = {5, 3, 1};
    int t = 3;

    SqList L1, L2, L3, L4;
    int arr[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;

    // 直接插入排序测试
    L1.length = n;
    for (i = 1; i <= n; i++) {
        L1.r[i].key = arr[i - 1];
    }
    InsertSort(&L1);
    printf("直接插入排序结果：");
    for (i = 1; i <= n; i++) {
        printf("%d ", L1.r[i].key);
    }
    printf("\n");

    // 折半插入排序测试
    L2.length = n;
    for (i = 1; i <= n; i++) {
        L2.r[i].key = arr[i - 1];
    }
    BInsertSort(&L2);
    printf("折半插入排序结果：");
    for (i = 1; i <= n; i++) {
        printf("%d ", L2.r[i].key);
    }
    printf("\n");

    // 希尔排序测试
    L3.length = n;
    for (i = 1; i <= n; i++) {
        L3.r[i].key = arr[i - 1];
    }
    ShellSort(&L3, dt, t);
    printf("希尔排序结果：");
    for (i = 1; i <= n; i++) {
        printf("%d ", L3.r[i].key);
    }
    printf("\n");

    // 冒泡排序测试
    L4.length = n;
    for (i = 1; i <= n; i++) {
        L4.r[i].key = arr[i - 1];
    }
    BubbleSort(&L4);
    printf("冒泡排序结果：");
    for (i = 1; i <= n; i++) {
        printf("%d ", L4.r[i].key);
    }
    printf("\n");

    return 0;
}
