#include <stdio.h>

#include "Array.h"

void moveZero(int *arr, int n) {
    int i = -1, j = 0, temp;
    for (j = 0; j < n; ++j) {
        if (arr[j] != 0) {
            ++i;
            if (i != j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int a[] = {0, 1, 2, 4, 0, 0, 4, 6, 7, 0};
    printIntArr(a, 10);
    moveZero(a, 10);
    printIntArr(a, 10);
    return 0;
}
