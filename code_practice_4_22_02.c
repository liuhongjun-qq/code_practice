#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 题目：翻转二叉树（左右子树交换）
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InvertTree(BiTree T) {
    if (T == NULL) {
        return;
    }
    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    InvertTree(T->lchild);
    InvertTree(T->rchild);
}

void PreOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%d ", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
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
    BiTree T = CreateBiTree();
    InvertTree(T);
    PreOrder(T);
    return 0;
}
