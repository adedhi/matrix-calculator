#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void){
    Matrix temp_matrix;
    temp_matrix.size = 2;
    initializeMatrix(temp_matrix);

    for(int i = 0; i < temp_matrix.size; i++){
        for(int j = 0; j < temp_matrix.size; j++){
            temp_matrix.values[i][j] = (i + j);
            temp_matrix.empty_indices[i][j] = 1;
        }
    }

    Matrix temp_matrix_2;
    temp_matrix_2.size = 3;
    initializeMatrix(temp_matrix_2);

    for(int i = 0; i < temp_matrix_2.size; i++){
        for(int j = 0; j < temp_matrix_2.size; j++){
            if(i == j){
                continue;
            }
            temp_matrix_2.values[i][j] = (i + j);
            temp_matrix_2.empty_indices[i][j] = 1;
        }
    }

    temp_matrix.values[0][0] = 10.00;

    printMatrix(temp_matrix);
    printMatrix(temp_matrix_2);
    return 0;
}