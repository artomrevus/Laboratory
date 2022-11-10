#include <stdio.h>
#include "table_function.h"

int main(){
 
    float h = 0, a = 0, b = 0;
    
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter step: ");
    scanf("%f", &h);
    
    tabulation_1(a, b, h);
    tabulation_2(a, b, h);
    
    return 0;
}
