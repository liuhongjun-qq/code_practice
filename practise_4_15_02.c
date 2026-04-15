#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 题目：判断一棵二叉树是否为二叉排序树

typedef int KeyType;

typedef struct BiTNode
{
    KeyType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 判断二叉树是否为二叉排序树
int IsBST(BiTree T, KeyType *pre)
{
    if (!T)
    {
        return 1;
    }
    if (!IsBST(T->lchild, pre))
    {
        return 0;
    }
    if (T->data <= *pre)
    {
        return 0;
    }
    *pre = T->data;
    return IsBST(T->rchild, pre);
}

int main()
{
    BiTree T = NULL;
    KeyType min = INT_MIN;

    if (IsBST(T, &min))
    {
        printf("该树是二叉排序树\n");
    }
    else
    {
        printf("该树不是二叉排序树\n");
    }

    return 0;
}
