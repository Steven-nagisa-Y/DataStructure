#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#ifndef MAX
#define MAX 9999999
#endif

/**
 * @brief 根据下标树打印顶点路径
 *
 * @param path 路径树
 * @param a 目标顶点号
 */
void printPath(int *path, int a) {
    int stack[MAX];
    int top = -1;
    while (path[a] != -1) {
        stack[++top] = a;
        a = path[a];
    }
    stack[++top] = a;
    while (top != -1) printf("\t%d", stack[top--]);
    printf("\n");
}

/**
 * @brief 迪杰斯特拉算法
 *  时间复杂度为O(n^2)
 * @param G 邻接矩阵
 * @param v 初始顶点
 * @param dist 存放了v到其余各顶点的最短路径长度
 * @param path 存放了v到其余各顶点的最短路径
 */
void Dijkstra(MGraph *G, int v, int dist[], int path[]) {
    int set[MAX];
    int min, i, j, u;
    for (i = 0; i < G->n; ++i) {
        dist[i] = G->edges[v][i];
        set[i] = 0;
        if (G->edges[v][i] < MAX)
            path[i] = v;
        else
            path[i] = -1;
    }
    set[v] = 1;
    path[v] = -1;
    // 关键循环
    for (i = 0; i < G->n - 1; ++i) {
        min = MAX;
        for (j = 0; j < G->n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        set[u] = 1;
        for (j = 0; j < G->n; ++j) {
            if (set[j] == 0 && dist[u] + G->edges[u][j] < dist[j]) {
                dist[j] = dist[u] + G->edges[u][j];
                path[j] = u;
            }
        }
    }
}

int main() {
    int N;
    printf("Vertex num: ");
    scanf("%d", &N);
    MGraph *G = (MGraph *)malloc(sizeof(MGraph));
    G->n = N;
    G->e = 0;
    for (int i = 0; i < N; ++i) {
        G->vex[i] = i;
        G->edges[i][i] = 0;
        for (int j = 0; j < N; ++j) {
            int tmp;
            // printf("%d to %d: ", i, j);
            if (j != i) {
                scanf("%d", &tmp);
                if (tmp < 256) {
                    ++G->e;
                }
                G->edges[i][j] = tmp;
            }
        }
    }
    printf("Vertex Matrix:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) printf("\t%d", G->edges[i][j]);
        printf("\n");
    }
    int dist[N];
    int path[N];
    int start;
    printf("\nStart Vertex(0-%d): ", N - 1);
    scanf("%d", &start);
    if (start >= N || start < 0) return -1;
    Dijkstra(G, start, dist, path);
    printf("%d to rest:\n");
    for (int i = 0; i < N; ++i) printf("\t%d", dist[i]);
    printf("\n");
    int target;
    printf("\nTarget Vertex(0-%d): ", N - 1);
    scanf("%d", &target);
    if (target >= N || target < 0) return -1;
    printPath(path, target);
    return 0;
}