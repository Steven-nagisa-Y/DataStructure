/**
 * @brief 选择排序。
 * 时间复杂度：O(n^2)
 * 空间复杂度O(1)
 *
 * @param R
 * @param n
 */
void SelectSort(int R[], int n) {
    int tmp;
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j)
            if (R[k] > R[j]) k = j;
        tmp = R[i];
        R[i] = R[k];
        R[k] = tmp;
    }
}

/**
 * @brief 调整堆排序结点。
 * 时间复杂度O(log2(n))
 *
 * @param R 排序数组
 * @param low
 * @param high
 */
void HeapAdjust(int R[], int low, int high) {
    int i = low, j = 2 * i;
    int tmp = R[i];
    while (j <= high) {
        if (j < high && R[j] < R[j + 1]) ++j;
        if (R[i] < R[j]) {
            R[i] = R[j];
            i = j;
            j = 2 * i;
        } else
            break;
    }
    R[i] = tmp;
}

/**
 * @brief 堆排序。
 * 时间复杂度：O(nlog2(n))
 * 空间复杂度：o(1)
 *
 * @param R 待排序数组
 * @param n 数组长度
 */
void HeapSort(int R[], int n) {
    // 将初始数组后移一位用于构建二叉树
    int *L = (int *)malloc(sizeof(int) * (n + 1));
    L[0] = -1;
    for (int i = 1; i <= n; ++i) L[i] = R[i - 1];
    // END
    int tmp;
    for (int i = n / 2; i > 0; --i) HeapAdjust(L, i, n);
    for (int i = n; i > 1; --i) {
        tmp = L[1];
        L[1] = L[i];
        L[i] = tmp;
        HeapAdjust(L, 1, i - 1);
    }
    // 将二叉树还原成数组
    for (int i = 0; i < n; ++i) R[i] = L[i + 1];
}