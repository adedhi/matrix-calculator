#include "matrix.h"

Matrix copyMatrix(Matrix originalMatrix, Matrix *newMatrix){
    int matrix_size = getSize(originalMatrix);
    setSize(newMatrix, matrix_size);
    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            newMatrix->values[i][j] = getValue(originalMatrix, i, j);
            newMatrix->empty_indices[i][j] = isEmpty(originalMatrix, i, j);
        }
    }
}