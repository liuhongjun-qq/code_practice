#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 题目：非递归实现二叉排序树查找，存在则计数+1，不存在则插入

typedef int KeyType;

typedef struct BSTNode
{
    KeyType key;
    int count;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 非递归查找关键字，存在则计数加1，不存在则插入
void SearchInsert(BSTree *T, KeyType key)
{
    BSTNode *p = *T, *f = NULL;
    while (p)
    {
        f = p;
        if (key == p->key)
        {
            p->count++;
            return;
        }
        else if (key < p->key)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    p = (BSTNode *)malloc(sizeof(BSTNode));
    p->key = key;
    p->count = 1;
    p->lchild = p->rchild = NULL;
    if (!f)
    {
        *T = p;
    }
    else if (key < f->key)
    {
        f->lchild = p;
    }
    else
    {
        f->rchild = p;
    }
}

int main()
{
    BSTree T = NULL;
    KeyType keys[] = { 12,23,12,34,23,45 };
    int n = sizeof(keys) / sizeof(KeyType);
    int i;

    for (i = 0; i < n; i++)
    {
        SearchInsert(&T, keys[i]);
    }

    return 0;
}
