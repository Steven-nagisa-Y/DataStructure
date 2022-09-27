#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

int main(int argc, char const *argv[]) {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Queue *q = (Queue *)malloc(sizeof(Queue));
    initQueue(q);
    for (int i = 0; i < 10; ++i) {
        bool ok = enQueue(q, a[i]);
        if (ok) printf("+%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        int val;
        bool ok = deQueue(q, &val);
        if (ok) printf("-%d ", val);
    }
    printf("\nLinked list queue:\n");
    int b[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    LQueue *lq = (LQueue *)malloc(sizeof(LQueue));
    initLQueue(lq);
    for (int i = 0; i < 10; ++i) {
        enLQueue(lq, b[i]);
        printf("+%d ", b[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        int val;
        bool ok = deLQueue(lq, &val);
        if (ok) printf("-%d ", val);
    }
    return 0;
}
