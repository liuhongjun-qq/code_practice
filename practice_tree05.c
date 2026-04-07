//交换二叉树每个结点的左右孩子
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

typedef struct Queue {
	ElemType* data;
	int front;
	int rear;
}Queue;

Queue* initQueue() {
	Queue* p = (Queue*)malloc(sizeof(Queue));
	p->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	p->front = 0;
	p->rear = 0; 
	return p;
}

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

//交换每个结点的左孩子和右孩子
void swapLeftRight(BiTree T) {
	if (T == NULL) {
		return;
	}
	NodeTree* temp = T->lchild;
	T->lchild = T->rchild; 
	T->rchild = temp;
	
	//递归交换左右孩子
	swapLeftRight(T->lchild);
	swapLeftRight(T->rchild);
}

int main() {
	BiTree T;
	inputSeq();
	creatTree(&T);
	swapLeftRight(T);
	printf("交换后（前序遍历）：");
	preOrder(T);
	printf("\n");
	return 0;
}