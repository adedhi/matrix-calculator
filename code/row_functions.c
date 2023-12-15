#include "matrix.h"
#include "row_operations.h"

void rowSwap(Matrix *matrix, int row1, int row2){
    int matrix_size = getSize(*matrix);
    double temp[matrix_size];
    for(int i = 0; i < matrix_size; i++){
        temp[i] = getValue(*matrix, row1, i);
        setValue(matrix, row1, i, getValue(*matrix, row2, i));
        setValue(matrix, row2, i, temp[i]);
    }
}

void rowMultiply(Matrix *matrix, int row, double factor){
    double new_value;
    for(int i = 0; i < getSize(*matrix); i++){
        new_value = (factor * getValue(*matrix, row, i));
        if((-0.005 < new_value) && (new_value <= 0.00)){
            new_value = 0.00;
        }
        setValue(matrix, row, i, new_value);
    }
}

void rowMultiplyAndAdd(Matrix *matrix, int addRow, int multiplyRow, double factor){
    double new_value;
    for(int i = 0; i < getSize(*matrix); i++){
        new_value = (getValue(*matrix, addRow, i) + (factor * getValue(*matrix, multiplyRow, i)));
        if((-0.005 < new_value) && (new_value < 0.00)){
            new_value = 0.00;
        }
        setValue(matrix, addRow, i, new_value);
    }
}