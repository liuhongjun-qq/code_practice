#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
 题目：
 计算二叉树最大宽度（二叉树的最大宽度是指二叉树所有层中节点个数的最大值）。
*/

// 二叉链表节点结构
typedef struct BiTNode {
    int data;               
    struct BiTNode* lchild; 
    struct BiTNode* rchild; 
} BiTNode, * BiTree;

typedef struct QueueNode {
    BiTree node;            
    struct QueueNode* next; // 队列下一个节点
} QueueNode, * QueuePtr;


typedef struct {
    QueuePtr front;         
    QueuePtr rear;         
} LinkQueue;

// 初始化队列
void initQueue(LinkQueue* Q) {
    Q->front = (QueuePtr)malloc(sizeof(QueueNode));
    Q->rear = Q->front;
    Q->front->next = NULL;
}

// 入队操作
void enQueue(LinkQueue* Q, BiTree T) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode));
    p->node = T;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

// 出队操作
int deQueue(LinkQueue* Q, BiTree* T) {
    if (Q->front == Q->rear) {
        return 0; 
    }
    QueuePtr p = Q->front->next;
    *T = p->node;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return 1;
}

// 判断队列是否为空
int isQueueEmpty(LinkQueue* Q) {
    int result;
    if (Q->front == Q->rear) {
        result = 1;
    }
    else {
        result = 0;
    }
    return result;
}

// 递归创建二叉树（输入0表示空节点，前序输入）
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

// 计算二叉树最大宽度
int getMaxWidth(BiTree T) {
    if (T == NULL) {
        return 0; 
    }
    LinkQueue Q;
    initQueue(&Q);
    enQueue(&Q, T); 

    int maxWidth = 0; 
    int levelSize;    
    BiTree p;

    while (!isQueueEmpty(&Q)) {
        levelSize = 0;
        QueuePtr temp = Q.front->next;
        while (temp != NULL) {
            levelSize = levelSize + 1;
            temp = temp->next;
        }
      
        if (levelSize > maxWidth) {
            maxWidth = levelSize;
        }
       
        int i;
        for (i = 0; i < levelSize; i = i + 1) {
            deQueue(&Q, &p);
            if (p->lchild != NULL) {
                enQueue(&Q, p->lchild);
            }
            if (p->rchild != NULL) {
                enQueue(&Q, p->rchild);
            }
        }
    }
    return maxWidth;
}


int main() {
    BiTree T;

    printf("请创建二叉树：\n");
    createBiTree(&T);

    int maxWidth = getMaxWidth(T);
    printf("二叉树的最大宽度为：%d\n", maxWidth);

    return 0;
}