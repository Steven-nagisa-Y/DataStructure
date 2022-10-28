#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int **createMatrix(int n) {
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) matrix[i] = (int *)malloc(sizeof(int) * n);
    return matrix;
}

void Floyd(MGraph *G, int **Path, int **A) {
    int i, j, k;
    for (i = 0; i < G->n; ++i)
        for (j = 0; j < G->n; ++j) {
            A[i][j] = G->edges[i][j];
            Path[i][j] = -1;
        }
    // 主要循环
    for (k = 0; k < G->n; ++k)
        for (i = 0; i < G->n; ++i)
            for (j = 0; j < G->n; ++j)
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    Path[i][j] = k;
                }
}

void printPath(int u, int v, int **Path, int **A) {
    if (A[u][v] > MAX) return;
    if (Path[u][v] == -1)
        printf("%d - %d\n", u, v);
    else {
        int mid = Path[u][v];
        printPath(u, mid, Path, A);
        printPath(mid, v, Path, A);
    }
}

int main(int argc, char const *argv[]) {
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
            if (j != i) {
                int tmp;
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
    printf("A:\n");
    int **A = createMatrix(N);
    int **Path = createMatrix(N);
    Floyd(G, Path, A);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) printf("\t%d", A[i][j]);
        printf("\n");
    }
    int u, v;
    printf("Input path i j: ");
    scanf("%d %d", &u, &v);
    printPath(u, v, Path, A);
    return 0;
}
