#include <stdio.h>
#include "matrix.h"

void printMatrix(Matrix matrix){
    for(int i = 0; i < matrix.size; i++){
        for(int j = 0; j < matrix.size; j++){
            if(matrix.empty_indices[i][j] == 1){
                printf("%6.2f\t", matrix.values[i][j]);
            } else{
                printf("   -  \t");
            }
        }
        printf("\n");
    }
    printf("\n");
}