#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
题目：构建双向链表，采用双向冒泡排序算法完成元素升序排序，遍历输出结果
*/
typedef struct DNode {
    int data;
    struct DNode* prior;
    struct DNode* next;
}DNode, *DLinkList;

void DList_BiBubbleSort(DLinkList head)
{
    if (head->next == NULL || head->next->next == NULL)
    {
        return;
    }
    int flag;
    DNode *low, *high, *p;
    low = head->next;
    high = NULL;
    do
    {
        flag = 0;
        for (p = low; p->next != high; p = p->next)
        {
            if (p->data > p->next->data)
            {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                flag = 1;
            }
        }
        high = p;
        if (flag == 0)
        {
            break;
        }
        flag = 0;
        for (p = high->prior; p != head && p != low->prior; p = p->prior)
        {
            if (p->prior->data > p->data)
            {
                int temp = p->prior->data;
                p->prior->data = p->data;
                p->data = temp;
                flag = 1;
            }
        }
        low = p->next;
    } while (flag);
}

int main()
{
    int a[] = {5, 3, 8, 1, 2};
    int n = 5;
    DLinkList head = (DLinkList)malloc(sizeof(DNode));
    head->next = NULL;
    head->prior = NULL;
    DNode* tail = head;
    for (int i = 0; i < n; i++)
    {
        DNode* p = (DNode*)malloc(sizeof(DNode));
        p->data = a[i];
        p->next = NULL;
        p->prior = tail;
        tail->next = p;
        tail = p;
    }
    DList_BiBubbleSort(head);
    DNode* cur = head->next;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 0;
}
