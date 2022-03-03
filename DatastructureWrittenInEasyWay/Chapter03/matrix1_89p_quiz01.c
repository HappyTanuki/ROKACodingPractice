#include <stdio.h>
#define ROWS 3
#define COLS 3

void MatrixTranspose(int a[ROWS][COLS], int b[ROWS][COLS]){
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            b[c][r] = a[r][c];
        }
    }
}

void MatrixPrint(int a[ROWS][COLS]){
    printf("======================\n");
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            printf("%d ", a[r][c]);
        }
        printf("\n");
    }
    printf("======================\n");
}

void AddMatrix(int matrix_a[ROWS][COLS], int matrix_b[ROWS][COLS], int matrix_c[ROWS][COLS]){
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            matrix_c[r][c] = matrix_a[r][c] + matrix_b[r][c];
        }
    }
}

int main(){
    int array1[ROWS][COLS]  =   {{2, 3, 0},
                                 {8, 9, 1},
                                 {7, 0, 5}};
    int array2[ROWS][COLS];
    int result[ROWS][COLS];

    MatrixTranspose(array1, array2);
    AddMatrix(array1, array2, result);
    MatrixPrint(array1);
    MatrixPrint(array2);
    MatrixPrint(result);

    return 0;
}