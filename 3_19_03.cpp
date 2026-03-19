#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
/*交换双向循环链表中p节点与其前驱节点的顺序*/
#include<stdio.h>
#include<stdlib.h>

typedef int elemType;

typedef struct node {
	elemType data;
	struct node* prior;  
	struct node* next;   
}Node;

// 初始化双向循环链表
Node* initDLinkList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->prior = head;  
	head->next = head;   
	return head;
}

// 尾插法
Node* getTail(Node* L)
{
	Node* p = L;
	while (p->next != L) 
	{
		p = p->next;
	}
	return p;
}
Node* insertTail(Node* tail, elemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	
	p->prior = tail;
	p->next = tail->next;  
	tail->next->prior = p;
	tail->next = p;
	return p;
}

// 遍历双向循环链表
void listDNode(Node* L)
{
	Node* p = L->next;
	while (p != L)  
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 查找指定数据的节点
Node* findNode(Node* L, elemType e)
{
	Node* p = L->next;
	while (p != L)
	{
		if (p->data == e)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 交换p节点与其前驱节点的顺序
void change(Node* p)
{
	if (p == NULL || p->prior == p)
	{
		return;
	}
	Node* pre = p->prior;    
	Node* pre_pre = pre->prior;  
	Node* p_next = p->next;  
	pre_pre->next = p;
	p->prior = pre_pre;
	p->next = pre;
	pre->prior = p;
	pre->next = p_next;
	p_next->prior = pre;
}

int main()
{
	Node* A = initDLinkList();
	Node* tailA = getTail(A);
	tailA = insertTail(tailA, 1);
	tailA = insertTail(tailA, 2);
	tailA = insertTail(tailA, 3);
	tailA = insertTail(tailA, 4);
	tailA = insertTail(tailA, 5);

	printf("原双向循环链表：");
	listDNode(A);
	Node* p = findNode(A, 3);
	if (p != NULL)
	{
		change(p);
		printf("交换后链表：");
		listDNode(A);
	}
	else
	{
		printf("未找到指定节点！\n");
	}

	return 0;
}