//回文是指正读和反读均相同的字符序列。如“aabaa”是回文“aabbab”不是回文，设计算法判断输入的字符序列是否是回文

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char ElemType;

typedef struct stack {
	ElemType data;
	struct stack* next;
}Stack;

//初始化链栈
Stack* initStack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//判断是否为空栈
int isEmpty(Stack* S) {
	if (S->next == NULL) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}

//压栈
void push(Stack* S, ElemType e) {
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = S->next;
	S->next = p;
}

//出栈
void popStack(Stack* S, ElemType* e) {
	*e = S->next->data;
	S->next = S->next->next;
}

//获取栈顶元素
ElemType gettop(Stack* S) {
	ElemType e;
	e = S->next->data;
	return e;
}

int main() {
	Stack* List1 = initStack();
	Stack* List2 = initStack();
	char str[1001];
	scanf("%s", str);
	int len = strlen(str);
	int i;
	//将输入的字符序列正向压栈
	for (i = 0;i < len;i++) {
		push(List1, str[i]);
	}
	//将输入的字符序列反向压栈
	for (i = len - 1;i >= 0;i--) {
		push(List2, str[i]);
	}
	Stack* p = List1->next;
	Stack* q = List2->next;
	while (p != NULL) {
		if (p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		else {
			break;
		}
	}
	if (p != NULL) {
		printf("false\n");
	}
	else {
		printf("true\n");
	}
	return 0;
}