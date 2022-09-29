#include <stdio.h>

#include "Array.h"

int findMax(int *arr, int i, int j) {
    if (i == j) return arr[i];
    int max;
    max = findMax(arr, i + 1, j);
    return arr[i] < max ? max : arr[i];
}

int sumTotal(int *arr, int i, int j) {
    if (i == j)
        return arr[i];
    else
        return arr[i] + sumTotal(arr, i + 1, j);
}

int main(int argc, char const *argv[]) {
    int a[] = {4, 1, 2, 3, 6, 7, 10, 8};
    int max = findMax(a, 0, 8 - 1);
    int sum = sumTotal(a, 0, 8 - 1);
    printIntArr(a, 8);
    printf("max = %d\n", max);
    printf("sum = %d", sum);
    return 0;
}
