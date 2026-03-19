#define _CRT_SECURE_NO_WARNINGS 1
/*删除递增链表中值大于mink且小于maxk的所有元素*/
#include<stdio.h>
#include<stdlib.h>

typedef int elemType;

typedef struct node {
	elemType data;
	struct node* next;
}Node;

//初始化链表
Node* initList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//头插法
int insertHead(Node* L, elemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 1;
}

//遍历
void listNode(Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//尾插法
Node* get_tail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}
Node* insertTail(Node* tail, elemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}

void deletek(Node* L, int mink, int maxk)
{
	Node* p = L;
	Node* q = L->next;
	while (q != NULL && q->data < maxk) 
	{
		if (q->data <= mink) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}

int main()
{
	Node* A = initList();
	Node* tailA = get_tail(A);
	tailA = insertTail(tailA, 1);
	tailA = insertTail(tailA, 3);
	tailA = insertTail(tailA, 5);
	tailA = insertTail(tailA, 7);
	tailA = insertTail(tailA, 9);
	tailA = insertTail(tailA, 11);
	tailA = insertTail(tailA, 13);
	printf("原来的链表：");
	listNode(A);
	int mink;
	int maxk;
	printf("请输入mink和maxk:");
	scanf("%d %d", &mink, &maxk);
	deletek(A, mink, maxk);
	printf("删除后的链表：");
	listNode(A);
	return 0;
}
