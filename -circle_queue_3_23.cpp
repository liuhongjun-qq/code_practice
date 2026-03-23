#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//队列-对头front出队，对尾入队（rear）（比较排队买东西）
 //对头指针指向的是对头元素，队尾指针指向的是对尾元素的下一个；
#define MAXSIZE 100
typedef int Elemtype;
//队列的顺序结构
typedef struct {
	Elemtype data[MAXSIZE];
	int front;
	int rear;
}Queue;

//初始化
void initQueue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

//判断是否为空
int isEmpty(Queue* q)
{
	if (q->front == q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

//出队
int dequeue(Queue* q, Elemtype* e)
{
	if (isEmpty(q))
	{
		printf("空的");
		return 0;
	}
	*e = q->data[q->front];
	q->front=(q->front+1)%MAXSIZE;
	return 1;
}

//判断是否是满的
int isFull(Queue* q)
{
	if ((q->rear + 1) % MAXSIZE == q->front) {
		return 1;
	}
	return 0;
}

//入队
int equeue(Queue* q, Elemtype e)
{
	if (isFull(q)) {
		printf("队列是满的\n");
		return 0;
	}
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return 1;
}

//获取对头数据
int getHead(Queue* q, Elemtype* e)
{
	if (isEmpty(q)) {
		printf("空的\n");
		return 0;
	}
	*e = q->data[q->front];
	return 1;
}

int main()
{
	Queue q;
	initQueue(&q);
	equeue(&q, 10);
	equeue(&q, 20);
	equeue(&q, 30);
	Elemtype e;
	dequeue(&q, &e);
	printf("%d\n", e);
	dequeue(&q, &e);
	printf("%d\n", e);
	dequeue(&q, &e);
	printf("%d\n", e);
	return 0;
}