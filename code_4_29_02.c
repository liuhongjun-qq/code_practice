#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
题目：创建整型单链表，使用选择排序对链表元素升序排序，输出排序后链表
*/
typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, *LinkList;

LinkList List_SelectSort(LinkList head)
{
    if (head->next == NULL)
    {
        return head;
    }
    LNode* p, *q, *min;
    for (p = head->next; p->next != NULL; p = p->next)
    {
        min = p;
        for (q = p->next; q != NULL; q = q->next)
        {
            if (q->data < min->data)
            {
                min = q;
            }
        }
        if (min != p)
        {
            int temp = p->data;
            p->data = min->data;
            min->data = temp;
        }
    }
    return head;
}

int main()
{
    int a[] = {3, 1, 4, 1, 5};
    int n = 5;
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        p->data = a[i];
        p->next = head->next;
        head->next = p;
    }
    List_SelectSort(head);
    LNode* cur = head->next;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 0;
}
