#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 题目：判断两棵二叉树是否完全相同
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int IsSameTree(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) {
        return 1;
    }
    if (T1 == NULL || T2 == NULL) {
        return 0;
    }
    if (T1->data != T2->data) {
        return 0;
    }
    int left = IsSameTree(T1->lchild, T2->lchild);
    int right = IsSameTree(T1->rchild, T2->rchild);
    if (left && right) {
        return 1;
    } else {
        return 0;
    }
}

BiTree CreateBiTree() {
    int ch;
    scanf("%d", &ch);
    if (ch == -1) {
        return NULL;
    }
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    T->data = ch;
    T->lchild = CreateBiTree();
    T->rchild = CreateBiTree();
    return T;
}

int main() {
    BiTree T1 = CreateBiTree();
    BiTree T2 = CreateBiTree();
    int res = IsSameTree(T1, T2);
    printf("%d\n", res);
    return 0;
}
