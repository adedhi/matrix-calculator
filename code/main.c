#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void){
    int counter = 0;

    Matrix temp_matrix;
    setSize(&temp_matrix, 2);
    initializeMatrix(&temp_matrix);

    counter = 0;
    for(int i = 0; i < getSize(temp_matrix); i++){
        for(int j = 0; j < getSize(temp_matrix); j++){
            setValue(&temp_matrix, i, j, counter);
            counter++;
        }
    }

    Matrix temp_matrix2;
    setSize(&temp_matrix2, 3);
    initializeMatrix(&temp_matrix2);

    counter = 0;
    for(int i = 0; i < getSize(temp_matrix2); i++){
        for(int j = 0; j < getSize(temp_matrix2); j++){
            setValue(&temp_matrix2, i, j, counter);
            counter++;
        }
    }

    Matrix temp_matrix3;
    setSize(&temp_matrix3, 4);
    initializeMatrix(&temp_matrix3);

    counter = 0;
    for(int i = 0; i < getSize(temp_matrix3); i++){
        for(int j = 0; j < getSize(temp_matrix3); j++){
            setValue(&temp_matrix3, i, j, counter);
            counter++;
        }
    }

    Matrix temp_matrix4;
    setSize(&temp_matrix4, 2);
    initializeMatrix(&temp_matrix4);

    setValue(&temp_matrix4, 0, 0, 5);
    setValue(&temp_matrix4, 0, 1, 232);
    setValue(&temp_matrix4, 1, 0, 4);
    setValue(&temp_matrix4, 1, 1, 0.5);

    Matrix temp_matrix5;
    setSize(&temp_matrix5, 3);
    initializeMatrix(&temp_matrix5);

    setValue(&temp_matrix5, 0, 0, 0);
    setValue(&temp_matrix5, 0, 1, 6);
    setValue(&temp_matrix5, 0, 2, -3);
    setValue(&temp_matrix5, 1, 0, 2);
    setValue(&temp_matrix5, 1, 1, -2);
    setValue(&temp_matrix5, 1, 2, 6);
    setValue(&temp_matrix5, 2, 0, 2);
    setValue(&temp_matrix5, 2, 1, 0);
    setValue(&temp_matrix5, 2, 2, 1);

    printMatrix(temp_matrix);
    printMatrix(temp_matrix2);
    printMatrix(temp_matrix3);
    printMatrix(temp_matrix4);
    printMatrix(temp_matrix5);

    printf("\n%.2lf\n", getDeterminant(temp_matrix));
    printf("\n%.2lf\n", getDeterminant(temp_matrix2));
    printf("\n%.2lf\n", getDeterminant(temp_matrix3));
    printf("\n%.2lf\n", getDeterminant(temp_matrix4));
    printf("\n%.2lf\n", getDeterminant(temp_matrix5));

    printf("\n");

    getREF(temp_matrix4);
    getREF(temp_matrix);
    getREF(temp_matrix5);

    printf("\n");
    
    getRREF(temp_matrix5);
    // getREF(temp_matrix2);
    // getREF(temp_matrix3);

    return 0;
}