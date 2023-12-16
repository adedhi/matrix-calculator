#include "matrix.h"

double getDeterminant(Matrix matrix){
    double determinant = 0.0;
    Matrix temp_matrix;
    int row_index = 0, column_index = 0;

    switch(getSize(matrix)){
        case 2: // Determinant of a 2x2 matrix = ad - bc
            determinant = (getValue(matrix, 0, 0) * getValue(matrix, 1, 1)) - (getValue(matrix, 0, 1) * getValue(matrix, 1, 0));
            break;

        case 3: // Recursively calls getDeterminant on 2x2 matrices
            initializeMatrix(&temp_matrix, 2);

            for(int n = 0; n < 3; n++){
                row_index = 0, column_index = 0;
                for(int i = 0; i < 3; i++){
                    if(i != n){
                        for(int j = 1; j < 3; j++){
                            if(j != 0){
                                setValue(&temp_matrix, row_index, column_index, getValue(matrix, i, j));
                                if(column_index < 1){
                                    column_index++;
                                } else{
                                    column_index = 0;
                                    row_index++;
                                }
                            }
                        }
                    }
                }

                if(n % 2 == 0){
                    determinant += (getValue(matrix, n, 0) * 1 * getDeterminant(temp_matrix));
                } else{
                    determinant += (getValue(matrix, n, 0) * -1 * getDeterminant(temp_matrix));
                }
            }
            break;

        case 4: // Recursively calls getDeterminant on 3x3 matrices
            initializeMatrix(&temp_matrix, 3);

            for(int n = 0; n < 4; n++){
                row_index = 0, column_index = 0;
                for(int i = 0; i < 4; i++){
                    if(i != n){
                        for(int j = 1; j < 4; j++){
                            if(j != 0){
                                setValue(&temp_matrix, row_index, column_index, getValue(matrix, i, j));
                                if(column_index < 2){
                                    column_index++;
                                } else{
                                    column_index = 0;
                                    row_index++;
                                }
                            }
                        }
                    }
                }

                if(n % 2 == 0){
                    determinant += (getValue(matrix, n, 0) * 1 * getDeterminant(temp_matrix));
                } else{
                    determinant += (getValue(matrix, n, 0) * -1 * getDeterminant(temp_matrix));
                }
            }
            break;

        default: // Not a 2x2, 3x3, or 4x4 matrix
            determinant = -1;
    }
    return determinant;
}