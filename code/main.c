#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void){
    Matrix user_matrix;
    int user_input = -1;
    int play_flag = 1;

    printf("Welcome, this is a matrix calculator that can calculate the determinant, row echelon form, reduced row echelon form, and inverse of square matrices of dimension 2, 3, or 4.\n\n");
    printf("First, please input the size and values of your matrix:\n");
    getMatrix(&user_matrix);

    while(play_flag == 1){
        printf("\n");
        printf("----------------------------------------------------------\n");
        printMatrix(user_matrix);
        printf("Options\n\t[1]: Print the matrix\n\t[2]: Reset the matrix\n\t[3]: Calculate the Determinant of the matrix\n\t[4]: Calculate the Row Echelon Form of the matrix\n\t[5]: Calculate the Reduced Row Echelon Form of the matrix\n\t[6]: Calculate the Inverse of the matrix\n\t[7]: Exit the program\nPlease make a choice (enter the corresponding number): ");
        while((scanf("%d", &user_input) != 1) || (user_input != 1 && user_input != 2 && user_input != 3 && user_input != 4 && user_input != 5 && user_input != 6 && user_input != 7)){
            printf("Invalid input. Please make a choice by choosing a valid number (1, 2, 3, 4, 5, or 6): ");
            while(getchar() != '\n'){
                continue;
            }
        }

        switch(user_input){
            case 1:
                break;
            case 2:
                printf("\n");
                getMatrix(&user_matrix);
                break;
            case 3:
                printf("\nDeterminant of the matrix: %.2lf\n", getDeterminant(user_matrix));
                break;
            case 4:
                printf("\nRow Echelon Form of the matrix:\n");
                getREF(user_matrix);
                break;
            case 5:
                printf("\nReduced Row Echelon Form of the matrix:\n");
                getRREF(user_matrix);
                break;
            case 6:
                printf("\nInverse of the matrix:\n");
                getInverse(user_matrix);
                break;
            case 7:
                play_flag = 0;
                break;
        }
        printf("\n");
    }

    printf("Thank you for using the matrix calculator.\n");
    printf("~End of Program~\n");


    // Matrix temp_matrix;
    // getMatrix(&temp_matrix);
    // printMatrix(temp_matrix);

    // printf("Determinant of the matrix: %.2lf\n", getDeterminant(temp_matrix));
    // printf("\n");
    // printf("Row Echelon Form of the matrix:\n");
    // getREF(temp_matrix);
    // printf("\n");
    // printf("Reduced Row Echelon Form of the matrix:\n");
    // getRREF(temp_matrix);
    // printf("\n");
    // printf("Inverse of the matrix:\n");
    // getInverse(temp_matrix);

    // int counter = 0;

    // Matrix temp_matrix;
    // initializeMatrix(&temp_matrix, 2);

    // counter = 0;
    // for(int i = 0; i < getSize(temp_matrix); i++){
    //     for(int j = 0; j < getSize(temp_matrix); j++){
    //         setValue(&temp_matrix, i, j, counter);
    //         counter++;
    //     }
    // }

    // Matrix temp_matrix2;
    // initializeMatrix(&temp_matrix2, 3);

    // counter = 0;
    // for(int i = 0; i < getSize(temp_matrix2); i++){
    //     for(int j = 0; j < getSize(temp_matrix2); j++){
    //         setValue(&temp_matrix2, i, j, counter);
    //         counter++;
    //     }
    // }

    // Matrix temp_matrix3;
    // initializeMatrix(&temp_matrix3, 4);

    // counter = 0;
    // for(int i = 0; i < getSize(temp_matrix3); i++){
    //     for(int j = 0; j < getSize(temp_matrix3); j++){
    //         setValue(&temp_matrix3, i, j, counter);
    //         counter++;
    //     }
    // }

    // Matrix temp_matrix4;
    // initializeMatrix(&temp_matrix4, 2);

    // setValue(&temp_matrix4, 0, 0, 5);
    // setValue(&temp_matrix4, 0, 1, 232);
    // setValue(&temp_matrix4, 1, 0, 4);
    // setValue(&temp_matrix4, 1, 1, 0.5);

    // Matrix temp_matrix5;
    // initializeMatrix(&temp_matrix5, 3);

    // setValue(&temp_matrix5, 0, 0, 0);
    // setValue(&temp_matrix5, 0, 1, 6);
    // setValue(&temp_matrix5, 0, 2, -3);
    // setValue(&temp_matrix5, 1, 0, 2);
    // setValue(&temp_matrix5, 1, 1, -2);
    // setValue(&temp_matrix5, 1, 2, 6);
    // setValue(&temp_matrix5, 2, 0, 2);
    // setValue(&temp_matrix5, 2, 1, 0);
    // setValue(&temp_matrix5, 2, 2, 1);

    // printMatrix(temp_matrix);
    // printMatrix(temp_matrix2);
    // printMatrix(temp_matrix3);
    // printMatrix(temp_matrix4);
    // printMatrix(temp_matrix5);

    // printf("\n%.2lf\n", getDeterminant(temp_matrix));
    // printf("\n%.2lf\n", getDeterminant(temp_matrix2));
    // printf("\n%.2lf\n", getDeterminant(temp_matrix3));
    // printf("\n%.2lf\n", getDeterminant(temp_matrix4));
    // printf("\n%.2lf\n", getDeterminant(temp_matrix5));

    // printf("\n");

    // getREF(temp_matrix4);
    // getREF(temp_matrix);
    // getREF(temp_matrix5);

    // printf("\n");
    
    // getRREF(temp_matrix5);
    // // getREF(temp_matrix2);
    // // getREF(temp_matrix3);

    // printf("\n");

    // getInverse(temp_matrix5);

    return 0;
}