#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
/*反转链表，用原来的存储空间*/
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
//反转链表
Node* reverseList(Node* L)
{
	Node* first = NULL;
	Node* second = L->next;
	Node* third;
	while (second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	Node* hd = initList();
	hd->next = first;
	return hd;
}
int main()
{
	Node* A = initList();
	Node* tailA = get_tail(A);
	tailA = insertTail(tailA, 1);
	tailA = insertTail(tailA, 1);
	tailA = insertTail(tailA, 5);
	tailA = insertTail(tailA, 7);
	printf("原来的链表：");
	listNode(A);
	printf("反转的链表：");
	A = reverseList(A);
	listNode(A);
	return 0;
}
