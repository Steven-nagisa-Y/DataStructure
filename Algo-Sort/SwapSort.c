/**
 * @brief 冒泡排序。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 * @param L
 * @param n
 */
void BubbleSort(int L[], int n) {
    int flag, tmp;
    for (int i = n - 1; i >= 1; --i) {
        flag = 0;
        for (int j = 1; j <= i; ++j) {
            if (L[j - 1] > L[j]) {
                tmp = L[j];
                L[j] = L[j - 1];
                L[j - 1] = tmp;
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
 * @param L
 * @param low
 * @param high
 */
void QuickSort(int L[], int low, int high) {
    int tmp;
    int i = low, j = high;
    if (low >= high) return;
    tmp = L[low];
    while (i < j) {
        while (j > i && L[j] >= tmp) --j;
        if (i < j) {
            L[i] = L[j];
            ++i;
        }
        while (i < j && L[i] < tmp) ++i;
        if (i < j) {
            L[j] = L[i];
            --j;
        }
    }
    L[i] = tmp;
    QuickSort(L, low, i - 1);
    QuickSort(L, i + 1, high);
}