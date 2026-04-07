#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 100

typedef int TreeType;

typedef struct NodeTree {
	TreeType data;
	struct NodeTree* lchild;
	struct NodeTree* rchild;
}NodeTree, * BiTree;

typedef NodeTree* ElemType;

//前序遍历
void preOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//中序遍历
void midOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	midOrder(T->lchild);
	printf("%d ", T->data);
	midOrder(T->rchild);
}

//后序遍历
void behindOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	behindOrder(T->lchild);
	behindOrder(T->rchild);
	printf("%d ", T->data);
}

//创建二叉树
int str[1000];
int idx;

void inputSeq() {
	int i = 0;
	printf("输入先序序列（-1表示空）：");
	while (scanf("%d", &str[i]) == 1) {
		i++;
		if (getchar() == '\n') {
			break;
		}
	}
	idx = 0;
}
void creatTree(BiTree* T) {
	TreeType ch;
	ch = str[idx++];
	if (ch == -1) {
		*T = NULL;
	}
	else {
		*T = (BiTree)malloc(sizeof(NodeTree));
		(*T)->data = ch;
		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}
}

//判断两棵二叉树是否相等
int isSameTree(BiTree T1, BiTree T2)
{
	if (T1 == NULL && T2 == NULL) {
		return 1;
	}
	if (T1 == NULL || T2 == NULL) {
		return 0;
	}
	if (T1->data != T2->data) {
		return 0;
	}

	//递归判断
	return isSameTree(T1->lchild, T2->lchild) && isSameTree(T1->rchild, T2->rchild);
}

int main() {
	BiTree T1, T2;
	printf("第一棵树");
	inputSeq();
	creatTree(&T1);
	printf("第二棵树");
	inputSeq();
	creatTree(&T2);

	if (isSameTree(T1, T2))
		printf("YES!\n");
	else
		printf("NO！\n");
	return 0;
}