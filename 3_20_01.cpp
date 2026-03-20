#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
/*删除顺序表中所有值为item的元素，时间O(n)，空间O(1)*/
#include<stdio.h>
#include<stdlib.h>

typedef int elemType;
#define MAXSIZE 100 

typedef struct {
	elemType data[MAXSIZE];
	int length; 
} SqList;

// 初始化顺序表
void initSqList(SqList* L)
{
	L->length = 0;  
}

// 尾插法
int insertTail(SqList* L, elemType e)
{
	if (L->length >= MAXSIZE)  
	{
		printf("顺序表已满，无法插入！\n");
		return 0;
	}
	L->data[L->length++] = e;
	return 1;
}

// 遍历顺序表
void printSqList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//删除所有值为item的元素
void deleteItem(SqList* L, elemType item)
{
	int j = 0; 
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] != item)
		{
			L->data[j] = L->data[i];
			j++;
		}
	}
	L->length = j; 
}


int main()
{
	SqList L;
	initSqList(&L);

	insertTail(&L, 1);
	insertTail(&L, 2);
	insertTail(&L, 3);
	insertTail(&L, 2);
	insertTail(&L, 4);
	insertTail(&L, 2);
	insertTail(&L, 5);

	printf("原顺序表：");
	printSqList(&L);

	elemType item;
	printf("请输入要删除的元素值：");
	scanf("%d", &item);

	deleteItem(&L, item);
	printf("删除后顺序表：");
	printSqList(&L);

	return 0;
}