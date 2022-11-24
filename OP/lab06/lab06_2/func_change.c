#include "func_change.h"
#include <stdarg.h>
#include <stdio.h>
#define CRT_INT(arg) int arg = 0;


void pos_neg_count(int n, ...){

    CRT_INT(positive);
    CRT_INT(negative);
    double term;
    va_list ptr;
    va_start(ptr, n);

    for (int i = 0; i < n ; i++)
    {
        
        term = va_arg(ptr, double);

        if(term > 0)
        {
            positive ++;
        }
        else if(term < 0)
        {
            negative ++;
        }

    }
    va_end(ptr);

    printf("%d ", positive);
    printf("%d ", negative);
}
