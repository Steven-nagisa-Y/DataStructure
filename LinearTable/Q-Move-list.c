#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    const int len = 12;
    const int N = 4;
    // 将前N项循环左移到后
    int tmp[N];
    for (int i = 0; i < N; i++) tmp[i] = a[i];
    for (int i = N; i < len; i++) {
        a[i - N] = a[i];
    }
    for (int i = len - N; i < len; i++) {
        a[i] = tmp[i - len + N];
    }
    for (int i = 0; i < len; i++) printf("%d ", a[i]);
    return 0;
}
