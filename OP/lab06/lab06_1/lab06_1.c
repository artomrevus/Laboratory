/* Написати функцію, для пошуку максимального елемента в зазначеному рядку двовимірного масиву.
Зсунути в двовимірному масиві всі рядки циклічно вправо на кількість елементів рівну максимальному елементу в цьому рядку. */

#include <stdio.h>
#include "func_shift.h"
#define n 10

int main() {
    do{
        int arr[n][n];
        int arr_i, arr_j, num_row, max;
        printf("Введіть кількість рядків масиву: ");
        scanf("%d", &arr_i);
        
        if(arr_i > n)
        {
            printf("\nХалепа... Надто велика матриця!\n");
            break;
        }
      
        
        printf("\nВведіть кількість стовпців масиву: ");
        scanf("%d", &arr_j);
        printf("\n");
        
        if(arr_j > n)
        {
            printf("\nХалепа... Надто велика матриця!\n");
            break;
        }
       
        scan_arr(arr, arr_i, arr_j);
        printf("\nВаш масив: \n");
        print_arr(arr, arr_i, arr_j);
        
        printf("\nВведіть номер рядка в якому будемо шукати максимальний елемент: ");
        scanf("%d", &num_row);
        num_row-- ;
        
        if(num_row >= arr_i || num_row < 0)
        {
            printf("\nХалепа... Введеного рядка не існує в матриці!\n");
            break;
        }
        
        max = maxx(arr, arr_i, arr_j, num_row);
        printf("\nМаксимальний елемент %d-го рядка = %d\n", num_row+1, max);
        
        teleport(arr, arr_i, arr_j, max);
        
    } while (0);
    return 0;
}
