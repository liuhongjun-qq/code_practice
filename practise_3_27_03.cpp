#define _CRT_SECURE_NO_WARNINGS 1
/*
	递归实现：
	1. 求链表最大值
	2. 求链表节点个数
	3. 求链表所有元素平均值
*/
#include<stdio.h>
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

// 递归求最大值
int GetMax(Node* p) {
	if (p->next == NULL) {
		return p->data;
	}
	int max = GetMax(p->next);
	if (p->data > max) {
		return p->data;
	}
	else {
		return max;
	}
}

// 递归求节点个数
int GetCount(Node* p) {
	if (p == NULL) {
		return 0;
	}
	return 1 + GetCount(p->next);
}

// 递归求总和
int GetSum(Node* p) {
	if (p == NULL) {
		return 0;
	}
	return p->data + GetSum(p->next);
}

// 求平均值
double GetAvg(Node* L) {
	int n = GetCount(L->next);
	int sum = GetSum(L->next);
	double avg = (double)sum / n;
	return avg;
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

	printf("链表元素：");
	listNode(A);

	printf("最大值：%d\n", GetMax(A->next));
	printf("节点个数：%d\n", GetCount(A->next));
	printf("平均值：%.2f\n", GetAvg(A));

	return 0;
}