#include "matrix.h"

void initializeMatrix(Matrix matrix){ // Called after creating a Matrix and setting its size
    for(int i = 0; i < matrix.size; i++){
        for(int j = 0; j < matrix.size; j++){
            matrix.empty_indices[i][j] = 0;
        }
    }
}