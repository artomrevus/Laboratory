/*
Написати програму, яка реалізує обчислення матриці досяжності орграфа G двома способами: за допомогою піднесення до степеня матриці суміжності та алгоритму Воршелла згідно зі своїм варіантом.

Програма має передбачати такі можливості:
- реалізацію введення структури графа за допомогою побудови матриці суміжності;
- реалізавцію обчислення та виведення різних степенів матриці суміжності графа та матриці
досяжності;
- відповідно до свого варіанту реалізацію алгоритму Воршелла для обчислення та виведеннч
матриці досяжності;
- перевірку на некоректне введення даних.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void multiplication_6x6(int matrix_1[6][6], int matrix_2[6][6], int return_matrix[6][6], char matrix_num){
    for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                return_matrix[i][j] = 0;
                for (int k = 0; k < 6; k++)
                    return_matrix[i][j] |= matrix_1[k][j] * matrix_2[i][k];
            }
        }
    
    printf("\n      M%c: \n\n", matrix_num);
    for(int i = 0; i < 6; i++){
        printf("| ");
        for (int j = 0; j < 6; j++) {
            printf("%d ", return_matrix[i][j]);
        }
        printf("|\n");
    }
}

void print_matrix(int matrix[6][6], char matrix_name, char matrix_num){
    printf("\n      %c%c: \n\n", matrix_name, matrix_num);
    for(int i = 0; i < 6; i++){
        printf("| ");
        for (int j = 0; j < 6; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }
}

void vorshell(int matrix[6][6], char vorshell_step_num){
    
    int n = atoi(&vorshell_step_num);
    for (int i = 0; i < 6; i++) {
        if(matrix[i][n-1] == 1)
        {
            for(int k = 0; k < 6; k++){
                matrix[i][k] |= matrix[n-1][k];
            }
        }
        else
            continue;;
    }
    
    print_matrix(matrix, 'W', vorshell_step_num);
    
}


int main(void)
{
  
    int M[6][6] = {
        {0, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(M[i][j] != 1 && M[i][j] != 0){
                printf("Incorrect input!");
                return 0;
            }
        }
    }
    
    int Mx[6][6] = {0};
    int M_star[6][6] = {0};
    
    
    print_matrix(M, 'M', '1');
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++){
            M_star[i][j] |= M[i][j];
        }
    }
    
    multiplication_6x6(M, M, Mx, '2');
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++){
            M_star[i][j] |= Mx[i][j];
        }
    }
    
    multiplication_6x6(Mx, M, Mx, '3');
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++){
            M_star[i][j] |= Mx[i][j];
        }
    }
    
    multiplication_6x6(Mx, M, Mx, '4');
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++){
            M_star[i][j] |= Mx[i][j];
        }
    }
    
    multiplication_6x6(Mx, M, Mx, '5');
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++){
            M_star[i][j] |= Mx[i][j];
        }
    }
    
    multiplication_6x6(Mx, M, Mx, '6');
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++){
            M_star[i][j] |= Mx[i][j];
        }
    }
    
    print_matrix(M_star, 'M', '*');

    printf("\n\n---------------\n\n");

    print_matrix(M, 'W', '0');
    

    vorshell(M, '1');
    vorshell(M, '2');
    vorshell(M, '3');
    vorshell(M, '4');
    vorshell(M, '5');
    vorshell(M, '6');
    
    return 0;
}
