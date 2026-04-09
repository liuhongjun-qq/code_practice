#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
题目：求任意二叉树中第一条最长的路径长度，并输出此路径上各节点的值
*/
#define MAX_PATH_LEN 100

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int maxLen = 0;
int maxPath[MAX_PATH_LEN];
int curPath[MAX_PATH_LEN];

// 创建二叉树（先序遍历，-1表示空节点）
void CreateBiTree(BiTree *T) {
    int ch;
    printf("请输入节点值（-1表示空节点）：");
    scanf("%d", &ch);
    if (ch == -1) {
        *T = NULL;
        return;
    }
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = ch;
    CreateBiTree(&((*T)->lchild));
    CreateBiTree(&((*T)->rchild));
}

// 递归计算二叉树深度，同时记录最长路径
int FindMaxPath(BiTree T, int depth) {
    if (T == NULL) {
        return 0;
    }
    curPath[depth] = T->data;
    int leftDepth = FindMaxPath(T->lchild, depth + 1);
    int rightDepth = FindMaxPath(T->rchild, depth + 1);
    int curLen = leftDepth + rightDepth;
    if (curLen > maxLen) {
        maxLen = curLen;
        for (int i = 0; i <= depth; i++) {
            maxPath[i] = curPath[i];
        }
    }
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 输出最长路径的长度和节点值
void PrintMaxPath() {
    printf("最长路径长度为：%d\n", maxLen);
    printf("路径上的节点值为：");
    for (int i = 0; i <= maxLen; i++) {
        printf("%d ", maxPath[i]);
    }
    printf("\n");
}

int main() {
    BiTree T;
    printf("请按先序遍历创建二叉树：\n");
    CreateBiTree(&T);

    FindMaxPath(T, 0);
    PrintMaxPath();

    return 0;
}
