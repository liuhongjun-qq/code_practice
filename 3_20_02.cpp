#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
/*双栈共享数组空间：初始化、判空、判满、进栈、出栈*/
#include<stdio.h>
#include<stdlib.h>

typedef int SElemType;  // 栈元素类型
#define MAXSIZE 100     // 数组最大容量

// 双栈结构定义
typedef struct {
    int top[2], bot[2]; // 栈顶、栈底指针（0号栈和1号栈）
    SElemType* V;       // 存储栈元素的数组
    int m;              // 栈最大可容纳元素个数
} DblStack;

// 初始化双栈
int initDblStack(DblStack* DS, int m)
{
    DS->V = (SElemType*)malloc(m * sizeof(SElemType));
    if (DS->V == NULL) 
    {
        printf("内存分配失败！\n");
        return 0;
    }
    DS->m = m;
    // 初始化0号栈:栈底在数组起始位置，栈顶为-1（空栈）
    DS->bot[0] = 0;
    DS->top[0] = -1;
    // 初始化1号栈：栈底在数组末尾位置，栈顶为m（空栈）
    DS->bot[1] = m - 1;
    DS->top[1] = m;
    return 1;
}

// 判断栈是否为空（stackNum：0表示0号栈，1表示1号栈）
int isEmpty(DblStack* DS, int stackNum)
{
    if (stackNum == 0)
    {
        // 判断0号栈是否为空
        if (DS->top[0] == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (stackNum == 1)
    {
        // 判断1号栈是否为空
        if (DS->top[1] == DS->m)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("栈编号错误！\n");
        return -1;
    }
}

// 判断双栈是否已满
int isFull(DblStack* DS)
{
    if (DS->top[0] + 1 == DS->top[1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 进栈
int push(DblStack* DS, int stackNum, SElemType e)
{
    if (isFull(DS))
    {
        printf("双栈已满，无法进栈！\n");
        return 0;
    }

    if (stackNum == 0)
    {
        // 先把栈顶上移，再存入元素
        DS->top[0] = DS->top[0] + 1;
        DS->V[DS->top[0]] = e;
    }
    else if (stackNum == 1)
    {
        // 先把栈顶上移，再存入元素
        DS->top[1] = DS->top[1] - 1;
        DS->V[DS->top[1]] = e;
    }
    else
    {
        printf("栈编号错误！\n");
        return 0;
    }

    return 1;
}

// 出栈
int pop(DblStack* DS, int stackNum, SElemType* e)
{
    if (isEmpty(DS, stackNum))  // 对应栈为空
    {
        printf("%d号栈为空，无法出栈！\n", stackNum);
        return 0;
    }
    if (stackNum == 0)
    {
        // 先取出元素，再修改栈顶指针
        *e = DS->V[DS->top[0]];
        DS->top[0] = DS->top[0] - 1;
    }
    else if (stackNum == 1)
    {
        // 先取出元素，再修改栈顶指针
        *e = DS->V[DS->top[1]];
        DS->top[1] = DS->top[1] + 1;
    }
    else
    {
        printf("栈编号错误！\n");
        return 0;
    }
    return 1;
}

// 遍历栈
void printStack(DblStack* DS, int stackNum)
{
    if (isEmpty(DS, stackNum))
    {
        printf("%d号栈为空！\n", stackNum);
        return;
    }
    printf("%d号栈元素：", stackNum);
    if (stackNum == 0)
    {
        for (int i = 0; i <= DS->top[0]; i++)
        {
            printf("%d ", DS->V[i]);
        }
    }
    else if (stackNum == 1)
    {
        for (int i = DS->top[1]; i <= DS->bot[1]; i++)
        {
            printf("%d ", DS->V[i]);
        }
    }
    printf("\n");
}

// 主函数测试
int main()
{
    DblStack DS;
    initDblStack(&DS, 10);  // 初始化容量为10的双栈

    // 0号栈进栈
    push(&DS, 0, 1);
    push(&DS, 0, 2);
    push(&DS, 0, 3);
    // 1号栈进栈
    push(&DS, 1, 10);
    push(&DS, 1, 20);
    push(&DS, 1, 30);

    printf("进栈后：\n");
    printStack(&DS, 0);
    printStack(&DS, 1);

    // 出栈操作
    SElemType e;
    pop(&DS, 0, &e);
    printf("0号栈出栈元素：%d\n", e);
    pop(&DS, 1, &e);
    printf("1号栈出栈元素：%d\n", e);

    printf("出栈后：\n");
    printStack(&DS, 0);
    printStack(&DS, 1);

    free(DS.V); 
    return 0;
}