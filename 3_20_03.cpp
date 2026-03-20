#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
/*利用栈判断字符串是否为回文（将一半字符入栈）*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char SElemType;  
#define MAXSIZE 100     


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

// 进栈操作
int push(Stack* S, SElemType e)
{
    if (S->top == MAXSIZE - 1)  
    {
        printf("栈已满，无法进栈！\n");
        return 0;
    }
    S->top = S->top + 1;
    S->data[S->top] = e;
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
    return 1;
}

// 判断字符串是否为回文
int isPalindrome(char* str)
{
    Stack S;
    initStack(&S);
    int len = strlen(str);
    int i;
    SElemType ch;

    // 第一步：将字符串前一半字符入栈
    for (i = 0; i < len / 2; i++)
    {
        push(&S, str[i]);
    }

    // 第二步：确定后一半字符的起始位置（奇数长度跳过中间字符）
    if (len % 2 != 0)
    {
        i = i + 1;  // 奇数长度时，从中间字符的下一个开始比较
    }

    // 第三步：遍历后一半字符，与栈顶元素比较
    while (str[i] != '\0')
    {
        pop(&S, &ch);
        // 字符不相等则不是回文
        if (ch != str[i])
        {
            return 0;
        }
        i = i + 1;
    }

    // 所有字符匹配成功，是回文
    return 1;
}

int main()
{
    char str[MAXSIZE];
    printf("请输入要判断的字符串：");
    scanf("%s", str);

    if (isPalindrome(str))
    {
        printf("\"%s\" 是回文！\n", str);
    }
    else
    {
        printf("\"%s\" 不是回文！\n", str);
    }

    return 0;
}