#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxSize 999

/**
 * @brief 二维矩阵定义
 *
 */
typedef struct {
    double **mat;
    int m;
    int n;
} Matrix;

/**
 * @brief 三元组矩阵定义
 *
 */
typedef struct {
    double val;
    int i, j;
} TriMat;

Matrix *initMatrix(int m, int n) {
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->mat = (double **)malloc(sizeof(double *) * m);
    for (int i = 0; i < m; ++i) {
        mat->mat[i] = (double *)malloc(sizeof(double) * n);
        for (int j = 0; j < n; ++j) {
            mat->mat[i][j] = 0.0;
        }
    }
    mat->m = m;
    mat->n = n;
    return mat;
}

void freeMatrix(Matrix *matrix) {
    if (matrix == NULL) printf("NULL\n");
    for (int i = 0; i < matrix->m; ++i) free(matrix->mat[i]);
    free(matrix->mat);
    matrix->m = 0;
    matrix->n = 0;
}

bool setMatrix(Matrix *mat, int m, int n, double val) {
    if (m < 0 || m > mat->m || n < 0 || n > mat->n) return false;
    mat->mat[m][n] = val;
}

Matrix *transMatrix(Matrix *mat) {
    Matrix *newM = initMatrix(mat->m, mat->n);
    for (int i = 0; i < mat->m; ++i)
        for (int j = 0; j < mat->n; ++j) newM->mat[j][i] = mat->mat[i][j];
    newM->m = mat->n;
    newM->n = mat->m;
    return newM;
}

void printMatrix(char *msg, Matrix *mat) {
    if (msg) printf("%s", msg);
    if (mat == NULL) {
        printf("NULL\n");
        return;
    }
    printf("[%d * %d]\n", mat->m, mat->n);
    for (int i = 0; i < mat->m; ++i) {
        for (int j = 0; j < mat->n; ++j) printf("%lf ", mat->mat[i][j]);
        printf("\n");
    }
}

Matrix *addMatrix(Matrix m1, Matrix m2) {
    if (m1.m != m2.m || m1.n != m2.n) return NULL;
    Matrix *m3 = initMatrix(m1.m, m1.n);
    for (int i = 0; i < m1.m; ++i)
        for (int j = 0; j < m1.n; ++j)
            m3->mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
    return m3;
}

Matrix *multMatrix(Matrix m1, Matrix m2) {
    if (m1.n != m2.m) return NULL;
    Matrix *m3 = initMatrix(m1.m, m2.n);
    for (int i = 0; i < m1.m; ++i)
        for (int j = 0; j < m2.n; ++j) {
            for (int k = 0; k < m2.m; ++k) {
                m3->mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
            }
        }
    return m3;
}

TriMat *createTrimat(Matrix *m) {
    TriMat *trimat = (TriMat *)malloc(sizeof(TriMat) * m->m * m->n);
    int c = 1;
    for (int i = 0; i < m->m; ++i)
        for (int j = 0; i < m->n; ++j) {
            if (m->mat[i][j] != 0) {
                trimat[c].val = m->mat[i][j];
                trimat[c].i = i;
                trimat[c].j = j;
                ++c;
            }
        }
    trimat[0].val = c - 1;
    trimat[0].i = m->m;
    trimat[0].j = m->n;
    return trimat;
}

void printTrimat(TriMat *trimat) {
    int c = 1;
    for (int i = 0; i < trimat[0].i; ++i) {
        for (int j = 0; j < trimat[0].j; ++j) {
            if (i == trimat[c].i && j == trimat[c].j) {
                printf("%lf ", trimat[c].val);
                ++c;
            } else
                printf("%lf ", 0);
        }
    }
    printf("\n");
}