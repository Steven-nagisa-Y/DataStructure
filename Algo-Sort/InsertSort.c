/**
 * @brief 插入排序。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 * @param L
 * @param n
 */
void InsertSort(int L[], int n) {
    int tmp;
    for (int i = 1; i < n; ++i) {
        tmp = L[i];
        int j = i - 1;
        while (j >= 0 && tmp < L[j]) {
            L[j + 1] = L[j];
            --j;
        }
        L[j + 1] = tmp;
    }
}

/**
 * @brief 希尔排序。不稳定排序。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 * @param L
 * @param n
 */
void ShellSort(int L[], int n) {
    int step, tmp;
    for (step = n >> 1; step > 0; step >>= 1) {
        for (int i = step; i < n; ++i) {
            tmp = L[i];
            int j = i - step;
            while (j >= 0 && L[j] > tmp) {
                L[j + step] = L[j];
                j -= step;
            }
            L[j + step] = tmp;
        }
    }
}