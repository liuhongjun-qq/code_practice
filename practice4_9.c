#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void PrintStar(int n) {
	int empty, star;
	for (int i = 1;i <= n;i++) {
		if (i * 2 < n) {
			empty = (n - 2 * i + 1) / 2;
			star = 2 * i - 1;
		}
		else {
			empty = (2 * i - 1 - n) / 2;
			star = n - 2 * empty;
		}
		while (empty > 0) {
			printf(" ");
			empty--;
		}
		while (star > 0) {
			printf("*");
			star--;
		}
		printf("\n");
	}
}

int main() {
	int n;
	printf("请输入一个奇数：");
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("Error！");
	}
	else {
		PrintStar(n);
	}
	return 0;
}