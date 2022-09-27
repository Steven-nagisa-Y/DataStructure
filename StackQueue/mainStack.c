#include <stdbool.h>
#include <stdio.h>

#include "Stack.h"

int main(int argc, char const *argv[]) {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Stack *s = (Stack *)malloc(sizeof(Stack));
    initStack(s);
    for (int i = 0; i < 10; ++i) {
        bool ok = push(s, a[i]);
        if (ok) printf("+%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        int val;
        bool ok = pop(s, &val);
        if (ok) printf("-%d ", val);
    }
    printf("\nLinked list stack:\n");

    int b[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    SNode *ls = (SNode *)malloc(sizeof(SNode));
    initLStack(ls);
    for (int i = 0; i < 10; ++i) {
        pushL(ls, b[i]);
        printf("+%d ", b[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        int val;
        bool ok = popL(ls, &val);
        if (ok) printf("-%d ", val);
    }
    return 0;
}
