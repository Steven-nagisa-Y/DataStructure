#include <stdio.h>
#include <stdlib.h>

#include "SequenceList.h"

/**
 * @brief 将一个顺序表前k个数置逆
 *
 * @return int
 */
int main_reverse() {
    // create a sequence list
    SeqListChar list = {
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'}, 12};
    printListChar(list);
    reverseChar(&list, 0, 11, 3);
    printListChar(list);
    moveCharToEnd(&list, 3);
    printListChar(list);
    return 0;
}

/**
 * @brief 一个顺序表，前m个数和后n个数分别有序，排序成整个顺序表有序
 *
 * @param list
 * @param m
 * @param n
 */
void sortTwoSectorNum(int *list, int m, int n) {
    int i, j;
    int tmp;
    // 后n个数插入前m个数
    for (i = m; i < m + n; i++) {
        tmp = list[i];
        for (j = i - 1; j >= 0 && tmp < list[j]; j--) {
            list[j + 1] = list[j];
        }
        list[j + 1] = tmp;
    }
}

int main() {
    int A[] = {1, 2, 3, 5, 6,  8,  10, 12, 15, 19, 3,
               4, 6, 7, 9, 10, 12, 14, 16, 19, 20, 21};
    int m = 10, n = 12;
    sortTwoSectorNum(A, m, n);
    for (int i = 0; i < m + n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
