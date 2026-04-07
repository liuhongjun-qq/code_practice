//用按层次顺序遍历二叉树的方法统计树中度为1的结点数目
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

//入队
void eQueue(Queue* Q, ElemType e) {
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
}

//出队
void deQueue(Queue* Q, ElemType* e) {
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
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

//判断队列是否为空
int isEmpty(Queue* Q) {
	if (Q->front == Q->rear) {
		return 1;
	}
	return 0;
}

//计算队列中结点个数
int QueueSize(Queue* Q) {
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

//层次遍历统计度为1的结点个数
int countDegreeOne(BiTree T)
{
	if (T == NULL) {
		return 0;
	}
	int count = 0;   
	Queue* Q = initQueue();
	eQueue(Q, T);

	while (!isEmpty(Q))
	{
		int size = QueueSize(Q); 
		while (size--)
		{
			NodeTree* p;
			deQueue(Q, &p);
			if ((p->lchild != NULL && p->rchild == NULL) ||(p->lchild == NULL && p->rchild != NULL))
			{
				count++;
			}
			if (p->lchild != NULL)
				eQueue(Q, p->lchild);
			if (p->rchild != NULL)
				eQueue(Q, p->rchild);
		}
	}
	return count;
}

int main() {
	BiTree T;
	inputSeq();
	creatTree(&T);
	printf("度为1的结点个数：%d\n", countDegreeOne(T));

	return 0;
}