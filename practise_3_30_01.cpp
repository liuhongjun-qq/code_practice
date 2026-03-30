#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//  构建 next 数组
void getNext(char* pattern, int* next) {
    int len = strlen(pattern);
    next[0] = -1;
    int i = 0;
    int j = -1;

    while (i < len - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

//  KMP 匹配算法
int KMP(char* text, char* pattern) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);
    if (patLen == 0) {
        return 0;
    }

    int* next = (int*)malloc(patLen * sizeof(int));
    if (next == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    getNext(pattern, next);

    int i = 0;
    int j = 0;
    while (i < textLen && j < patLen) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }

    int result;
    if (j == patLen) {
        result = i - j;
    }
    else {
        result = -1;
    }

    free(next);
    return result;
}

int main() {
    char text[] = "ABABCABCABABD";    
    char pattern[] = "ABABD";        

    int index = KMP(text, pattern);

    if (index != -1) {
        printf("匹配成功！起始下标：%d\n", index);
    }
    else {
        printf("未找到匹配串\n");
    }

    return 0;
}