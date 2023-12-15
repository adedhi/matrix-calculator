#include <stdio.h>
#include "matrix.h"
#include "row_operations.h"

Matrix getRREF(Matrix matrix){
    Matrix temp = getREF(matrix);
    int matrix_size = getSize(temp);

    double curr_value;
    double factor;
    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            curr_value = getValue(temp, i, j);
            if((0.005 < curr_value) || (curr_value < -0.005)){
                factor = (1 / curr_value);
                rowMultiply(&temp, i, factor);
                printf("R%d(%.2lf)\n", i, factor);
                break;
            }
        }
    }
    printMatrix(temp);

    double leading_value;
    for(int i = matrix_size - 1; i >= 0; i--){
        for(int j = 0; j < matrix_size; j++){
            leading_value = getValue(temp, i, j);
            if(leading_value != 0){
                for(int k = 0; k < j; k++){
                    curr_value = getValue(temp, k, j);
                    if(curr_value != 0){
                        factor = ((curr_value * -1) / leading_value);
                        rowMultiplyAndAdd(&temp, k, j, factor);
                        if(factor < 0){
                            printf("R%d - (%.2lf)R%d\n", (k + 1), (factor * -1), (j + 1));
                        } else{
                            printf("R%d + (%.2lf)R%d\n", (k + 1), factor, (j + 1));
                        }
                    }
                }
                printMatrix(temp);
                break;
            }
        }
    }

    return(temp);
}