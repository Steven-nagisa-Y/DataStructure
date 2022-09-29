#include <stdio.h>

#include "Matrix.h"

int main(int argc, char const *argv[]) {
    Matrix *mat = initMatrix(3, 3);
    setMatrix(mat, 0, 0, 1.0);
    setMatrix(mat, 0, 1, 2.0);
    setMatrix(mat, 0, 2, 3.0);
    setMatrix(mat, 1, 1, 4.0);
    setMatrix(mat, 1, 2, 5.0);
    setMatrix(mat, 2, 2, 6.0);
    printMatrix("3*3 square matrix ", mat);
    Matrix *mat1 = initMatrix(3, 1);
    setMatrix(mat1, 0, 0, 1.0);
    setMatrix(mat1, 1, 0, 1.0);
    setMatrix(mat1, 2, 0, 1.0);
    printMatrix("3*1 row matrix ", mat1);
    Matrix *tranMat = transMatrix(mat);
    printMatrix("transpose matrix ", tranMat);
    Matrix *sumMat = addMatrix(*mat, *tranMat);
    printMatrix("sum of matrix ", sumMat);
    Matrix *multMat = multMatrix(*mat, *mat1);
    printMatrix("multiply of matrix ", multMat);
    return 0;
}
