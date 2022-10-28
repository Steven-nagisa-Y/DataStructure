#include "Graph.h"

/**
 * @brief Get the Count of V, E by DFS
 *
 * @param gh 邻接表
 * @param v 节点编号
 * @param visited 已访问标记
 * @param Vn 顶点个数引用
 * @param En 边个数引用
 */
void getCountDFS(AGraph *gh, int v, int visited[], int *Vn, int *En) {
    ArcNode *p;
    visited[v] = 1;
    ++(*Vn);
    p = gh->list[v].first;
    while (p) {
        ++(*En);
        if (visited[p->vex] == 0) {
            getCountDFS(gh, p->vex, visited, Vn, En);
        }
        p = p->next;
    }
}

bool GraphIsTree(AGraph *gh) {
    int Vn = 0, En = 0, i;
    int *visited = (int *)malloc(sizeof(int) * gh->n);
    for (i = 0; i < gh->n; ++i) visited[i] = 0;
    getCountDFS(gh, 0, visited, &Vn, &En);
    // 节点数和图的顶点数相同，且边数等于顶点数-1.则为树
    if (Vn == gh->n && (gh->n - 1) == En / 2)
        return true;
    else
        return false;
}