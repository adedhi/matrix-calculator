#ifndef MATRIX_H
#define MATRIX_H

#define MAX_SIZE 4 // This program accepts square matrices of dimensions 2x2, 3x3, or 4x4

typedef struct{
    int size;
    double values[MAX_SIZE][MAX_SIZE];
} Matrix;

void printMatrix(Matrix matrix);

#endif