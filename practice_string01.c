//统计输入的字符串中各个不同的数字和大写字母出现的次数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	char input[1000];
	fgets(input, sizeof(input), stdin);
	int length = strlen(input);
	int letter[26] = { 0 };
	int number[10] = { 0 };


	for (int i = 0;i < length;i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			number[input[i] - '0']++;
		}
		if (input[i] >= 'A' && input[i] <= 'Z') {
			letter[input[i] - 'A']++;
		}
	}

	for (int j = 0;j < 10;j++) {
		printf("%d:%d\n", j, number[j]);
	}
	for (int k = 0;k < 26;k++) {
		printf("%c:%d\n", k + 'A', letter[k]);
	}

	return 0;
}