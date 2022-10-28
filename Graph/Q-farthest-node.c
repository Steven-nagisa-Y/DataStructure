#include "Graph.h"

int getFarthestBFS(AGraph *gh, int v) {
    ArcNode *p;
    int queue[gh->n];
    int front = 0, rear = 0;
    int visited[gh->n];
    for (int i = 0; i < gh->n; ++i) visited[i] = 0;
    int c;
    rear = (rear + 1) % MAX;
    queue[rear] = v;
    visited[v] = 1;
    while (front != rear) {
        front = (front + 1) % MAX;
        c = queue[front];
        p = gh->list[c].first;
        while (p) {
            if (visited[p->vex] == 0) {
                visited[p->vex] = 1;
                rear = (rear + 1) % MAX;
                queue[rear] = p->vex;
            }
            p = p->next;
        }
    }
    return c;
}