#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
typedef int Elemtype;

//栈的链式结构-直接用第一个节点作为栈顶
typedef struct stack
{
	Elemtype data;
	struct stack* next;
}Stack;
//初始化
Stack* initStack()
{
	Stack* s = (stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//判断栈是否为空
int isEmpty(Stack* s)
{
	if (s->next == NULL) {
		printf("栈为空\n");
		return 1;
	}
	else {
		return 0;
	}
}

//进栈
void push(Stack* s,Elemtype e)
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

//出栈
int pop(Stack* s, Elemtype* e)
{
	if (isEmpty(s)) {
		printf("栈为空\n");
		return 0;
	}
	Stack* p = s->next;
	*e = p->data;
	s->next = p->next;
	free(p);
	return 1;
}

//获取栈顶元素
int getTop(Stack* s, Elemtype *e)
{
	if (isEmpty(s)) {
		printf("空的\n");
		return 0;
	}
	else {
		*e = s->next->data;
		return 1;
	}
}

int main()
{
	Stack* s = initStack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	Elemtype e;
	pop(s, &e);
	printf("%d\n", e);
	getTop(s, &e);
	printf("%d\n", e);
	return 0;
}