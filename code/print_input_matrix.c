#include <stdio.h>
#include "matrix.h"

void printInputMatrix(Matrix matrix, int next_position){
    int position_counter = 0;
    int matrix_size = getSize(matrix);
    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            if(position_counter < next_position){
                printf("%6.2lf\t", getValue(matrix, i, j));
            } else if(position_counter == next_position){
                printf("%6c\t", 'X');
            } else{
                printf("%6c\t", '-');
            }
            position_counter++;
        }
        printf("\n");
    }
    printf("\n");
}