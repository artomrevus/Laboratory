/*
 За заданим натуральним восьмизначним числом знаходить подвоєний добуток ненульовиx цифр цього числа та кількість нулів.
 */
 
#include <stdio.h>

int main() {
    
    short x8, zero = 0;
    int num, result = 2;
    float x1, x2, x3, x4, x5, x6, x7;
    
    printf("Введіть восьмизначне число: ");
    scanf("%d", &num);
    
    
    if(num >= 10000000 && num <= 99999999) {
        
        x8 = num % 10;
        if(x8 == 0)
            zero ++ ;
        else
            result *= x8;
        
        
        x7 = (int)(num % 100) / 10;
        if(x7 == 0)
            zero ++ ;
        else
            result *= x7;
        
        
        x6 = (int)(num % 1000) / 100;
        if(x6 == 0)
            zero ++ ;
        else
            result *= x6;
        
        
        x5 = (int)(num % 10000) / 1000;
        if(x5 == 0)
            zero ++ ;
        else
            result *= x5;
        
        
        x4 = (int)(num % 100000) / 10000;
        if(x4 == 0)
            zero ++ ;
        else
            result *= x4;
        
        
        x3 = (int)(num % 1000000) / 100000;
        if(x3 == 0)
            zero ++ ;
        else
            result *= x3;
        
        
        x2 = (int)(num % 10000000) / 1000000;
        if(x2 == 0)
            zero ++ ;
        else
            result *= x2;
        
        
        x1 = (int) num / 10000000;
        if(x1 == 0)
            zero ++ ;
        else
            result *= x1;
        
        printf("Кількість нулів у введеному числі: %hd\n", zero);
        printf("Подвоєний добуток ненульових цифр введеного числа = %d\n", result);
        
    } else
        printf("Ви ввели не восьмизначне число!\n");
    
    return 0;
}

