#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//一趟遍历求最大的节点

typedef int elemType;

typedef struct node {
    elemType data;
    struct node* next;
} Node;

//创建链表
void CreateList(Node** L, int n) {
    *L = (Node*)malloc(sizeof(Node));
    (*L)->next = NULL;
    Node* tail = *L;

    int val;
    printf("请输入%d个链表节点值：\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = val;
        new_node->next = NULL;

        tail->next = new_node;
        tail = new_node;
    }
}

//遍历链表
void listNode(Node* L)
{
    Node* p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//  一趟遍历找最大值节点 
Node* GetMaxNode(Node* L) {
    Node* p = L->next;
    Node* max_node = p;

    while (p != NULL) {
        if (p->data > max_node->data) {
            max_node = p;
        }
        p = p->next;
    }
    return max_node;
}

int main() {
    Node* L;
    int n;
    printf("请输入链表长度n：");
    scanf("%d", &n);

    CreateList(&L, n);
    listNode(L);

    Node* max_node = GetMaxNode(L);
    if (max_node != NULL) {
        printf("最大值节点的值为：%d\n", max_node->data);
    }

    return 0;
}