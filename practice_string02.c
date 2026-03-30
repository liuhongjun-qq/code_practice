//设计一个递归算法实现字符串逆序，要求不另设存储空间
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void exchange(char input[], int left, int right) {
	if (left >= right) {
		return;
	}
	char temp = input[left];
	input[left] = input[right];
	input[right] = temp;
	exchange(input, left + 1, right - 1);
}

int main() {
	char input[1000];
	fgets(input, sizeof(input), stdin);
	int length = strlen(input);

	exchange(input, 0, length - 1);
	
	printf("%s\n", input);
	return 0;
}