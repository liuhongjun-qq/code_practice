#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

/*
 Éè¼ÆÒ»¸öµÝ¹éËã·¨ÊµÏÖ×Ö·û´®ÄæÐò´æ´¢£¬ÒªÇó²»ÁíÉè´æ´¢¿Õ¼ä¡£
*/

// µÝ¹éÊµÏÖ×Ö·û´®ÄæÐò
void reverseStringRecursive(char str[], int left, int right) {

    if (left >= right) {
        return;
    }
    
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    int newLeft = left + 1;
    int newRight = right - 1;
    reverseStringRecursive(str, newLeft, newRight);
}

void reverseString(char str[]) {
    int len = strlen(str);
    if (len <= 1) {
        return; 
    }
    reverseStringRecursive(str, 0, len - 1);
}


int main() {
    char str[100]; 
    printf("ÇëÊäÈëÐèÒªÄæÐòµÄ×Ö·û´®£º");
    scanf("%s", str);

    printf("ÄæÐòÇ°£º%s\n", str);
    reverseString(str); 
    printf("ÄæÐòºó£º%s\n", str);

    return 0;
}