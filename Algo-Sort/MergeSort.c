/**
 * @brief 归并两端有序序列
 *
 * @param A
 * @param low
 * @param mid
 * @param high
 */
void merge(int A[], int low, int mid, int high) {
    int *T = (int *)malloc(sizeof(int) * (high - low + 1));
    int c = 0;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (A[i] <= A[j])
            T[c++] = A[i++];
        else
            T[c++] = A[j++];
    }
    while (i <= mid) T[c++] = A[i++];
    while (j <= high) T[c++] = A[j++];
    for (int k = 0; k < c; ++k) A[low + k] = T[k];
    free(T);
}

/**
 * @brief 归并排序。
 * 时间复杂度：O(nlog2(n))
 * 空间复杂度：O(n)
 *
 * @param R
 * @param low
 * @param high
 */
void MergeSort(int L[], int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    MergeSort(L, low, mid);
    MergeSort(L, mid + 1, high);
    merge(L, low, mid, high);
}