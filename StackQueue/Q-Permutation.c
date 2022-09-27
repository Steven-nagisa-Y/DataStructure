#include <stdio.h>

/**
 * @brief 全排列
 *
 * @param str 排列数组
 * @param n 长度
 * @param k 排列末尾的索引
 */
void perm(char str[], int n, int k) {
    int i, j;
    char tmp;
    if (k == 0) {
        for (j = 0; j < n; ++j) printf("%c", str[j]);
        printf("\n");
        return;
    }
    for (i = 0; i <= k; ++i) {
        tmp = str[k];
        str[k] = str[i];
        str[i] = tmp;
        perm(str, n, k - 1);
        tmp = str[i];
        str[i] = str[k];
        str[k] = tmp;
    }
}

int main() {
    char c[] = {'a', 'b', 'c'};
    int size = sizeof(c) / sizeof(c[0]);
    perm(c, size, size - 1);
    return 0;
}