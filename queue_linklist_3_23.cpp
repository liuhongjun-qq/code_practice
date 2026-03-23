#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
//队列-对头front出队，对尾入队（rear）（比较排队买东西）
 //对头指针指向的是头节点，队尾指针指向的是对尾元素；

typedef int  ElemType;
typedef struct QueueNode
{
    ElemType data;
    struct QueueNode* next;
}QueueNode;

typedef struct
{
    QueueNode* front;
    QueueNode* rear;
}Queue;

//初始化
Queue* initQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

//判断是否为空
int isEmpty(Queue* q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//入队--尾插法
void equeue(Queue* q, ElemType e)
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

//出队
int dequeue(Queue* q, ElemType* e)
{
    QueueNode* node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if (q->rear == node)
    {
        q->rear = q->front;
    }
    free(node);
    return 1;
}

//获取对头元素
ElemType getFront(Queue* q)
{
    if (isEmpty(q))
    {
        printf("空的\n");
        return 0;
    }
    return q->front->next->data;
}

int main()
{
    Queue* q = initQueue();
    equeue(q, 10);
    equeue(q, 20);
    equeue(q, 30);
    equeue(q, 40);
    equeue(q, 50);
    ElemType e;
    dequeue(q, &e);
    printf("出队%d\n", e);
    dequeue(q, &e);
    printf("出队%d\n", e);
    printf("%d\n", getFront(q));
    return 0;
}