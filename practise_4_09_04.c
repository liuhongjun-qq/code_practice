#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
题目：输出二叉树中从每个叶子节点到根节点的路径
*/
#define MAX_PATH_LEN 100

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

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

// 递归遍历二叉树，输出每个叶子节点到根节点的路径
void PrintLeafToRootPath(BiTree T, int path[], int pathLen) {
    if (T == NULL) {
        return;
    }
    path[pathLen] = T->data;
    pathLen++;
    if (T->lchild == NULL && T->rchild == NULL) {
        printf("叶子节点%d到根节点的路径：", T->data);
        for (int i = pathLen - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        PrintLeafToRootPath(T->lchild, path, pathLen);
        PrintLeafToRootPath(T->rchild, path, pathLen);
    }
}

int main() {
    BiTree T;
    int path[MAX_PATH_LEN];
    printf("请按先序遍历创建二叉树：\n");
    CreateBiTree(&T);

    printf("\n所有叶子节点到根节点的路径如下：\n");
    PrintLeafToRootPath(T, path, 0);

    return 0;
}
