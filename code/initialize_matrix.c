#include "matrix.h"

void initializeMatrix(Matrix *matrix){ // Called after creating a Matrix and setting its size
    for(int i = 0; i < getSize(*matrix); i++){
        for(int j = 0; j < getSize(*matrix); j++){
            matrix->values[i][j] = 0;
            matrix->empty_indices[i][j] = 0;
        }
    }
}