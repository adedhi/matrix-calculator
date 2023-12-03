#include <stdio.h>
#include "matrix.h"

void printMatrix(Matrix matrix){
    for(int i = 0; i < getSize(matrix); i++){
        for(int j = 0; j < getSize(matrix); j++){
            if(isEmpty(matrix, i, j) == 1){
                printf("%6.2lf\t", getValue(matrix, i, j));
            } else{
                printf("   -  \t");
            }
        }
        printf("\n");
    }
    printf("\n");
}