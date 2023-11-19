#ifndef MATRIX_H
#define MATRIX_H

#define MAX_SIZE 4 // This program accepts square matrices of dimensions 2x2, 3x3, or 4x4

typedef struct{
    int size;
    double values[MAX_SIZE][MAX_SIZE];
    int empty_indices[MAX_SIZE][MAX_SIZE]; // Holds the empty/non-empty states of all indices in the Matrix (have to call initializeMatrix to initialize this)
} Matrix;

void initializeMatrix(Matrix matrix); // Called after creating a Matrix and setting its size

void printMatrix(Matrix matrix);

#endif