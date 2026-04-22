//≤Â»Î≈≈–Ú
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int a[], int n){
    int i, j, temp;
    for (i = 1; i < n; i++){
        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > temp){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

//’€∞Î≤Â»Î≈≈–Ú
void BinInsertSort(int a[], int n){
    int i, j, temp;
    int low, high, mid;

    for (i = 1; i < n; i++){
        temp = a[i];
        low = 0;
        high = i - 1;

        while (low <= high){
            mid = (low + high) / 2;
            if (a[mid] > temp) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        for (j = i - 1; j >= high + 1; j--){
            a[j + 1] = a[j];
        }
        a[high + 1] = temp;
    }
}

//œ£∂˚≈≈–Ú
void ShellSort(int a[], int n){
    int i, j, d, temp;
    d = n / 2;

    while (d > 0){
        for (i = d; i < n; i++){
            temp = a[i];
            j = i - d;
            while (j >= 0 && a[j] > temp){
                a[j + d] = a[j];
                j = j - d;
            }
            a[j + d] = temp;
        }
        d = d / 2;
    }
}

//¥Ú”°
void Print(int a[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int n, i;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    InsertSort(a, n); 
    Print(a, n);
    BinInsertSort(a, n); 
    Print(a, n);
    ShellSort(a, n); 
    Print(a, n);
    free(a);
    return 0;
}