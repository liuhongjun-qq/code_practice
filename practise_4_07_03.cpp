#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
 题目：
 设计二叉树的双序遍历算法。双序遍历定义：对于二叉树的每一个节点，
 先访问该节点，再按双序遍历左子树，然后再次访问该节点，
 接下来按双序遍历右子树。
*/

// 二叉链表节点结构
typedef struct BiTNode {
    int data;              
    struct BiTNode* lchild; 
    struct BiTNode* rchild; 
} BiTNode, * BiTree;

// 递归创建二叉树
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

//双序遍历
void doubleOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
   
    printf("%d ", T->data);
    doubleOrder(T->lchild);
    printf("%d ", T->data);
    doubleOrder(T->rchild);
}

int main() {
    BiTree T;

    printf("请创建二叉树：\n");
    createBiTree(&T);

    printf("二叉树的双序遍历结果：");
    doubleOrder(T);
    printf("\n");

    return 0;
}