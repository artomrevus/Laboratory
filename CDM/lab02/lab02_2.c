/*
Написати програму, яка реалізує алгоритм найближчого сусіда для пошуку ГЦ у зваженому графі, взявши за вихідну вершину 1.

Програма має передбачати такі можливості:
- введення вхідних даних вручну (вагова матриця);
- реалізацію алгоритму найближчого сусіда для пошуку ГЦ;
- виведення на екран вершин побудованого ГЦ та його довжини; 
- перевірку на некоректне введення даних.

*/

#include <stdio.h>
#include <ctype.h>
int main() {
    int matrix[8][8] = {
        {0, 7, 6, 5, 4, 3, 2, 1},
        {7, 0, 1, 5, 6, 4, 2, 3},
        {6, 1, 0, 1, 5, 6, 2, 3},
        {5, 5, 1, 0, 3, 2, 2, 2},
        {4, 6, 5, 3, 0, 2, 2, 2},
        {3, 4, 6, 2, 2, 0, 5, 5},
        {2, 2, 2, 2, 2, 5, 0, 2},
        {1, 3, 3, 2, 2, 5, 2, 0}
    };
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(matrix[i][j] < 0 || isalpha(matrix[i][j]))
                printf("Incorrect input! ");
        }
    }
    
    int first_j = 1;
    int min_1 = matrix[0][1];
        for(int j = 0; j < 8; j++){
            if(matrix[0][j] < min_1 && j != 0){
                min_1 = matrix[0][j];
                first_j = j;
            }
        }
    
    int second_j = 0;
    int min_2 = 0;
    for(int j = 0; j < 8; j++){
        if(j != 0 && j != first_j){
            min_2 = matrix[first_j][j];
            second_j = j;
            break;
        }
    }
        for(int j = 0; j < 8; j++){
            if(matrix[first_j][j] < min_2 && j != 0 && j != first_j){
                min_2 = matrix[first_j][j];
                second_j = j;
            }
        }
    
    int thirt_j = 0;
    int min_3 = 0;
    for(int j = 0; j < 8; j++){
        if(j != 0 && j != first_j && j != second_j){
            min_3 = matrix[second_j][j];
            thirt_j = j;
            break;
        }
    }
        for(int j = 0; j < 8; j++){
            if(matrix[second_j][j] < min_3 && j != 0 && j != first_j && j != second_j){
                min_3 = matrix[second_j][j];
                thirt_j = j;
            }
        }
    
    int fourth_j = 0;
    int min_4 = 0;
    for(int j = 0; j < 8; j++){
        if(j != 0 && j != first_j && j != second_j && j != thirt_j){
            min_4 = matrix[thirt_j][j];
            fourth_j = j;
            break;
        }
    }
        for(int j = 0; j < 8; j++){
            if(matrix[thirt_j][j] < min_4 && j != 0 && j != first_j && j != second_j && j != thirt_j){
                min_4 = matrix[thirt_j][j];
                fourth_j = j;
            }
        }
    
    
    int fifth_j = 0;
    int min_5 = 0;
    for(int j = 0; j < 8; j++){
        if(j != 0 && j != first_j && j != second_j && j != thirt_j && j != fourth_j){
            min_5 = matrix[fourth_j][j];
            fifth_j = j;
            break;
        }
    }
        for(int j = 0; j < 8; j++){
            if(matrix[fourth_j][j] < min_5 && j != 0 && j != first_j && j != second_j && j != thirt_j && j != fourth_j){
                min_5 = matrix[fourth_j][j];
                fifth_j = j;
            }
        }

    
    
    int six_j = 0;
    int min_6 = 0;
    for(int j = 0; j < 8; j++){
        if(j != 0 && j != first_j && j != second_j && j != thirt_j && j != fourth_j && j != fifth_j){
            min_6 = matrix[fifth_j][j];
            six_j = j;
            break;
        }
    }
        for(int j = 0; j < 8; j++){
            if(matrix[fifth_j][j] < min_6 && j != 0 && j != first_j && j != second_j && j != thirt_j && j != fourth_j && j != fifth_j){
                min_6 = matrix[fifth_j][j];
                six_j = j;
            }
        }

    
    int seven_j = 0;
    int min_7 = 0;
    for(int j = 0; j < 8; j++){
        if(j != 0 && j != first_j && j != second_j && j != thirt_j && j != fourth_j && j != fifth_j && j != six_j){
            min_7 = matrix[six_j][j];
            seven_j = j;
            break;
        }
    }
        for(int j = 0; j < 8; j++){
            if(matrix[six_j][j] < min_7 && j != 0 && j != first_j && j != second_j && j != thirt_j && j != fourth_j && j != fifth_j && j != six_j){
                min_7 = matrix[six_j][j];
                seven_j = j;
            }
        }
    
    
    int eight_j = 0;
    int min_8 = 0;
    for(int j = 0; j < 8; j++){
        if(j != first_j && j != second_j && j != thirt_j && j != fourth_j && j != fifth_j && j != six_j && j != seven_j){
            min_8 = matrix[seven_j][j];
            eight_j = j;
            break;
        }
    }
        for(int j = 0; j < 8; j++){
            if(matrix[seven_j][j] < min_7 && j != first_j && j != second_j && j != thirt_j && j != fourth_j && j != fifth_j && j != six_j && j != seven_j){
                min_8 = matrix[seven_j][j];
                eight_j = j;
            }
        }
    
    int dow = min_1 + min_2 + min_3 + min_4 + min_5 + min_6 + min_7 + min_8;
    
    printf("ГЦ: 1 - %d - %d - %d - %d - %d - %d - %d - %d\n", first_j+1, second_j+1, thirt_j+1, fourth_j+1, fifth_j+1, six_j+1, seven_j+1, eight_j+1);
    printf("Довжина циклу = %d\n\n", dow);
    return 0;
}
