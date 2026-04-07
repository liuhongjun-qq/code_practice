//输出二叉树中每个叶子结点到根结点的路径
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 100

typedef int TreeType;

typedef struct NodeTree {
    TreeType data;
    struct NodeTree* lchild;
    struct NodeTree* rchild;
}NodeTree, * BiTree;

typedef NodeTree* ElemType;



//前序遍历
void preOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%d ", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//中序遍历
void midOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    midOrder(T->lchild);
    printf("%d ", T->data);
    midOrder(T->rchild);
}

//后序遍历
void behindOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    behindOrder(T->lchild);
    behindOrder(T->rchild);
    printf("%d ", T->data);
}

//创建二叉树
int str[1000];
int idx;

void inputSeq() {
    int i = 0;
    printf("输入先序序列（-1表示空）：");
    while (scanf("%d", &str[i]) == 1) {
        i++;
        if (getchar() == '\n') {
            break;
        }
    }
    idx = 0;
}
void creatTree(BiTree* T) {
    TreeType ch;
    ch = str[idx++];
    if (ch == -1) {
        *T = NULL;
    }
    else {
        *T = (BiTree)malloc(sizeof(NodeTree));
        (*T)->data = ch;
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }
}

int path[1000];
int pathLength = 0;

// 打印路径
void printPath(int path[], int len) {
    printf("叶子节点%d：", path[len - 1]);
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

// 遍历找叶子结点并输出路径
void printRoot(BiTree T) {
    if (T == NULL) {
        return;
    }
    path[pathLength++] = T->data;
    if (T->lchild == NULL && T->rchild == NULL) {
        printPath(path, pathLength);
    }
    printRoot(T->lchild);
    printRoot(T->rchild);
    pathLength--;
}

int main() {
    BiTree T;
    inputSeq();
    creatTree(&T);
    printRoot(T);

    return 0;
}