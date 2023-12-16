#include <stdio.h>
#include "matrix.h"
#include "row_operations.h"

Matrix getInverse(Matrix matrix){
    if(getDeterminant(matrix) == 0){ // (|A| = 0) => (A is not invertible)
        printf("This matrix is not invertible.\n");
        return(matrix);
    }

    int matrix_size = getSize(matrix);

    Matrix A;
    copyMatrix(matrix, &A);

    Matrix I;
    initializeMatrix(&I, matrix_size);
    for(int i = 0; i < matrix_size; i++){
        setValue(&I, i, i, 1);
    }

    printInverseMatrix(A, I);

    int all_zero;
    double leading_value;
    double curr_value;
    double factor;
    for(int i = 0; i < matrix_size - 1; i++){ // REF
        all_zero = 1; // 0 if all entries in the current column are zero, 1 otherwise
        if(getValue(A, i, i) == 0){
            all_zero = 0;
            for(int j = i + 1; j < matrix_size; j++){ // i = column / j = row
                if(getValue(A, j, i) != 0){
                    rowSwap(&A, j, i);
                    rowSwap(&I, i, j);
                    printf("R%d <-> R%d\n", (i + 1), (j + 1));
                    printInverseMatrix(A, I);
                    all_zero = 1;
                    break;
                }
            }
        }
        if(all_zero == 0){ // All entries in the current column are already zero
            continue;
        }
        leading_value = getValue(A, i, i);
        for(int j = i + 1; j < matrix_size; j++){
            curr_value = getValue(A, j, i);
            if(curr_value != 0){
                factor = ((curr_value * -1) / leading_value);
                rowMultiplyAndAdd(&A, j, i, factor);
                rowMultiplyAndAdd(&I, j, i, factor);
                if(factor < 0){
                    printf("R%d - (%.2lf)R%d\n", (j + 1), (factor * -1), (i + 1));
                } else{
                    printf("R%d + (%.2lf)R%d\n", (j + 1), factor, (i + 1));
                }
            }
        }
        printInverseMatrix(A, I);
    }

    for(int i = 0; i < matrix_size; i++){ // RREF
        for(int j = 0; j < matrix_size; j++){
            curr_value = getValue(A, i, j);
            if((0.005 < curr_value) || (curr_value < -0.005)){
                factor = (1 / curr_value);
                rowMultiply(&A, i, factor);
                rowMultiply(&I, i, factor);
                printf("R%d(%.2lf)\n", i, factor);
                break;
            }
        }
    }
    printInverseMatrix(A, I);

    for(int i = matrix_size - 1; i >= 1; i--){
        for(int j = 0; j < matrix_size; j++){
            leading_value = getValue(A, i, j);
            if(leading_value != 0){
                for(int k = 0; k < j; k++){
                    curr_value = getValue(A, k, j);
                    if(curr_value != 0){
                        factor = ((curr_value * -1) / leading_value);
                        rowMultiplyAndAdd(&A, k, j, factor);
                        rowMultiplyAndAdd(&I, k, j, factor);
                        if(factor < 0){
                            printf("R%d - (%.2lf)R%d\n", (k + 1), (factor * -1), (j + 1));
                        } else{
                            printf("R%d + (%.2lf)R%d\n", (k + 1), factor, (j + 1));
                        }
                    }
                }
                printInverseMatrix(A, I);
                break;
            }
        }
    }

    printMatrix(I);
    return(I);
}