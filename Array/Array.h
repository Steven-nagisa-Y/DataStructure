#include <stdio.h>

void printIntArr(int *arr, int n) {
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}