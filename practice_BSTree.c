//二叉排序树
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


int str[1000];
int idx;

void inputSeq() {
    int i = 0;
    printf("输入二叉排序树先序序列（-1结束输入）：");
    while (scanf("%d", &str[i]) == 1) {
        if (str[i] == -1) break;
        i++;
        if (getchar() == '\n') {
            break;
        }
    }
    idx = 0;
}

//插入节点
void InsertBST(BiTree* T, TreeType key) {
    if (*T == NULL) {
        *T = (BiTree)malloc(sizeof(NodeTree));
        (*T)->data = key;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    //小于根节点插入左子树
    else if (key < (*T)->data) {
        InsertBST(&(*T)->lchild, key);
    }
    //大于根节点插入右子树
    else if (key > (*T)->data) {
        InsertBST(&(*T)->rchild, key);
    }
}

//创建二叉排序树
void CreateBST(BiTree* T) {
    *T = NULL;
    TreeType key;
    while (str[idx] != -1) {
        key = str[idx++];
        InsertBST(T, key);
    }
}

//查找
BiTree SearchBST(BiTree T, TreeType key) {
    if (T == NULL || T->data == key) {
        return T; 
    }
    else if (key < T->data) {
        return SearchBST(T->lchild, key);
    }
    else {
        return SearchBST(T->rchild, key);
    }
}

//删除节点
void Delete(BiTree* p) {
    BiTree q, s;
    //右子树空，重接左子树
    if ((*p)->rchild == NULL) {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    //左子树空，重接右子树
    else if ((*p)->lchild == NULL) {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    //左右子树都不为空
    else {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild != NULL) {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if (q != *p) {
            q->rchild = s->lchild;
        }
        else {
            q->lchild = s->lchild;
        }
        free(s);
    }
}

int DeleteBST(BiTree* T, TreeType key) {
    if (*T == NULL) {
        return 0; 
    }
    else {
        if (key == (*T)->data) {
            Delete(T);
            return 1;
        }
        else if (key < (*T)->data) {
            return DeleteBST(&(*T)->lchild, key);
        }
        else {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
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

int main() {
    BiTree T;
    TreeType key;
    int choose;
    inputSeq();
    CreateBST(&T);
    printf("中序遍历：");
    midOrder(T);
    printf("\n");

    printf("输入要查找的值：");
    scanf("%d", &key);
    if (SearchBST(T, key) != NULL) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    printf("请输入要插入的值：");
    scanf("%d", &key);
    InsertBST(&T, key);
    printf("插入后中序遍历：");
    midOrder(T);
    printf("\n");

    printf("请输入要删除的值：");
    scanf("%d", &key);
    if (DeleteBST(&T, key)) {
        printf("删除成功！\n");
    }
    else {
        printf("ERROR！\n");
    }
    printf("删除后中序遍历：");
    midOrder(T);
    printf("\n");
    return 0;
}