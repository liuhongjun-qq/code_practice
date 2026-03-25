#define _CRT_SECURE_NO_WARNINGS 1
/*判断栈的IO操作序列是否合法（I入栈，O出栈）*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100  
typedef char SElemType;

// 栈结构定义
typedef struct {
    SElemType data[MAXSIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* S)
{
    S->top = -1;
}

// 判断栈空
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

// 判断栈满
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

// 进栈
int push(Stack* S, SElemType e)
{
    if (isFull(S))
    {
        printf("栈已满，无法进栈！\n");
        return 0;
    }
    S->top = S->top + 1;
    S->data[S->top] = e;
    return 1;
}

// 出栈
int pop(Stack* S)
{
    if (isEmpty(S))
    {
        printf("栈为空，无法出栈！\n");
        return 0;
    }
    S->top = S->top - 1;
    return 1;
}

// 判断IO序列是否合法
int isLegalSequence(char* seq)
{
    Stack S;
    initStack(&S);
    int len = strlen(seq);

    for (int i = 0; i < len; i++)
    {
        // 检查是否为合法字符
        if (seq[i] != 'I' && seq[i] != 'O')
        {
            printf("错误：包含非法字符 '%c'，仅允许I和O！\n", seq[i]);
            return 0;
        }

        if (seq[i] == 'I')
        {
            // 入栈操作
            push(&S, 'I'); 
        }
        else if (seq[i] == 'O')
        {
            // 出栈操作，栈空则序列非法
            if (!pop(&S))
            {
                printf("错误：出栈时栈为空，序列非法！\n");
                return 0;
            }
        }
    }

    // 最终栈必须为空，否则入栈次数多于出栈次数，序列非法
    if (isEmpty(&S))
    {
        return 1;
    }
    else
    {
        printf("错误：最终栈不为空，入栈次数多于出栈次数，序列非法！\n");
        return 0;
    }
}

int main()
{
    char seq[MAXSIZE];
    printf("请输入栈的IO操作序列\n");
    scanf("%s", seq);

    if (isLegalSequence(seq))
    {
        printf("该操作序列是合法序列！\n");
    }
    else
    {
        printf("该操作序列是非法序列！\n");
    }

    return 0;
}