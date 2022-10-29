/**
 * @brief 插入排序。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 * @param R
 * @param n
 */
void InsertSort(int R[], int n) {
    int tmp;
    for (int i = 1; i < n; ++i) {
        tmp = R[i];
        int j = i - 1;
        while (j >= 0 && tmp < R[j]) {
            R[j + 1] = R[j];
            --j;
        }
        R[j + 1] = tmp;
    }
}

/**
 * @brief 希尔排序。不稳定排序。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 * @param R
 * @param n
 */
void ShellSort(int R[], int n) {
    int step, tmp;
    for (step = n >> 1; step > 0; step >>= 1) {
        for (int i = step; i < n; ++i) {
            tmp = R[i];
            int j = i - step;
            while (j >= 0 && R[j] > tmp) {
                R[j + step] = R[j];
                j -= step;
            }
            R[j + step] = tmp;
        }
    }
}