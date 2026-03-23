#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node* next;
	struct node* proior;
}Node;

//初始化双向链表
Node* initNode() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	head->proior = NULL;
	return head;
}

//双向链表的头插法
void headinsert(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	p->proior = L;
	if (L->next != NULL) {
		(L->next)->proior = p;
	}
	L->next = p;
}

//遍历双向链表
void listNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//获取双向链表的最后一个结点
Node* gettail(Node* L) {
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}

//双向链表的尾插法
void tailinsert(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	Node* tail = gettail(L);
	tail->next = p;
	p->next = NULL;
	p->proior = tail;
}

//指定位置插入
void insertNode(Node* L, int position, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	int i = 0;
	Node* q = L;
	for (i = 0;i < position - 1;i++) {
		q = q->next;
	}
	p->proior = q;
	p->next = q->next;
	q->next->proior = p;
	q->next = p;
}

//指定位置删除
void deleteNode(Node* L, int position) {
	Node* p = L;
	int i = 0;
	for (i = 0;i < position - 1;i++) {
		p = p->next;
	}
	Node* q = p->next;
	q->next->proior = p;
	p->next = q->next;
}

int main() {
	Node* List = initNode();
	headinsert(List, 50);
	headinsert(List, 40);
	headinsert(List, 30);
	headinsert(List, 20);
	headinsert(List, 10);
	headinsert(List, 0);
	headinsert(List, -10);
	listNode(List);
	tailinsert(List, 55);
	tailinsert(List, 60);
	listNode(List);
	insertNode(List, 5, 25);
	listNode(List);
	deleteNode(List, 4);
	listNode(List);
	return 0;
}