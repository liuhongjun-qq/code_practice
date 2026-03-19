#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node* next;
}Node;


//链表的初始化
Node* initNode() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//单链表的头插法
int headinsert(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 1;
}

//单链表的遍历
void listNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//寻找单链表的尾部
Node* gettail(Node* L) {
	Node* p = L->next;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}

//单链表的尾插法
void tailinsert(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	gettail(L)->next = p;
	p->next = NULL;
}

//在指定位置插入数据
void insertNode(Node* L, int position, ElemType e) {
	Node* p = L;
	int i = 0;
	for (i = 0;i < position - 1;i++) {
		p = p->next;
	}
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
}

//在指定位置删除数据
void deleteNode(Node* L, int position, ElemType* e) {
	Node* p = L;
	int i = 0;
	for (i = 0;i < position - 1;i++) {
		p = p->next;
	}
	*e = (p->next)->data;
	p->next = (p->next)->next;

}

//获取链表长度
int getlength(Node* L) {
	Node* p = L;
	int length = 0;
	while (p->next != NULL) {
		length++;
		p = p->next;
	}
	return length;
}

//释放链表
void freeNode(Node* L) {
	Node* p = L->next;
	Node* q;
	while (p->next != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}


//第4题找出递增排列的链表A和B的差集
Node* differNode(Node* A, Node* B) {
	A = A->next;
	B = B->next;
	Node* C = initNode();
	Node* tail = C;
	while (A != NULL && B != NULL) {
		if (A->data < B->data) {
			tail->next = A;
			tail = tail->next;
			A = A->next;
		}
		if (A->data > B->data) {
			B = B->next;
		}
		if (A->data = B->data) {
			A = A->next;
			B = B->next;
		}
	}
	while (A != NULL) {
		tail->next = A;
		tail = tail->next;
		A = A->next;
	}
	return C;
}

//第6题通过一趟遍历确定最大节点
Node* MaxNode(Node* L) {
	Node* p = L;
	Node* q = L;
	if (L == NULL) {
		return NULL;
	}
	while (p->next != NULL) {
		p = p->next;
		if (p->data > q->data) {
			q = p;
		}
	}
	return q;
}

//第7题倒置链表
Node* invertNode(Node* L) {
	Node* num1 = NULL;
	Node* num2 = L->next;
	Node* num3;
	while (num2 != NULL) {
		num3 = num2->next;
		num2->next = num1;
		num1 = num2;
		num2 = num3;
	}
	Node* invert = initNode();
	invert->next = num1;
	return invert;
}



int main(int argc, char const* argv[]) {
	Node* List = initNode();
	headinsert(List, 10);
	headinsert(List, 20);
	headinsert(List, 30);
	headinsert(List, 40);
	headinsert(List, 50);
	tailinsert(List, 0);
	listNode(List);
	insertNode(List, 3, 35);
	listNode(List);
	ElemType deletenum;
	deleteNode(List, 2, &deletenum);
	printf("被删除的数据是：%d\n", deletenum);
	listNode(List);
	printf("List的最后一个数据是：%d\n", gettail(List)->data);
	printf("List的长度是%d\n", getlength(List));
	Node* NewNode = invertNode(List);
	listNode(NewNode);
	Node* B = initNode();
	headinsert(B, 50);
	headinsert(B, 45);
	headinsert(B, 40);
	headinsert(B, 35);
	headinsert(B, 30);
	headinsert(B, 25);
	headinsert(B, 20);
	headinsert(B, 15);
	headinsert(B, 10);
	listNode(B);
	Node* C = initNode();
	C = differNode(B, NewNode);
	listNode(C);
	return 0;
}
