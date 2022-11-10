#include "table_function.h"
#include <stdio.h>
#include <math.h>

float calculation_1(float x)
{
    float y = 0;
    if(1-x >= 0)
        y = x * pow((1-x), 1/3.0);
    else
        y = -x * pow(fabs(1-x), 1/3.0);
    return y;
}


float calculation_2(float x, float * y)
{
    float ret = 0;
    *y = calculation_1(x);
    if(*y < 0)
        ret = -1;
    else if(*y>0)
        ret = 1;
    else if(*y == 0)
        ret = 0;
    
    return ret;
}


void tabulation_1(float a, float b, float h)
{
    printf("           Тaблиця 1:\n");
    printf("---------------------------------\n");
    printf("|    X    |   calculation_1(y)  |\n");
    printf("---------------------------------\n");
    
    for (float x = a; x <= b; x += h) {
        printf("|%6.1f   |%13.3f        | \n", x, calculation_1(x));
    }
    
    printf("---------------------------------\n");
}


void tabulation_2(float a, float b, float h)
{
    float y;
    printf("           Тaблиця 2:\n");
    printf("------------------------------------------------------------\n");
    printf("|    X    |   calculation_2(*y)  |  calculation_2(return)  |\n");
    printf("------------------------------------------------------------\n");
    
    for (float x = a; x <= b; x += h) {
        float return_calculation_2 = calculation_2(x, &y);
        printf("|%6.1f   |%13.3f         | %12.0f            |\n", x, y, return_calculation_2);
    }
    
    printf("------------------------------------------------------------\n");
}
