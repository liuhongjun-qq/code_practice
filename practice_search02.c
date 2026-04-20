//折半查找
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXSIZE 100

//顺序表结构
typedef int SeqList[MAXSIZE];
int length;

//初始化顺序表
void InitList(SeqList L) {
    length = 0;
}

//创建顺序表
void CreateList(SeqList L, int n) {
    int i;
    printf("请输入%d个有序元素：", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }
    length = n;
}

//输出顺序表
void PrintList(SeqList L) {
    int i;
    printf("顺序表元素：");
    for (i = 0; i < length; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
}

//折半查找
int BinarySearch(SeqList L, int key) {
    int low = 0;
    int high = length - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (L[mid] == key) {
            return mid;
        }
        else if (L[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    SeqList L;
    int n, key, pos;
    InitList(L);
    printf("顺序表长度：");
    scanf("%d", &n);
    CreateList(L, n);
    PrintList(L);
    printf("要查找的元素：");
    scanf("%d", &key);

    pos = BinarySearch(L, key);
    if (pos != -1) {
        printf("元素下标为：%d\n", pos);
    }
    else {
        printf("元素不存在！\n");
    }
    return 0;
}