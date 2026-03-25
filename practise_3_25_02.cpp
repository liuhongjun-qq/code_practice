#define _CRT_SECURE_NO_WARNINGS 1
/*用栈处理整数序列：输入非-1进栈，输入-1出栈并输出栈顶，处理栈满/栈空异常*/
#include<stdio.h>
#include<stdlib.h>

typedef int SElemType;  
#define MAXSIZE 10     

// 定义栈结构
typedef struct {
    SElemType data[MAXSIZE];
    int top;  
} Stack;

// 初始化栈
void initStack(Stack* S)
{
    S->top = -1;  
}

// 判断栈是否为空
int isEmpty(Stack* S)
{
    if (S->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 判断栈是否已满
int isFull(Stack* S)
{
    if (S->top == MAXSIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 进栈操作
int push(Stack* S, SElemType e)
{
    if (isFull(S))  
    {
        printf("栈已满，%d 无法进栈！\n", e);
        return 0;
    }
    S->top = S->top + 1;
    S->data[S->top] = e;
    printf("%d 已进栈\n", e);
    return 1;
}

// 出栈操作
int pop(Stack* S, SElemType* e)
{
    if (isEmpty(S))  
    {
        printf("栈为空，无法出栈！\n");
        return 0;
    }
    *e = S->data[S->top];
    S->top = S->top - 1;
    printf("栈顶元素 %d 已出栈\n", *e);
    return 1;
}

// 核心算法：处理整数序列输入
void handleIntSequence(Stack* S)
{
    SElemType num;
    printf("请输入整数序列（输入-1出栈，输入-2结束程序）：\n");
    while (1)
    {
        scanf("%d", &num);
        if (num == -2)  
        {
            printf("程序结束\n");
            break;
        }
        else if (num == -1) 
        {
            SElemType pop_num;
            pop(S, &pop_num);
        }
        else  
        {
            push(S, num);
        }
    }
}


int main()
{
    Stack S;
    initStack(&S);
    handleIntSequence(&S);
    return 0;
}