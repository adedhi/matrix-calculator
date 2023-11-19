#include <stdio.h>
#include "matrix.h"

void printMatrix(Matrix matrix){
    for(int i = 0; i < matrix.size; i++){
        for(int j = 0; j < matrix.size; j++){
            printf("%.2f\t", matrix.values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}