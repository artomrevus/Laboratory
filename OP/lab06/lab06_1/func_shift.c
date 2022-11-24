#include "func_shift.h"
#include <stdio.h>
#define n 10

void scan_arr(int arr[n][n], int arr_i, int arr_j){
    for(int i = 0; i < arr_i; i++){
        for(int j = 0; j < arr_j; j++){
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_arr(int arr[n][n], int arr_i, int arr_j){
    printf("\n");
    for(int i = 0; i < arr_i; i++){
        for(int j = 0; j < arr_j; j++){
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

int maxx(int arr[n][n], int arr_i, int arr_j , int num_row){
    int max = arr[num_row][0];
    for(int j = 1; j < arr_j; j++){
        if(arr[num_row][j] > max)
        {
            max = arr[num_row][j];
        }
    }
    return max;
}

void teleport(int arr[n][n], int arr_i, int arr_j, int max){
    
        max %= arr_j;
        for(int k = 0; k < max; k++){
            for(int i = 0; i < arr_i; i ++){
                for(int j = arr_j - 1; j > 0; j --){
                    int tmp = arr[i][j];
                    arr[i][j] = arr[i][j-1];
                    arr[i][j-1] = tmp;
                }
            }
        }
    printf("\nЗсунутий масив: \n");
    print_arr(arr, arr_i, arr_j);
    printf("\n");
}
