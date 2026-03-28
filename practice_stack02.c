//从键盘上输入一个后缀表达式（逆波兰表达式），长度不超过一行，以“$”结束，操作数之间用空格分隔，操作符只能有+-*/四种
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct stack {
    ElemType data;
    struct stack* next;
} Stack;

// 初始化链栈
Stack* initStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

// 判断是否为空栈
int isEmpty(Stack* S) {
    if (S->next == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// 压栈
void push(Stack* S, ElemType e) {
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

// 出栈
void popStack(Stack* S, ElemType* e) {
    *e = S->next->data;
    S->next = S->next->next;
}

// 获取栈顶元素
ElemType gettop(Stack* S) {
    ElemType e;
    e = S->next->data;
    return e;
}

int main() {
    Stack* S = initStack();
    char str[100];
    int i = 0, num = 0;
    char ch;
    ElemType a, b;
    ElemType result;

    printf("请输入后缀表达式（以$结束）：");
    gets(str);

    while (1) {
        ch = str[i]; 
        i++;      
        // 结束
        if (ch == '$') {
            break;
        }
        //压栈
        if (ch == ' ') {
            if (num != 0) { 
                push(S, num);
                num = 0;
            }
            continue;
        }
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        }
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            popStack(S, &b);
            popStack(S, &a);
            if (ch == '+') result = a + b;
            if (ch == '-') result = a - b;
            if (ch == '*') result = a * b;
            if (ch == '/') result = a / b;
            push(S, result);
        }
    }
    popStack(S, &result);
    printf("result = %d\n", result);
    return 0;
}