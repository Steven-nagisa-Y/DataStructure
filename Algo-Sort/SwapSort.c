/**
 * @brief 冒泡排序。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 * @param R
 * @param n
 */
void BubbleSort(int R[], int n) {
    int flag, tmp;
    for (int i = n - 1; i >= 1; --i) {
        flag = 0;
        for (int j = 1; j <= i; ++j) {
            if (R[j - 1] > R[j]) {
                tmp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0) return;
    }
}

/**
 * @brief 快速排序。
 * 时间复杂度：平均O(nlog2(n))；最坏O(n^2)
 * 空间复杂度：O(log2(n))
 *
 * @param R
 * @param low
 * @param high
 */
void QuickSort(int R[], int low, int high) {
    int tmp;
    int i = low, j = high;
    if (low >= high) return;
    tmp = R[low];
    while (i < j) {
        while (j > i && R[j] >= tmp) --j;
        if (i < j) {
            R[i] = R[j];
            ++i;
        }
        while (i < j && R[i] < tmp) ++i;
        if (i < j) {
            R[j] = R[i];
            --j;
        }
    }
    R[i] = tmp;
    QuickSort(R, low, i - 1);
    QuickSort(R, i + 1, high);
}