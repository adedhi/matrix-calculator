#include <stdio.h>
#include "matrix.h"

void getMatrix(Matrix *matrix){
    int matrix_size;
    int position_counter = 0;
    double position_value;

    printf("Please enter the size of the square matrix (2, 3, or 4): ");
    while((scanf("%d", &matrix_size) != 1) || (matrix_size != 2 && matrix_size != 3 && matrix_size != 4)){
        printf("Invalid input. Please enter the size of the square matrix (2, 3, or 4): ");
        while(getchar() != '\n'){
            continue;
        }
    }

    printf("\nInitializing a matrix of size [%d]\n", matrix_size);
    initializeMatrix(matrix, matrix_size);

    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            printf("\n");
            printInputMatrix(*matrix, position_counter);
            printf("Enter the value of position (a%d%d): ", (i + 1), (j + 1));
            while(scanf("%lf", &position_value) != 1){
                printf("Invalid input. Please enter the value of position (a%d%d): ", (i + 1), (j + 1));
                while(getchar() != '\n'){
                    continue;
                }
            }
            setValue(matrix, i, j, position_value);
            position_counter++;
        }
    }

    printMatrix(*matrix);
}