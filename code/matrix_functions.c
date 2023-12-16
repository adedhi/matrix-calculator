#include "matrix.h"

int setSize(Matrix *matrix, int size){ // Requires a pointer to the matrix
    if((size == 2) || (size == 3) || (size == 4)){
        matrix->size = size;
        return(1);
    } else{
        return(-1);
    }
}

int setValue(Matrix *matrix, int i, int j, double value){ // Requires a pointer to the matrix
    if(((0 <= i) && (i < getSize(*matrix))) && ((0 <= j) && (j < getSize(*matrix)))){
        matrix->values[i][j] = value;
        return(1);
    } else{
        return(-1);
    }
}

int getSize(Matrix matrix){
    return(matrix.size);
}

double getValue(Matrix matrix, int i, int j){
    if(((0 <= i) && (i < getSize(matrix))) && ((0 <= j) && (j < getSize(matrix)))){
        return(matrix.values[i][j]);
    }
}