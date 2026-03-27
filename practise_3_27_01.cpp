#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
// 两端可插入删除的循环队列：队头/队尾均可插入、队头/队尾均可删除
#define MAXSIZE 100
typedef int Elemtype;

// 循环队列的类型定义
typedef struct {
    Elemtype data[MAXSIZE];
    int front;  // 队头指针，指向队头元素
    int rear;   // 队尾指针，指向队尾元素的下一个位置
} Queue;

// 初始化队列
void initQueue(Queue* q)
{
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
int isEmpty(Queue* q)
{
    if (q->front == q->rear) {
        return 1;
    }
    else {
        return 0;
    }
}

// 判断队列是否为满
int isFull(Queue* q)
{
    if ((q->rear + 1) % MAXSIZE == q->front) {
        return 1;
    }
    return 0;
}

// 队尾入队
int enQueueRear(Queue* q, Elemtype e)
{
    if (isFull(q)) {
        printf("队列是满的\n");
        return 0;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

// 队头出队
int deQueueFront(Queue* q, Elemtype* e)
{
    if (isEmpty(q))
    {
        printf("队列空的\n");
        return 0;
    }
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

// 队头插入元素
int enQueueFront(Queue* q, Elemtype e)
{
    if (isFull(q)) {
        printf("队列是满的\n");
        return 0;
    }
    
    q->front = (q->front - 1 + MAXSIZE) % MAXSIZE;
    q->data[q->front] = e;
    return 1;
}

// 队尾删除元素
int deQueueRear(Queue* q, Elemtype* e)
{
    if (isEmpty(q))
    {
        printf("队列空的\n");
        return 0;
    }
    q->rear = (q->rear - 1 + MAXSIZE) % MAXSIZE;
    *e = q->data[q->rear];
    return 1;
}

// 遍历打印队列
void printQueue(Queue* q)
{
    if (isEmpty(q)) {
        printf("队列为空\n");
        return;
    }
    int i = q->front;
    printf("队列元素：");
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initQueue(&q);

    // 队尾入队
    enQueueRear(&q, 10);
    enQueueRear(&q, 20);
    enQueueRear(&q, 30);
    printf("队尾入队10、20、30后：");
    printQueue(&q);

    // 队头插入
    enQueueFront(&q, 5);
    printf("队头插入5后：");
    printQueue(&q);

    // 队尾删除
    Elemtype e;
    deQueueRear(&q, &e);
    printf("队尾删除的元素：%d\n", e);
    printf("队尾删除后：");
    printQueue(&q);

    // 队头出队
    deQueueFront(&q, &e);
    printf("队头删除的元素：%d\n", e);
    printf("队头删除后：");
    printQueue(&q);

    return 0;
}