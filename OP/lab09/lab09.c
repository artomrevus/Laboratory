/*
 Ввести рoзміри матриці n, m, розмістити матрицю в динамічній пам'яті. 
 Для роботи з елементами матриці використати звичайний вказівник. 
 Вивести елементи 2-ого стовпчика матриці на екран.
 */

#include <stdio.h>
#include <stdlib.h>
#include "work_with_dynamic.h"


int main() {
    
    unsigned int n = 0, m = 0;
    printf("Введіть розміри матриці (рядки/стовпці): ");
    scanf("%u/%u", &n, &m);
    
    int ** pMatr = NULL;
    pMatr = (int **) calloc(n, sizeof(int*));
    if(!pMatr)
    {
        printf("ERROR");
        return -1;
    }
    
    for(int i = 0; i < n; i ++){
        pMatr[i] = (int *) calloc(m, sizeof(int));
        if(!pMatr[i])
        {
            printf("ERROR");
            return -1;
        }
    }
    
    scan_elem(pMatr, n, m);
    
    print_second_column(pMatr, n, m);
    
    clean_memory(pMatr, n, m);
   

    return 0;
}
