//分块查找
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXSIZE 100
#define BLOCKSIZE 5 

//顺序表结构
typedef int SeqList[MAXSIZE];
int length;

//索引表
typedef struct {
    int max;   
    int start;  
}IndexTable[MAXSIZE];

//初始化顺序表
void InitList(SeqList L) {
    length = 0;
}

//创建顺序表
void CreateList(SeqList L, int n) {
    int i;
    printf("请输入%d个分块有序元素：", n);
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

//分块查找
int BlockSearch(SeqList L, IndexTable idx, int key, int blockNum)
{
    int i, low, high;

    //在索引表折半找所在块
    low = 0;
    high = blockNum - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (idx[mid].max < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    i = low;

    //在块内顺序查找
    low = idx[i].start;
    if (i + 1 < blockNum)
        high = idx[i + 1].start - 1;
    else
        high = length - 1;

    while (low <= high)
    {
        if (L[low] == key)
            return low;
        low++;
    }
    return -1;
}

int main() {
    SeqList L;
    IndexTable idx;
    int n, key, pos;
    int blockNum;

    InitList(L);
    printf("顺序表长度：");
    scanf("%d", &n);
    CreateList(L, n);
    PrintList(L);

    printf("输入分块数量：");
    scanf("%d", &blockNum);

    //建立索引表
    int k = 0;
    for (int i = 0;i < blockNum;i++)
    {
        idx[i].start = k;
        int max = L[k];
        for (int j = k;j < n && j < k + BLOCKSIZE;j++)
        {
            if (L[j] > max) max = L[j];
        }
        idx[i].max = max;
        k += BLOCKSIZE;
    }

    printf("要查找的元素：");
    scanf("%d", &key);
    pos = BlockSearch(L, idx, key, blockNum);
    if (pos != -1) {
        printf("元素下标为：%d\n", pos);
    }
    else {
        printf("元素不存在！\n");
    }
    return 0;
}