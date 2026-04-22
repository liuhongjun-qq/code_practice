#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 题目：求二叉树中所有节点值的和
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SumNodes(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int left = SumNodes(T->lchild);
    int right = SumNodes(T->rchild);
    return T->data + left + right;
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
    int sum = SumNodes(T);
    printf("%d\n", sum);
    return 0;
}
