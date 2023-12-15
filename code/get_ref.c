#include <stdio.h>
#include "matrix.h"
#include "row_operations.h"

Matrix getREF(Matrix matrix){
    Matrix temp;
    copyMatrix(matrix, &temp);
    int matrix_size = getSize(temp);
    printMatrix(temp);

    
    int all_zero;
    double leading_value;
    double curr_value;
    double factor;

    for(int i = 0; i < matrix_size; i++){
        all_zero = 1; // 0 if all entries in the current column are zero, 1 otherwise
        if(getValue(temp, i, i) == 0){
            all_zero = 0;
            for(int j = i + 1; j < matrix_size; j++){ // i = column / j = row
                if(getValue(temp, j, i) != 0){
                    rowSwap(&temp, j, i);
                    printf("R%d <-> R%d\n", (i + 1), (j + 1));
                    printMatrix(temp);
                    all_zero = 1;
                    break;
                }
            }
        }

        if(all_zero == 0){ // All entries in the current column are already zero
            continue;
        }
        leading_value = getValue(temp, i, i);
        for(int j = i + 1; j < matrix_size; j++){
            curr_value = getValue(temp, j, i);
            if(curr_value != 0){
                factor = ((curr_value * -1) / leading_value);
                rowMultiplyAndAdd(&temp, j, i, factor);
                if(factor < 0){
                    printf("R%d - (%.2lf)R%d\n", (j + 1), (factor * -1), (i + 1));
                } else{
                    printf("R%d + (%.2lf)R%d\n", (j + 1), factor, (i + 1));
                }
            }
        }
        printMatrix(temp);
    }

    return(temp);
}