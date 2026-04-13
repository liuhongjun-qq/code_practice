#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 题目：二叉排序树的创建、查找、插入与删除实现

// 二叉排序树节点定义
typedef int KeyType;
typedef struct BSTNode {
    KeyType key;
    struct BSTNode* lchild, * rchild;
} BSTNode, * BSTree;

//查找
BSTree SearchBST(BSTree T, KeyType key) {
    if (!T || T->key == key) {
        return T;
    }
    if (key < T->key) {
        return SearchBST(T->lchild, key);
    }
    else {
        return SearchBST(T->rchild, key);
    }
}


  //二叉排序树的插入
 
int InsertBST(BSTree* T, KeyType key) {
    if (!*T) {
        *T = (BSTree)malloc(sizeof(BSTNode));
        (*T)->key = key;
        (*T)->lchild = (*T)->rchild = NULL;
        return 1;
    }
    if (key == (*T)->key) {
        return 0;
    }
    if (key < (*T)->key) {
        return InsertBST(&(*T)->lchild, key);
    }
    else {
        return InsertBST(&(*T)->rchild, key);
    }
}

//二叉树的创建
void CreateBST(BSTree* T, KeyType keys[], int n) {
    *T = NULL;
    int i;
    for (i = 0; i < n; i++) {
        InsertBST(T, keys[i]);
    }
}

//找到二叉排序树中最小节点
BSTree FindMin(BSTree T) {
    while (T && T->lchild) {
        T = T->lchild;
    }
    return T;
}

//二叉树删除
int DeleteBST(BSTree* T, KeyType key) {
    if (!*T) {
        return 0;
    }
    if (key < (*T)->key) {
        return DeleteBST(&(*T)->lchild, key);
    }
    else if (key > (*T)->key) {
        return DeleteBST(&(*T)->rchild, key);
    }
    else {
        BSTree temp = *T;
        if (!(*T)->lchild) {
            *T = (*T)->rchild;
            free(temp);
        }
        else if (!(*T)->rchild) {
            *T = (*T)->lchild;
            free(temp);
        }
        else {
            temp = FindMin((*T)->rchild);
            (*T)->key = temp->key;
            DeleteBST(&(*T)->rchild, temp->key);
        }
        return 1;
    }
}

//中序遍历
void InOrderTraverse(BSTree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        printf("%d ", T->key);
        InOrderTraverse(T->rchild);
    }
}


int main() {
    KeyType keys[] = { 45, 24, 53, 12, 37, 93 };
    int n = sizeof(keys) / sizeof(KeyType);
    BSTree T;

    CreateBST(&T, keys, n);
    printf("中序遍历二叉排序树：");
    InOrderTraverse(T);
    printf("\n");

    KeyType search_key = 37;
    BSTree find_node = SearchBST(T, search_key);
    if (find_node) {
        printf("找到关键字 %d\n", search_key);
    }
    else {
        printf("未找到关键字 %d\n", search_key);
    }

    KeyType insert_key = 60;
    if (InsertBST(&T, insert_key)) {
        printf("插入关键字 %d 成功，中序遍历：", insert_key);
        InOrderTraverse(T);
        printf("\n");
    }
    else {
        printf("插入关键字 %d 失败\n", insert_key);
    }

    KeyType delete_key = 24;
    if (DeleteBST(&T, delete_key)) {
        printf("删除关键字 %d 成功，中序遍历：", delete_key);
        InOrderTraverse(T);
        printf("\n");
    }
    else {
        printf("删除关键字 %d 失败\n", delete_key);
    }

    return 0;
}