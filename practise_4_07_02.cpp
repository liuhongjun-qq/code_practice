#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
 题目：
 以二叉链表作为二叉树的存储结构，设计算法交换二叉树每个节点的左孩子和右孩子。
*/

// 二叉链表节点结构
typedef struct BiTNode {
    int data;               
    struct BiTNode* lchild; 
    struct BiTNode* rchild; 
} BiTNode, * BiTree;

// 递归创建二叉树（输入0表示空节点）
void createBiTree(BiTree* T) {
    int ch;
    scanf("%d", &ch);
    if (ch == 0) {
        *T = NULL;
    }
    else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T == NULL) {
            exit(1);
        }
        (*T)->data = ch;
        createBiTree(&((*T)->lchild));
        createBiTree(&((*T)->rchild));
    }
}

// 交换每个节点的左右孩子
void swapLeftRight(BiTree T) {
    if (T == NULL) {
        return;
    }
    
    BiTNode* temp;
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    swapLeftRight(T->lchild);
    swapLeftRight(T->rchild);
}

//前序遍历二叉树
void preOrder(BiTree T) {
    if (T != NULL) {
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}


int main() {
    BiTree T;

    printf("请创建二叉树\n");
    createBiTree(&T);

    printf("交换前的前序遍历结果：");
    preOrder(T);
    printf("\n");

    swapLeftRight(T); 

    printf("交换后的前序遍历结果：");
    preOrder(T);
    printf("\n");

    return 0;
}