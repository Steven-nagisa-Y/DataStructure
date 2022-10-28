#include <stdbool.h>
#include <stdio.h>

#include "Graph.h"

bool TopSort(AGraph *G) {
    int i, j;
    int n = 0;
    int stack[MAX], top = -1;
    ArcNode *p;
    for (i = 0; i < G->n; ++i) {
        if (G->list[i].count == 0) stack[++top] = i;
    }
    while (top != -1) {
        i = stack[top--];
        ++n;
        printf("\t%d", i);
        p = G->list[i].first;
        while (p != NULL) {
            j = p->vex;
            --(G->list[j].count);
            if (G->list[j].count == 0) stack[++top] = j;
            p = p->next;
        }
    }
    if (G->n)
        return true;
    else
        return false;
}
