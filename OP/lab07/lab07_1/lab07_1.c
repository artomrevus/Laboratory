/* Використовуючи функції swap та qs_sort, які реалізують алгоритм швидкого сортування масиву, 
написати програму мовою С для порівняння ефективності алгоритмів сортування масивів великих обсягів 
(наприклад, 100000 елементів). Написати сортування в порядку спадання “бульбашковим” методом без додаткової 
перевірки чи масив вже відсортований. У програмі використати два одинакових масиви, які заповнити випадковими числами, 
здійснити перевірку впорядкованості елементів масиву, перевірку ідентичності масивів до і після сортування, а також
за допомогою стандартної функції time, оцінити час виконання реалізованих алгоритмів сортування. */

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000

int main() {

    clock_t start_time_1 = 0, end_time_1 = 0, start_time_2 = 0, end_time_2 = 0;
    srand(time(NULL));
    
    int array_1[SIZE];
    int array_2[SIZE];
    for(int i = 0; i < SIZE; i++){
        array_1[i] = rand()%100;
        array_2[i] = array_1[i];
    }
    printf("До сортування: \n");
    printf("array_1: ");
    arrange_check(array_1, SIZE);
    printf("array_2: ");
    arrange_check(array_2, SIZE);
    array_equal(array_1, array_2, SIZE);
    
    start_time_1 = clock();
    qs_sort(array_1, 0, SIZE-1);
    end_time_1 = clock();
    
    start_time_2 = clock();
    bubble_sort(array_2, SIZE);
    end_time_2 = clock();
    
    
    printf("\nПісля сортування: \n");
    printf("array_1: ");
    arrange_check(array_1, SIZE);
    printf("array_2: ");
    arrange_check(array_2, SIZE);
    array_equal(array_1, array_2, SIZE);
    
    printf("\nЧас, затрачений на сортування функцією qs_sort = %.5lf сек. Час, затрачений на сортування бульбашкою  = %.5lf сек. ", (double)(end_time_1-start_time_1)/CLOCKS_PER_SEC , (double)(end_time_2-start_time_2)/CLOCKS_PER_SEC);
    
    return 0;
}
