#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 题目：平衡二叉树（AVL树）的创建、插入、旋转与查找实现

// AVL树节点结构体定义
typedef int KeyType;
typedef struct AVLNode {
    KeyType key;
    int bf; // 平衡因子
    struct AVLNode* lchild, * rchild;
} AVLNode, * AVLTree;

//求二叉树的深度
int GetDepth(AVLTree T) {
    if (!T) {
        return 0;
    }
    int ldepth = GetDepth(T->lchild);
    int rdepth = GetDepth(T->rchild);
    return (ldepth > rdepth) ? (ldepth + 1) : (rdepth + 1);
}

// LL型旋转（右单旋）
void LLRotate(AVLTree* T) {
    AVLTree temp = (*T)->lchild;
    (*T)->lchild = temp->rchild;
    temp->rchild = *T;
    (*T)->bf = 0;
    temp->bf = 0;
    *T = temp;
}

//RR型旋转（左单旋）
void RRRotate(AVLTree* T) {
    AVLTree temp = (*T)->rchild;
    (*T)->rchild = temp->lchild;
    temp->lchild = *T;
    (*T)->bf = 0;
    temp->bf = 0;
    *T = temp;
}

// LR型旋转（先左后右双旋）
void LRRotate(AVLTree* T) {
    AVLTree temp1 = (*T)->lchild;
    AVLTree temp2 = temp1->rchild;
    temp1->rchild = temp2->lchild;
    temp2->lchild = temp1;
    (*T)->lchild = temp2->rchild;
    temp2->rchild = *T;
    switch (temp2->bf) {
    case 1:
        (*T)->bf = -1;
        temp1->bf = 0;
        break;
    case 0:
        (*T)->bf = 0;
        temp1->bf = 0;
        break;
    case -1:
        (*T)->bf = 0;
        temp1->bf = 1;
        break;
    }
    temp2->bf = 0;
    *T = temp2;
}

//RL型旋转（先右后左双旋）
void RLRotate(AVLTree* T) {
    AVLTree temp1 = (*T)->rchild;
    AVLTree temp2 = temp1->lchild;
    temp1->lchild = temp2->rchild;
    temp2->rchild = temp1;
    (*T)->rchild = temp2->lchild;
    temp2->lchild = *T;
    switch (temp2->bf) {
    case 1:
        (*T)->bf = 0;
        temp1->bf = -1;
        break;
    case 0:
        (*T)->bf = 0;
        temp1->bf = 0;
        break;
    case -1:
        (*T)->bf = 1;
        temp1->bf = 0;
        break;
    }
    temp2->bf = 0;
    *T = temp2;
}

//插入
int InsertAVL(AVLTree* T, KeyType key, int* taller) {
    if (!*T) {
        *T = (AVLTree)malloc(sizeof(AVLNode));
        (*T)->key = key;
        (*T)->bf = 0;
        (*T)->lchild = (*T)->rchild = NULL;
        *taller = 1;
        return 1;
    }
    if (key == (*T)->key) {
        *taller = 0;
        return 0;
    }
    if (key < (*T)->key) {
        if (!InsertAVL(&(*T)->lchild, key, taller)) {
            return 0;
        }
        if (*taller) {
            switch ((*T)->bf) {
            case 1:
                if ((*T)->lchild->bf == 1) {
                    LLRotate(T);
                }
                else {
                    LRRotate(T);
                }
                *taller = 0;
                break;
            case 0:
                (*T)->bf = 1;
                *taller = 1;
                break;
            case -1:
                (*T)->bf = 0;
                *taller = 0;
                break;
            }
        }
    }
    else {
        if (!InsertAVL(&(*T)->rchild, key, taller)) {
            return 0;
        }
        if (*taller) {
            switch ((*T)->bf) {
            case 1:
                (*T)->bf = 0;
                *taller = 0;
                break;
            case 0:
                (*T)->bf = -1;
                *taller = 1;
                break;
            case -1:
                if ((*T)->rchild->bf == -1) {
                    RRRotate(T);
                }
                else {
                    RLRotate(T);
                }
                *taller = 0;
                break;
            }
        }
    }
    return 1;
}

//创建
void CreateAVL(AVLTree* T, KeyType keys[], int n) {
    *T = NULL;
    int i;
    int taller;
    for (i = 0; i < n; i++) {
        InsertAVL(T, keys[i], &taller);
    }
}

//查找
AVLTree SearchAVL(AVLTree T, KeyType key) {
    if (!T || T->key == key) {
        return T;
    }
    if (key < T->key) {
        return SearchAVL(T->lchild, key);
    }
    else {
        return SearchAVL(T->rchild, key);
    }
}

//中序遍历
void InOrderTraverse(AVLTree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        printf("key: %d, bf: %d\n", T->key, T->bf);
        InOrderTraverse(T->rchild);
    }
}


int main() {
    KeyType keys[] = { 13, 24, 37, 90, 53 };
    int n = sizeof(keys) / sizeof(KeyType);
    AVLTree T;

    CreateAVL(&T, keys, n);
    printf("中序遍历AVL树：\n");
    InOrderTraverse(T);
    printf("\n");

    KeyType search_key = 37;
    AVLTree find_node = SearchAVL(T, search_key);
    if (find_node) {
        printf("找到关键字 %d，平衡因子为 %d\n", search_key, find_node->bf);
    }
    else {
        printf("未找到关键字 %d\n", search_key);
    }

    return 0;
}