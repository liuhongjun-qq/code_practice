#define _CRT_SECURE_NO_WARNINGS 1
/*求A和B两个递增集合的交集，并将结果放在A中*/
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

void intersection(Node* A, Node* B)
{
	Node* p = A;
	Node* q = A->next;
	Node* s = B->next;
	while (q != NULL && s != NULL)
	{
		if (q->data < s->data) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else if (q->data == s->data) {
			p = q;
			p->next = q->next;
			q = q->next;
			s = s->next;
			continue;
		}
		else {
			s = s->next;
		}
	}
	while (q!= NULL)
	{
		p->next = q->next;
		free(q);
		q = p->next;
	}
}

int main()
{
	Node* A = initList();
	Node* B = initList();
	Node* tailA = get_tail(A);
	tailA = insertTail(tailA, 1);
	tailA = insertTail(tailA, 2);
	tailA = insertTail(tailA, 3);
	tailA = insertTail(tailA, 4);
	Node* tailB = get_tail(B);
	tailB = insertTail(tailB, 2);
	tailB = insertTail(tailB, 3);
	tailB = insertTail(tailB, 5);
	tailB = insertTail(tailB, 7);
	printf("原集合 A：");
	listNode(A);
	printf("原集合 B：");
	listNode(B);
	intersection(A, B);
	printf("交集结果 A：");
	listNode(A);
}
