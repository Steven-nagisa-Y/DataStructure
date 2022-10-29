#define BASE 10

#ifndef MAX
#define MAX 256
#endif

/**
 * @brief 基数排序。
 * 时间复杂度：O(digits * (n + base))
 * 空间复杂度：O(base)
 *  digits 为最高位数；n 为个数；base 为基数
 * @param R
 * @param n
 */
void RadixSort(int R[], int n) {
    int i, b[MAX], m = R[0], exp = 1;

    for (i = 1; i < n; i++)
        if (R[i] > m) m = R[i];

    while (m / exp > 0) {
        int bucket[BASE] = {0};
        for (i = 0; i < n; ++i) bucket[(R[i] / exp) % BASE]++;
        for (i = 1; i < BASE; ++i) bucket[i] += bucket[i - 1];
        for (i = n - 1; i >= 0; --i) b[--bucket[(R[i] / exp) % BASE]] = R[i];
        for (i = 0; i < n; ++i) R[i] = b[i];
        exp *= BASE;
    }
}