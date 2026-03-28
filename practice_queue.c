//队列初始化、判断是否为空、判断是否满、入队、出队、获取队头和队尾元素、统计元素个数、清空队列
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int front; 
	int rear; 
}Queue;

//初始化
void initQueue(Queue* Q) {
	Q->front = 0;
	Q->rear = 0;
}

//判断队列是否为空
int IsEmpty(Queue* Q) {
	if (Q->front == Q->rear) {
		return 1;  //
	}
	else {
		return 0;  //
	}
}

//判断队列是否满
int IsFull(Queue* Q) {
	if (Q->rear >= MAXSIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

//入队
void eQueue(Queue* Q, ElemType e) {
	Q->data[Q->rear] = e;
	Q->rear++;
}

//出队
ElemType deQueue(Queue* Q) {
	ElemType e = Q->data[Q->front];
	Q->front++;
	return e;
}

//获取队头元素
ElemType GetFront(Queue* Q) {
	return Q->data[Q->front];
}

//获取队尾元素
ElemType GetRear(Queue* Q) {
	return Q->data[Q->rear - 1];
}

//统计队列元素个数
int QueueLength(Queue* Q) {
	return Q->rear - Q->front;
}

//清空队列
void ClearQueue(Queue* Q) {
	Q->front = 0;
	Q->rear = 0;
}

int main() {
	return 0;
}