#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
 题目：
 已知字符串 s1 中存放一段英文，设计算法 format(s1, s2, s3, n)。
 功能：
 1. 将 s1 按给定长度 n 格式化到 s2 中（每行长度为 n）。
 2. s2 首尾字符不得为空格，需两端对齐（中间补空格）。
 3. s1 中多余的字符存入 s3。
 要求：不得使用任何库函数。
*/

//计算字符串长度
int myStrlen(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len = len + 1;
    }
    return len;
}

// 格式化函数
void format(char* s1, char* s2, char* s3, int n) {
    int len1 = myStrlen(s1);
    int i = 0;      // s1 的遍历指针
    int j = 0;      // s2 的遍历指针
    int k = 0;      // s3 的遍历指针
    int lineLen = 0; 
    while (s1[i] != '\0') {
        if (lineLen == n || (s1[i] == ' ' && lineLen > 0)) {
            while (lineLen < n) {
                s2[j] = ' ';
                j = j + 1;
                lineLen = lineLen + 1;
            }
            s2[j] = '\n'; 
            j = j + 1;
            lineLen = 0; 
        }

        if (s1[i] == ' ') {
            s2[j] = s1[i];
            j = j + 1;
            i = i + 1;
            lineLen = lineLen + 1;
        }
        else {
            s2[j] = s1[i];
            j = j + 1;
            i = i + 1;
            lineLen = lineLen + 1;
        }
    }
    if (lineLen > 0) {
        while (lineLen < n) {
            s2[j] = ' ';
            j = j + 1;
            lineLen = lineLen + 1;
        }
    }

    s2[j] = '\0'; 

  
    while (s1[i] != '\0') {
        s3[k] = s1[i];
        k = k + 1;
        i = i + 1;
    }
    s3[k] = '\0'; 
}


int main() {
    char s1[1000] = "Hello world this is a test string for formatting";
    char s2[1000];  // 存储格式化后的结果
    char s3[1000];  // 存储溢出的多余字符
    int n = 10;      // 每行的长度要求

    printf("原始字符串 s1:\n%s\n", s1);

    format(s1, s2, s3, n);

    printf("\n格式化后的 s2 (每行 %d 个字符):\n%s", n, s2);
    printf("\n溢出的多余字符 s3:\n%s\n", s3);

    return 0;
}