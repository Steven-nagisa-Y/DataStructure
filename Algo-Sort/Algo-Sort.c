#include <stdio.h>
#include <stdlib.h>

#include "InsertSort.c"
#include "MergeSort.c"
#include "RadixSort.c"
#include "SelectSort.c"
#include "SwapSort.c"

int main(int argc, char const *argv[]) {
    int n;
    printf("Length: ");
    scanf("%d", &n);
    if (n <= 1) return 1;
    int *R = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) scanf("%d", &R[i]);

    RadixSort(R, n);
    for (int i = 0; i < n; ++i) printf("%d ", R[i]);
    return 0;
}
