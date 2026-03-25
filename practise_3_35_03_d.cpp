#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
/*计算后缀表达式的值*/
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>  /

typedef int SElemType;
#define MAXSIZE 100  

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
        return 1;
    else
        return 0;
}

// 判断栈满
int isFull(Stack* S)
{
    if (S->top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

// 进栈
int push(Stack* S, SElemType e)
{
    if (isFull(S))
    {
        printf("栈溢出！\n");
        return 0;
    }
    S->top = S->top + 1;
    S->data[S->top] = e;
    return 1;
}

// 出栈
int pop(Stack* S, SElemType* e)
{
    if (isEmpty(S))
    {
        printf("栈为空！\n");
        return 0;
    }
    *e = S->data[S->top];
    S->top = S->top - 1;
    return 1;
}

// 获取栈顶元素但不出栈
int getTop(Stack* S, SElemType* e)
{
    if (isEmpty(S))
    {
        return 0;
    }
    *e = S->data[S->top];
    return 1;
}

// ：计算后缀表达式
int calculatePostfix()
{
    Stack S;
    initStack(&S);
    char token[20];  // 存储当前读取的操作数或运算符
    int i = 0;
    char ch;
    SElemType num, a, b;

    printf("请输入后缀表达式（以$结束）：\n");

    // 循环读取输入，直到遇到结束符$
    while (1)
    {
        // 读取一个字符
        scanf(" %c", &ch);  // 前面加空格跳过所有空白字符

        if (ch == '$')  // 遇到结束符
        {
            break;
        }

        if (isspace(ch))  // 空格则继续读取下一个
        {
            continue;
        }

        if (isdigit(ch))  // 如果是数字
        {
            // 处理多位数，把完整数字读入token
            int num_val = 0;
            do
            {
                num_val = num_val * 10 + (ch - '0');
                scanf("%c", &ch);
            } while (isdigit(ch));

            // 将读取到的数字入栈
            push(&S, num_val);
        }
        else  // 运算符
        {
            // 出栈两个操作数
            if (!pop(&S, &b)) return -1;
            if (!pop(&S, &a)) return -1;

            // 根据运算符计算
            switch (ch)
            {
            case '+': num = a + b; break;
            case '-': num = a - b; break;
            case '*': num = a * b; break;
            case '/':
                if (b == 0)
                {
                    printf("错误：除数为0！\n");
                    return -1;
                }
                num = a / b;
                break;
            default:
                printf("错误：未知运算符 %c\n", ch);
                return -1;
            }
            // 计算结果入栈
            push(&S, num);
        }
    }

    // 最终栈顶元素即为结果
    if (!pop(&S, &num)) return -1;

    // 检查栈是否已空）
    if (!isEmpty(&S))
    {
        printf("警告：表达式格式错误，存在多余元素！\n");
        return -1;
    }

    return num;
}

int main()
{
    int result = calculatePostfix();
    if (result != -1)
    {
        printf("计算结果为：%d\n", result);
    }
    return 0;
}