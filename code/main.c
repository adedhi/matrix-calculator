#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void){
    Matrix temp_matrix;
    temp_matrix.size = 2;
    initializeMatrix(temp_matrix);
    printMatrix(temp_matrix);
    return 0;
}