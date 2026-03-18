#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
/*求A和B两个递增集合的差集，并将结果以同样的方式存储，同时返回该集合元素的个数*/
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
//元素的个数
int count(Node* L)
{
	Node* p = L->next;
	int cnt = 0;
	while (p != NULL) {
		cnt++;
		p = p->next;
	}
	return cnt;
 }

Node* difference(Node* A, Node* B)
{
	Node* p = A->next;
	Node* q = B->next;
	Node* R = initList();
	Node* tailR = R;
	while (p != NULL && q != NULL)
	{
		if (p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		else if (p->data > q->data) {
			q = q->next;
		}
		else {
			tailR = insertTail(tailR, p->data);
			p = p->next;
		}
	}
	return R;
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
	Node* R = difference(A, B);
	printf("差集结果：");
	listNode(R);
	int rcnt = count(R);
	printf("%d", rcnt);
	return 0;
}
