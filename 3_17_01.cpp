#define _CRT_SECURE_NO_WARNINGS 1
/*将两个递增的有序链表合并成一个递增的有序链表
不另外占用其他的存储空间，表中不允许有重复数据*/
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

void sort(Node* A, Node* B)
{
	Node* p = A->next;
	Node* q = B->next;
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data) {
			A->next = p;
			A = p;
			p = p->next;
		}
		else if(p->data>q->data){
			A->next = q;
			A = q;
			q = q->next;
		}
		else {
			q = q->next;
		}
	}
	while (p != NULL) {
		A->next = p;
		A = p;
		p = p->next;
	}
	while (q != NULL) {
		A->next = q;
		A = q;
		q = q->next;
	}
}

int main()
{
	Node* A = initList();
	Node* B = initList();
	Node* tailA = get_tail(A);
	tailA = insertTail(tailA, 1);
	tailA = insertTail(tailA, 3);
	tailA = insertTail(tailA, 5);
	tailA = insertTail(tailA, 7);
	Node* tailB = get_tail(B);
	tailB = insertTail(tailB, 3);
	tailB = insertTail(tailB, 4);
	tailB = insertTail(tailB, 6);
	tailB = insertTail(tailB, 8);
	listNode(A);
	listNode(B);
	sort(A, B);
	listNode(A);
}
