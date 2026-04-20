#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

// 构建next数组
void getNext(char *p, int next[])
{
    int len = strlen(p);
    int j = 0;
    int k = -1;

    next[0] = -1;

    while (j < len - 1)
    {
        if (k == -1)
        {
            j++;
            k++;
            next[j] = k;
        }
        else if (p[j] == p[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

// KMP匹配
int KMP(char *s, char *p, int next[])
{
    int i = 0;
    int j = 0;
    int lenS = strlen(s);
    int lenP = strlen(p);

    if (lenP == 0)
    {
        return 0;
    }

    while (i < lenS && j < lenP)
    {
        if (j == -1)
        {
            i++;
            j++;
        }
        else if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j >= lenP)
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char s[] = "ababcabcacbab";
    char p[] = "abcac";
    int next[256];

    getNext(p, next);
    int pos = KMP(s, p, next);

    if (pos != -1)
    {
        printf("匹配成功，起始下标：%d\n", pos);
    }
    else
    {
        printf("匹配失败\n");
    }

    return 0;
}
