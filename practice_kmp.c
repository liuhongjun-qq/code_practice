//kmp
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define MAXSIZE 100

//获取next数组
void build_next(char t[], int next[]){
    int i = 0;
    int j = -1;
    int len = strlen(t);
    next[0] = -1;

    while (i < len - 1){
        if (j == -1 || t[i] == t[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

//kmp算法
int KMP(char s[], char t[], int next[]){
    int i = 0;
    int j = 0;
    int lens = strlen(s);
    int lent = strlen(t);
    while (i < lens && j < lent){
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if (j >= lent){
        return i - j; 
    }
    else{
        return -1;
    }
}

int main(){
    char s[MAXSIZE];
    char t[MAXSIZE];
    int next[MAXSIZE];
    int pos;

    printf("主串：");
    scanf("%s", s);
    printf("模式串：");
    scanf("%s", t);

    build_next(t, next);
    pos = KMP(s, t, next);

    if (pos != -1) {
        printf("找到字串，起始下标为：%d\n", pos);
    }
    else{
        printf("未找到子串\n");
    }
    return 0;
}
