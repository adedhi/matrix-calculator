#include "matrix.h"

void initializeMatrix(Matrix *matrix, int size){ // Called after creating a Matrix and setting its size
    setSize(matrix, size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix->values[i][j] = 0;
        }
    }
}