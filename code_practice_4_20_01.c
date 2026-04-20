#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int BruteForce(char *s, char *p)
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
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
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

    int pos = BruteForce(s, p);

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
