#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
 题目：
 以二叉链表作为二叉树的存储结构，设计以下算法：
 (1) 统计二叉树的叶节点个数。
 (2) 判别两棵树是否相等。
*/

// 二叉链表节点结构
typedef struct BiTNode {
    int data;               
    struct BiTNode* lchild; 
    struct BiTNode* rchild;
} BiTNode, * BiTree;

// 1. 创建二叉树（递归创建）
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

// 统计叶节点个数 
int countLeaves(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    else {
        if (T->lchild == NULL && T->rchild == NULL) {
            return 1;
        }
        else {
            return countLeaves(T->lchild) + countLeaves(T->rchild);
        }
    }
}

//判断两棵树是否完全相等
int isEqual(BiTree T1, BiTree T2) {
    // 两个都为空
    if (T1 == NULL && T2 == NULL) {
        return 1;
    }
    else {
        // 一个空一个非空
        if (T1 == NULL || T2 == NULL) {
            return 0;
        }
        else {
            // 数据相等 + 左右子树都相等
            if (T1->data == T2->data) {
                if (isEqual(T1->lchild, T2->lchild) == 1) {
                    if (isEqual(T1->rchild, T2->rchild) == 1) {
                        return 1;
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
    }
}

// 辅助打印：前序遍历
void preOrder(BiTree T) {
    if (T != NULL) {
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

int main() {
    BiTree T1, T2;

    printf("创建第一棵树\n");
    createBiTree(&T1);

    printf("创建第二棵树（输入0表示空节点） \n");
    createBiTree(&T2);

    // 统计叶节点
    int leafCount = countLeaves(T1);
    printf("第一棵树的叶节点个数：%d\n", leafCount);

    //判断两棵树是否相等
    int equal = isEqual(T1, T2);
    if (equal == 1) {
        printf("两棵树相等\n");
    }
    else {
        printf("两棵树不相等\n");
    }

    return 0;
}