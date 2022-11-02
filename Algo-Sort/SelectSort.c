/**
 * @brief 选择排序。
 * 时间复杂度：O(n^2)
 * 空间复杂度O(1)
 *
 * @param L
 * @param n
 */
void SelectSort(int L[], int n) {
    int tmp;
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j)
            if (L[k] > L[j]) k = j;
        tmp = L[i];
        L[i] = L[k];
        L[k] = tmp;
    }
}

/**
 * @brief 调整堆排序结点。
 * 时间复杂度O(log2(n))
 *
 * @param L 排序数组
 * @param low
 * @param high
 */
void HeapAdjust(int L[], int low, int high) {
    int i = low, j = 2 * i;
    int tmp = L[i];
    while (j <= high) {
        if (j < high && L[j] < L[j + 1]) ++j;
        if (L[i] < L[j]) {
            L[i] = L[j];
            i = j;
            j = 2 * i;
        } else
            break;
    }
    L[i] = tmp;
}

/**
 * @brief 堆排序。
 * 时间复杂度：O(nlog2(n))
 * 空间复杂度：o(1)
 *
 * @param L 待排序数组
 * @param n 数组长度
 */
void HeapSort(int L[], int n) {
    // 将初始数组后移一位用于构建二叉树
    int *T = (int *)malloc(sizeof(int) * (n + 1));
    T[0] = -1;
    for (int i = 1; i <= n; ++i) T[i] = L[i - 1];
    // END
    int tmp;
    for (int i = n / 2; i > 0; --i) HeapAdjust(T, i, n);
    for (int i = n; i > 1; --i) {
        tmp = T[1];
        T[1] = T[i];
        T[i] = tmp;
        HeapAdjust(T, 1, i - 1);
    }
    // 将二叉树还原成数组
    for (int i = 0; i < n; ++i) L[i] = T[i + 1];
    free(T);
}