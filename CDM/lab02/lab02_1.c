/*
Написати програму, яка реалізує обчислення матриць суміжності графа-доповнення, графа-перетину та графа-об’єднання.

Програма має передбачати такі можливості:
- введення вхідних даних вручну (матриці суміжності);
- реалізацію обчислення та виведення матриць суміжності графа-доповнення, графа-перетину
та графа-об’єднання;
- виведення кількості вершин і ребер вказаних графів;
- перевірку на некоректне введення даних.

*/

#include <stdio.h>
int main() {
    
    int arr_G[8][8] = { // Вхідна матриця суміжності №1
        {0, 1, 0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0, 1, 0}
    };

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(arr_G[i][j] != 0 && arr_G[i][j] != 1)
                printf("Incorrect input! ");
        }
    }
    
    int arr_H[8][8] =  { // Вхідна матриця суміжності №2
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 1},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 0},
        {0},
        {0}
    };
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(arr_H[i][j] != 0 && arr_H[i][j] != 1)
                printf("Incorrect input! ");
        }
    }
    
    int add_G[8][8] = {0};
    printf("Граф-доповнення до графа G:\n\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(arr_G[i][j] == 0 && i != j)
                add_G[i][j] = 1;
            if(arr_G[i][j] == 1)
                add_G[i][j] = 0;
            printf("%d ", add_G[i][j]);
        }
        printf("\n");
    }
    
    int v_add_G = 0, r_add_G = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(add_G[i][j] == 1){
                v_add_G += add_G[i][j];
                break;
            }
        }
        for(int k = 0; k < 8; k ++){
            r_add_G += add_G[i][k];
        }
    }
    r_add_G /= 2;
    
    printf("\nКількість вершин = %d\n", v_add_G);
    printf("Кількість ребер = %d\n", r_add_G);
    
    
    int intersection[8][8] = {0};
    printf("\n\nГраф-перетин G пертинається з H:\n\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            intersection[i][j] = arr_G[i][j] & arr_H[i][j];
            printf("%d ", intersection[i][j]);
        }
        printf("\n");
    }
    
    int v_intersection = 0, r_intersection= 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(intersection[i][j] == 1){
                v_intersection += intersection[i][j];
                break;
            }
        }
        for(int k = 0; k < 8; k ++){
            r_intersection += intersection[i][k];
        }
    }
    r_intersection /= 2;
    
    printf("\nКількість вершин = %d\n", v_intersection);
    printf("Кількість ребер = %d\n", r_intersection);
    
    
    int unionn[8][8] = {0};
    printf("\n\nГраф-об'єднання G U H:\n\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            unionn[i][j] = arr_G[i][j] | arr_H[i][j];
            printf("%d ", unionn[i][j]);
        }
        printf("\n");
    }
    
    int v_union = 0, r_union= 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(unionn[i][j] == 1){
                v_union += unionn[i][j];
                break;
            }
        }
        for(int k = 0; k < 8; k ++){
            r_union += unionn[i][k];
        }
    }
    r_union /= 2;
    
    printf("\nКількість вершин = %d\n", v_union);
    printf("Кількість ребер = %d\n\n", r_union);
    
    return (0);
}
