#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 题目：求平衡二叉树（AVL树）的高度

typedef int KeyType;

typedef struct AVLNode
{
    KeyType key;
    int bf;
    struct AVLNode *lchild, *rchild;
} AVLNode, *AVLTree;

// 求平衡二叉树的高度
int GetHeight(AVLTree T)
{
    int lh, rh;
    if (!T)
    {
        return 0;
    }
    lh = GetHeight(T->lchild);
    rh = GetHeight(T->rchild);
    if (lh > rh)
    {
        return lh + 1;
    }
    else
    {
        return rh + 1;
    }
}

int main()
{
    AVLTree T = NULL;
    int h = GetHeight(T);
    printf("AVL树高度为：%d\n", h);
    return 0;
}
