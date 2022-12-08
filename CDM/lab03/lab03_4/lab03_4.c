/*

Написати програму, яка реалізує обчислення матриць перетину, об’єднання, різниці, симетричної різниці, 
доповнення, обернених, композицій двох бінарних відношень, заданих на множині А = {a, b, c}. 

Програма має передбачати такі можливості:
- введення вхідних даних вручну (задання відношень матрицями);
- реалізацію обчислення та виведення матриць перетину, об’єднання, різниці, симетричної
різниці, доповнення, обернених, композицій двох бінарних відношень; 
- перевірку на некоректне введення даних.

*/

#include <stdio.h>
#define SIZE 3
int main() {
    
    int arr_R1[SIZE][SIZE] = { // Вхідна матриця №1
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(arr_R1[i][j] != 0 && arr_R1[i][j] != 1)
                printf("Incorrect input! ");
        }
    }
    
    int arr_R2[SIZE][SIZE] = { // Вхідна матриця №2
        {1, 1, 1},
        {1, 1, 1},
        {1, 0, 1}
    };
    
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(arr_R2[i][j] != 0 && arr_R2[i][j] != 1)
                printf("Incorrect input! ");
        }
    }
    
    int add_R1[SIZE][SIZE] = {0};
    printf("Матриця-доповнення до R1:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(arr_R1[i][j] == 0 && i != j)
                add_R1[i][j] = 1;
            if(arr_R1[i][j] == 1)
                add_R1[i][j] = 0;
            printf("%d ", add_R1[i][j]);
        }
        printf("\n");
    }
    
    
    int add_R2[SIZE][SIZE] = {0};
    printf("\nМатриця-доповнення до R2:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(arr_R2[i][j] == 0 && i != j)
                add_R2[i][j] = 1;
            if(arr_R2[i][j] == 1)
                add_R2[i][j] = 0;
            printf("%d ", add_R2[i][j]);
        }
        printf("\n");
    }
    
    
    
    int intersection[SIZE][SIZE] = {0};
    printf("\nПеретин R1 з R2:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            intersection[i][j] = arr_R1[i][j] & arr_R2[i][j];
            printf("%d ", intersection[i][j]);
        }
        printf("\n");
    }
    
    
    int unionn[SIZE][SIZE] = {0};
    printf("\nOб'єднання R1 U R2:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            unionn[i][j] = arr_R1[i][j] | arr_R2[i][j];
            printf("%d ", unionn[i][j]);
        }
        printf("\n");
    }
    
    
    int difference[SIZE][SIZE] = {0};
    printf("\nРізниця R1 / R2:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(arr_R1[i][j] == 1 && arr_R2[i][j] == 0)
            {
                difference[i][j] = 1;
            }
        
        
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }
    
    int difference_2[SIZE][SIZE] = {0};
    printf("\nРізниця R2 / R1:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(arr_R2[i][j] == 1 && arr_R1[i][j] == 0)
            {
                difference_2[i][j] = 1;
            }
        
        
            printf("%d ", difference_2[i][j]);
        }
        printf("\n");
    }
    
    
    int s_difference[SIZE][SIZE] = {0};
    printf("\nСиметрична різниця R1 ∆ R2:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            s_difference[i][j] = arr_R1[i][j] ^ arr_R2[i][j];
            printf("%d ", s_difference[i][j]);
        }
        printf("\n");
    }
    
    
    int transp[SIZE][SIZE] = {0};
    printf("\nОбернена матриця R1:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            transp[i][j] = arr_R1[j][i];
            printf("%d ", transp[i][j]);
        }
        printf("\n");
    }
     
    int transp_2[SIZE][SIZE] = {0};
    printf("\nОбернена матриця R2:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            transp_2[i][j] = arr_R2[j][i];
            printf("%d ", transp_2[i][j]);
        }
        printf("\n");
    }
    
    int composition[SIZE][SIZE] = {0};
    printf("\nКомпозиція R1°R2:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < SIZE; k++){
                composition[i][j] |= arr_R1[k][j] * arr_R2[i][k];
                
            }
        }
    }
    
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d ", composition[i][j]);
        }
        printf("\n");
    }
    
    int composition_2[SIZE][SIZE] = {0};
    printf("\nКомпозиція R2°R1:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < SIZE; k++){
                composition_2[i][j] |= arr_R2[k][j] * arr_R1[i][k];
                
            }
        }
    }
    
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d ", composition_2[i][j]);
        }
        printf("\n");
    }
    
    return (0);
}
