#include "Graph.h"

/**
 * @brief 在图中i,j是否有路径
 *
 * @param gh 邻接表
 * @param i 顶点i编号
 * @param j 顶点j编号
 * @return bool 是否
 */
bool DFStrave(AGraph *gh, int i, int j) {
    int *visited = (int *)malloc(sizeof(int) * gh->n);
    for (i = 0; i < gh->n; ++i) visited[i] = 0;
    DFS(gh, i, visited);
    return visited[j] == 1 ? true : false;
}