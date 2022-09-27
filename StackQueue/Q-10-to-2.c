#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

/**
 * @brief translate 10 based number to 2 based number
 *
 * @param N a 10 based number
 * @return int a 2 based number in display
 */
int trans2bit(int N) {
    int i, res = 0;
    int stack[maxSize], top = -1;
    while (N != 0) {
        i = N % 2;
        N /= 2;
        stack[++top] = i;
    }
    while (top != -1) {
        i = stack[top--];
        res = res * 10 + i;
    }
    return res;
}

int main() {
    int num = 10;
    int res = trans2bit(num);
    printf("%d -> %d", num, res);
    return 0;
}