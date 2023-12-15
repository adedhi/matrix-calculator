#include "matrix.h"

void initializeMatrix(Matrix *matrix){ // Called after creating a Matrix and setting its size
    int matrix_size = getSize(*matrix);
    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            matrix->values[i][j] = 0;
            matrix->empty_indices[i][j] = 0;
        }
    }
}