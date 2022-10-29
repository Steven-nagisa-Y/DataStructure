#include <stdio.h>

#include "Graph.h"

/**
 * @brief 设在有向图G中某结点能到达其他所有结点，则该节点为根。
 * 通过DFS依次遍历所有结点，若DFS结束时每个结点都访问过，则开始结点为根
 *
 * @param G 邻接表
 * @param v 初始结点编号
 * @param sum 已访问结点数目的指针
 * @param visited 访问标记数组
 */
void findRoot(AGraph *G, int v, int *sum, int *visited) {
    ArcNode *p;
    visited[v] = 1;
    ++(*sum);
    p = G->list[v].first;
    while (p) {
        if (visited[p->vex] == 0) {
            findRoot(G, p->vex, sum, visited);
            p = p->next;
        }
    }
}

void printAllRoot(AGraph *G) {
    int sum;
    int *visited = (int *)malloc(sizeof(int) * G->n);
    for (int i = 0; i < G->n; ++i) {
        // 选取新结点前把sum和visited清空
        sum = 0;
        for (int j = 0; j < G->n; ++j) visited[i] = 0;
        // 对每个结点开始DFS查找
        findRoot(G, i, &sum, visited);
        if (sum == G->n) printf(" %d", i);
    }
}