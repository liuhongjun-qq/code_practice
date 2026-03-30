#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

/*题目：
 输入一个只包含大写英文字符（A~Z）和数字（0~9）的字符串，
 统计字符串中每个字母和每个数字出现的频率，
 并将统计结果写入文件 char_frequency.txt 中。
 要求：忽略除 A~Z、0~9 以外的所有字符。*/

// 初始化计数数组
void initCount(int letterCount[], int digitCount[]) {
    int i;
    for (i = 0; i < 26; i++) {
        letterCount[i] = 0;
    }
 
    for (i = 0; i < 10; i++) {
        digitCount[i] = 0;
    }
}

// 输入字符串
void inputString(char str[]) {
    printf("请输入待统计的字符串（仅含A-Z和0-9）：");
    scanf("%s", str);
}

// 统计字符频率
void countFrequency(char str[], int letterCount[], int digitCount[]) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            int index = str[i] - 'A';
            letterCount[index] = letterCount[index] + 1;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            int index = str[i] - '0';
            digitCount[index] = digitCount[index] + 1;
        }
    }
}

// 将结果写入文件
void writeToFile(int letterCount[], int digitCount[]) {
    FILE* fp;
    fp = fopen("char_frequency.txt", "w");

    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }

    
    fprintf(fp, "字母出现频率：\n");
    int i;
    for (i = 0; i < 26; i++) {
        fprintf(fp, "%c: %d\n", 'A' + i, letterCount[i]);
    }

    
    fprintf(fp, "\n数字出现频率：\n");
    for (i = 0; i < 10; i++) {
        fprintf(fp, "%d: %d\n", i, digitCount[i]);
    }

    fclose(fp);
    printf("统计结果已写入char_frequency.txt文件！\n");
}


int main() {
    int letterCount[26];
    int digitCount[10];
    char inputStr[1000];

    initCount(letterCount, digitCount);  
    inputString(inputStr);             
    countFrequency(inputStr, letterCount, digitCount); 
    writeToFile(letterCount, digitCount); 

    return 0;
}