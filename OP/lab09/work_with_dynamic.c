#include <stdlib.h>
#include "work_with_dynamic.h"

void scan_elem(int ** pMatr, int n, int m){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(pMatr && pMatr[i])
            {
                printf("Введіть елемент матриці, який знаходиться на перетині %u рядка та %u стовпця: ", i+1, j+1);
                scanf("%d", (pMatr[i]+j));
            }
        }
    }
}


void print_second_column(int ** pMatr, int n, int m){
    printf("Eлементи 2-ого стовпчика матриці: ");
        for(int i = 0; i < n; i ++){
            printf("%d ", *(pMatr[i]+1));
        }
    printf("\n");
}


void clean_memory(int ** pMatr, int n, int m){
    for(int i = 0; i < n; i ++){
        if(pMatr && pMatr[i])
        {
            free(pMatr[i]);
        }
    }
    
    if(pMatr)
    {
        free(pMatr);
    }
    pMatr = NULL;
}


