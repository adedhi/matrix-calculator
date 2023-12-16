#include <stdio.h>
#include "matrix.h"

void printInverseMatrix(Matrix A, Matrix I){
    int matrix_size = getSize(A);
    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            printf("%6.2lf\t", getValue(A, i, j));
        }
        printf("\t|\t");
        for(int j = 0; j < matrix_size; j++){
            printf("%6.2lf\t", getValue(I, i, j));
        }
        printf("\n");
    }
    printf("\n");
}