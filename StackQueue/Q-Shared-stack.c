#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxSize 20

typedef struct {
    int elem[maxSize];
    int top[2];
} Stack;

bool pushT(Stack *s, int x, int val) {
    if (s->top[0] + 1 >= s->top[1]) return false;
    if (x == 0) {
        ++(s->top[0]);
        s->elem[s->top[0]] = val;
        return true;
    } else {
        --(s->top[1]);
        s->elem[s->top[1]] = val;
        return true;
    }
}

bool popT(int *elem, int *top, int x, int *val) {
    if (x == 0) {
        if (top[0] == -1) return false;
        *val = elem[top[0]];
        --(top[0]);
        return true;
    } else if (x == 1) {
        if (top[1] == maxSize) return false;
        *val = elem[top[1]];
        ++(top[1]);
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 两端确定的连续空间实现两个共享栈
 *
 * @return int
 */
int main() {
    // 设置栈0的底在elem[0]，栈1的底在elem[maxSize-1]
    // 栈满条件是：top[0]+1 >= top[1]
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Stack *s = (Stack *)malloc(sizeof(Stack));
    return 0;
}
