#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
	1. 设计Ackermann函数的递归算法
	2. 设计Ackermann函数的非递归算法
*/

#define MAX_STACK_SIZE 100
typedef int Elemtype;

// 栈节点结构
typedef struct {
	int m;
	int n;
}StackNode;

// 栈结构
typedef struct {
	StackNode data[MAX_STACK_SIZE];
	int top;
}Stack;

// 初始化栈
void InitStack(Stack* s) {
	s->top = -1;
}

// 判断栈空
int IsEmpty(Stack* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}

// 判断栈满
int IsFull(Stack* s) {
	if ((s->top + 1) % MAX_STACK_SIZE == 0)
		return 1;
	else
		return 0;
}

// 入栈
int Push(Stack* s, int m, int n) {
	if (IsFull(s)) {
		printf("栈满\n");
		return 0;
	}
	s->top++;
	s->data[s->top].m = m;
	s->data[s->top].n = n;
	return 1;
}

// 出栈
int Pop(Stack* s, int* m, int* n) {
	if (IsEmpty(s)) {
		printf("栈空\n");
		return 0;
	}
	*m = s->data[s->top].m;
	*n = s->data[s->top].n;
	s->top--;
	return 1;
}

// 递归实现Ackermann
int Ack(int m, int n) {
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return Ack(m - 1, 1);
	else
		return Ack(m - 1, Ack(m, n - 1));
}

// 非递归实现Ackermann
int AckNonRecursive(int m, int n) {
	Stack s;
	InitStack(&s);
	Push(&s, m, n);

	int result = 0;
	int curr_m, curr_n;

	while (!IsEmpty(&s)) {
		Pop(&s, &curr_m, &curr_n);

		if (curr_m == 0) {
			result = curr_n + 1;
		}
		else if (curr_n == 0) {
			Push(&s, curr_m - 1, 1);
		}
		else {
			Push(&s, curr_m - 1, -1);
			Push(&s, curr_m, curr_n - 1);
		}

		if (!IsEmpty(&s) && s.data[s.top].n == -1) {
			s.data[s.top].n = result;
		}
	}
	return result;
}

int main() {
	// 递归
	printf("递归Ack(2,1) = %d\n", Ack(2, 1));

	// 非递归
	printf("非递归Ack(2,1) = %d\n", AckNonRecursive(2, 1));
	printf("非递归Ack(1,2) = %d\n", AckNonRecursive(1, 2));

	return 0;
}