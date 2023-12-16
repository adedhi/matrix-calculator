#include <stdio.h>
#include "matrix.h"

void printMatrix(Matrix matrix){
    int matrix_size = getSize(matrix);
    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            printf("%6.2lf\t", getValue(matrix, i, j));
        }
        printf("\n");
    }
    printf("\n");
}