#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 512

/**
 *
 */
typedef struct {
    int no;            // 节点编号
    /** char type; */  // 节点类型
} VertexType;

/**
 * @brief 无权图边为0/1
 * 有权图边有权重，类型为float
 *
 */
typedef int edgetype;

typedef char nodetype;

typedef struct {
    edgetype edges[MAX][MAX];  // 边是否相连，或边权
    int n, e;                  // 顶点个数和边数
    int vex[MAX];              // 相邻矩阵元素合集
} MGraph;

/**
 *
 */
typedef struct ArcNode {
    int vex;               // 该边指向结点的位置
    struct ArcNode *next;  // 下一条边
    /** char type; */      // 边的类型
} ArcNode;

typedef struct {
    nodetype data;   // 顶点
    ArcNode *first;  // 指向第一条边
    int count;       // 边的入度
} VNode;

typedef struct {
    VNode list[MAX];  // 邻接表
    int n, e;         // 顶点数和边数
} AGraph;

/**
 * @brief 全局访问标记数组
 *
 */
void initVisited(int *visited, int n) {
    visited = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) visited[i] = 0;
}
/**
 * @brief 深度优先遍历
 *
 * @param gh 邻接表
 * @param v 节点编号
 * @param visited 已访问标记数组
 */
void DFS(AGraph *gh, int v, int visited[]) {
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", v);
    p = gh->list[v].first;
    while (p) {
        if (visited[p->vex] == 0) DFS(gh, p->vex, visited);
        p = p->next;
    }
}

/**
 * @brief 广度优先遍历
 *
 * @param gh 邻接表
 * @param v 节点编号
 * @param visited 已访问标记数组
 */
void BFS(AGraph *gh, int v, int visited[]) {
    int N = gh->n;
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", v);
    int queue[N], front = 0, rear = 0;
    int j;
    rear = (rear + 1) % N;
    queue[rear] = v;
    while (front != rear) {
        front = (front + 1) % N;
        j = queue[front];
        p = gh->list[j].first;
        while (p) {
            if (visited[p->vex] == 0) {
                printf("%d ", p->vex);
                visited[p->vex] = 1;
                rear = (rear + 1) % N;
                queue[rear] = p->vex;
            }
            p = p->next;
        }
    }
}

/**
 * @brief 非连通图的深度优先搜索遍历
 *
 * @param gh 邻接表
 * @param visited 已访问标记数组
 */
void dfs(AGraph *gh, int visited[]) {
    for (int i = 0; i < gh->n; ++i)
        if (visited[i] == 0) DFS(gh, i, visited);
}

void bfs(AGraph *gh, int visited[]) {
    for (int i = 0; i < gh->n; ++i)
        if (visited[i] == 0) BFS(gh, i, visited);
}
