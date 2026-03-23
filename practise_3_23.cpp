#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define MAXSIZE 100

typedef int Elemtype;
//栈的顺序结构实现
typedef struct {
	Elemtype data[MAXSIZE];
	int top;
}Stack;

//初始化
void initStack(Stack* s)
{
	s->top = -1;
}

//判断是否为空
int isEmpty(Stack* s)
{
	if (s->top == -1) {
		printf("栈为空\n");
		return 1;
	}
	else {
		return 0;
	}
}
//判断栈是否是满的
int isFull(Stack* s)
{
	if (s->top == MAXSIZE - 1)
	{
		printf("栈是满的\n");
		return 1;
	}
	else {
		return 0;
	}
}

//进栈
int push(Stack* s,Elemtype e)
{
	if (isFull(s)) {
		printf("栈为满，无法入栈\n");
		return 0;
	}
	else {
		s->top++;
		s->data[s->top] = e;
		return 1;
	}
}

//出栈
int pop(Stack* s,Elemtype*e)
{
	if (isEmpty(s)) {
		printf("栈为空，无法出栈");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

//获取栈顶元素
int gettop(Stack* s, Elemtype* e)
{
	if (isEmpty(s)) {
		printf("栈是空的\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}
int main()
{
	Stack s;
	initStack(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	Elemtype e;
	pop(&s, &e);
	printf("%d\n", e);
	gettop(&s, &e);
	printf("%d\n", e);
	return 0;
}