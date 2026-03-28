//输入整数序列a1，a2，...，an，当输入的数为-1时是出栈操作，其余为入栈，输出入栈或出栈元素
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct stack {
    ElemType data;
    struct stack* next;
} Stack;

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
    Stack* S = initStack();
    int n;     
    int num; 
    int top_val; 

    printf("输入整数序列个数：");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        if (num != -1) {
            push(S, num);
            printf("入栈元素：%d\n", num);
        }
        else {
            if (isEmpty(S)) {
                printf("Error！\n");
                break;
            }
            else {
                popStack(S, &top_val);
                printf("出栈元素：%d\n", top_val);
            }
        }
    }

    while (!isEmpty(S)) {
        popStack(S, &top_val);
    }
    free(S);
    return 0;
}