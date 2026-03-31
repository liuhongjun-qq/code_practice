#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
 题目：
 设计算法实现函数 void insert(char* s, char* t, int pos)。
 功能：将字符串 t 插入到字符串 s 中，插入位置为 pos。
 要求：不另设存储空间，不得使用任何库函数。
*/

//字符串长度函数
int myStrlen(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len = len + 1;
    }
    return len;
}

// 插入
void insert(char* s, char* t, int pos) {
 
    int lenS = myStrlen(s);
    int lenT = myStrlen(t);
    int endS = lenS - 1;

    int i;
    for (i = endS; i >= pos; i = i - 1) {
        s[i + lenT] = s[i];
    }

    int j = 0;
    while (t[j] != '\0') {
        s[pos + j] = t[j];
        j = j + 1;
    }
    s[lenS + lenT] = '\0';
}

int main() {
    char s[100] = "HelloWorld";
    char t[] = "CSDN";
    int pos = 5; 

    printf("插入前 s: %s\n", s);
    insert(s, t, pos);
    printf("插入后 s: %s\n", s);

    return 0;
}