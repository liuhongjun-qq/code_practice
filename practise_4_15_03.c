#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 题目：从小到大输出二叉排序树中所有大于等于x的结点

typedef int KeyType;

typedef struct BiTNode
{
    KeyType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 输出二叉排序树中所有大于等于x的结点
void PrintGE(BiTree T, KeyType x)
{
    if (!T)
    {
        return;
    }
    if (T->data >= x)
    {
        PrintGE(T->lchild, x);
    }
    if (T->data >= x)
    {
        printf("%d ", T->data);
    }
    PrintGE(T->rchild, x);
}

int main()
{
    BiTree T = NULL;
    KeyType x = 20;

    printf("大于等于 %d 的结点为：", x);
    PrintGE(T, x);
    printf("\n");

    return 0;
}
