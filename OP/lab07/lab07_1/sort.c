#include "sort.h"
#include <stdio.h>
#define SIZE 10

void swap(int array[], long pos1, long pos2)
{
    long tmp;
    tmp=array[pos1];
    array[pos1]=array[pos2];
    array[pos2]=tmp;
}

void qs_sort(int array[], long start, long end)
{
    long head=start, tail=end-1;
    long diff=end-start;
    long pe_index;
    // якщо залишилося менше двох елементів – кінець рекурсії
    if (diff<1) return;
    if (diff==1)
        if (array[start]>array[end]) {
            swap(array, start, end);
            return;
        }
    // пошук індексу розділяючого елементу pe_index
    long m=(start+end)/2;
    if (array[start]<=array[m]) {
        if (array[m]<=array[end]) pe_index=m;
        else if (array[end]<=array[start]) pe_index=start;
        else pe_index=end;
    }
    else {
        if (array[start]<=array[end]) pe_index=start;
        else if(array[end]<=array[m]) pe_index=m;
        else pe_index=end;
    }
    long pe=array[pe_index]; // сам розділяючий елемент
    swap(array,pe_index,end);
    while (1) {
        while(array[head]<pe)
            ++head;
        while(array[tail]>pe && tail>start)
            --tail;
        if (head>=tail) break;
        swap(array,head++, tail--);
    }
    swap(array,head,end);
    long mid=head;
    qs_sort(array, start, mid-1); // рекурсивний виклик для 1-ої підмножини
    qs_sort(array, mid+1, end); // рекурсивний виклик для 2-ої підмножини
}


void bubble_sort(int array[], int size){
    for(int i = 0; i < size; i ++){
        for (int k = 1; k < size; k ++) {
            if(array[k] > array[k-1])
                swap(array, k, k-1);
        }
    }
}


void arrange_check(int array[], int size){
    int decrease = 1;
    for(int i = 1; i < size; i++){
        if(array[i]>array[i-1])
        {
            decrease = 0;
        }
    }
    if(decrease == 1)
    {
        printf("Елементи масиву впорядковані в порядку спадання!\n");
    }
    
    int increase = 1;
    for(int i = 1; i < size; i++){
        if(array[i]<array[i-1])
        {
            increase = 0;
        }
    }
    
    if(increase == 1)
    {
        printf("Елементи масиву впорядковані в порядку зростання!\n");
    }
    
    if(increase == 0 && decrease == 0)
    {
        printf("Елементи масиву не впорядковані ні в порядку зростання, ні в порядку спадання!\n");
    }
}

void array_equal(int array_1[], int * array_2, int size){
    int equal = 1;
    for(int i = 1; i < size; i++){
        if(array_1[i] != array_2[i])
        {
            equal = 0;
        }
    }
    
    if(equal == 1)
    {
        printf("Масиви ідентичні! \n");
    }
    else if (equal == 0)
    {
        printf("Масиви різні! \n");
    }
}
