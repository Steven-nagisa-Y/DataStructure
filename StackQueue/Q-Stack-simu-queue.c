#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 200

typedef struct {
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} DQueue;

DQueue* DQueueCreate() {
    DQueue* queue = (DQueue*)malloc(sizeof(DQueue));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void DQueuePush(DQueue* obj, int x) {
    int y;
    if (obj->top1 == MAX - 1) {
        if (!obj->top2 == -1) return;
        while (obj->top1 != -1) {
            y = obj->stack1[obj->top1];
            --(obj->top1);
            ++(obj->top2);
            obj->stack2[obj->top2] = y;
        }
        ++(obj->top1);
        obj->stack1[obj->top1] = x;
        return;

    } else {
        ++(obj->top1);
        obj->stack1[obj->top1] = x;
        return;
    }
}

int DQueuePop(DQueue* obj) {
    int x;
    int y;
    if (obj->top2 != -1) {
        x = obj->stack2[obj->top2];
        --(obj->top2);
        return x;
    } else {
        if (obj->top1 == -1)
            return 0;
        else {
            while (obj->top1 != -1) {
                y = obj->stack1[obj->top1];
                --(obj->top1);
                ++(obj->top2);
                obj->stack2[obj->top2] = y;
            }
            x = obj->stack2[obj->top2];
            --(obj->top2);
            return x;
        }
    }
}

int DQueuePeek(DQueue* obj) {
    int x;
    int y;
    if (obj->top2 != -1) {
        x = obj->stack2[obj->top2];
        return x;
    } else {
        if (obj->top1 == -1)
            return 0;
        else {
            while (obj->top1 != -1) {
                y = obj->stack1[obj->top1];
                --(obj->top1);
                ++(obj->top2);
                obj->stack2[obj->top2] = y;
            }
            x = obj->stack2[obj->top2];
            return x;
        }
    }
}

bool DQueueEmpty(DQueue* obj) {
    if (obj->top1 == -1 && obj->top2 == -1)
        return true;
    else
        return false;
}

void DQueueFree(DQueue* obj) { free(obj); }

/**
 * @brief 使用两个栈模拟队列
 *
 * @return int
 */
int main() {
    DQueue* q = DQueueCreate();
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 0};
    for (int i = 0; i < 5; ++i) {
        DQueuePush(q, a[i]);
        printf("+%d ", a[i]);
    }
    int peek = DQueuePeek(q);
    printf("\nPeek: %d\n", peek);
    for (int i = 0; i < 2; ++i) DQueuePop(q);
    for (int i = 0; i < 5; ++i) {
        DQueuePush(q, b[i]);
        printf("+%d ", b[i]);
    }
    int peek2 = DQueuePeek(q);
    printf("\nPeek: %d\n", peek2);
    while (!DQueueEmpty(q)) {
        int pop = DQueuePop(q);
        printf("-%d ", pop);
    }
    return 0;
}
