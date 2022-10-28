#include "Graph.h"

#define MAX_COST 9999

/**
 * @brief 普利姆算法最小生成树
 * O(n^2)
 *
 * @param G 邻接矩阵
 * @param v0 第一个顶点数
 * @param sum 最小权和引用
 */
void Prim(MGraph *G, int v0, int *sum) {
    int N = G->n;
    int lowCost[N], vSet[N], v;
    int k, min;
    v = v0;
    for (int i = 0; i < N; ++i) {
        // 将初始顶点的所有边权加入lowCost
        lowCost[i] = G->edges[v0][i];
        // 为是否并入树中标记0
        vSet[i] = 0;
    }
    // 将初始顶点并入树中并标记
    vSet[v0] = 1;
    // 初始化权和
    *sum = 0;
    for (int i = 0; i < N - 1; ++i) {
        // 找到最小边权，首先初始化为极大值
        min = MAX_COST;
        for (int j = 0; j < N; ++j)
            if (vSet[j] == 0 && lowCost[j] < min) {
                min = lowCost[j];
                k = j;
            }
        // 找到最小边权后加入生成树
        vSet[k] = 1;
        v = k;
        *sum += min;
        for (int j = 0; j < N; ++j) {
            if (vSet[j] == 0 && G->edges[v][j] < lowCost[j])
                lowCost[j] = G->edges[v][j];
        }
    }
}

typedef struct {
    int i, j;  // 边的两个顶点
    int w;     // 边的权值
} Road;

Road road[MAX];
int v[MAX];  // 并查集数组
int getRoot(int a) {
    while (a != v[a]) a = v[a];
    return a;
}

void sortRoad(Road *r, int n) {
    Road *tmp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (r[j] > r[j + 1]) {
                tmp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = tmp;
            }
        }
    }
}

/**
 * @brief 克鲁斯卡尔算法
 *
 * @param G 邻接矩阵
 * @param road  最小权的路径合集
 * @param sum 总权和
 */
void Kruskal(MGraph *G, Road *road, int *sum) {
    int N, E, i, j;
    N = G->n;
    E = G->e;
    *sum = 0;
    int v[N];
    for (int k = 0; k < N; ++k) v[k] = k;
    sortRoad(road, E);
    for (int k = 0; k < E; ++k) {
        i = getRoot(road[k].i);

        
        j = getRoot(road[k].j);
        if (i != j) {
            v[i] = j;
            *sum += road[k].w;
        }
    }
}
