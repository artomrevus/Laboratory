/*
 Написати мовою С три функції, щоб протабулювати, задану згідно варіанту, функцію на проміжку [a , b] з кроком h, використавши:
 а) для першої функції оператор циклу for;
 б) для другої – оператор циклу while;
 в) для третьої – – оператор циклу do...while.
 Вибір способу табулювання реалізувати через вказівник на відповідну функцію.
 */

#include <stdio.h>
#include "table_ptr.h"
#define CREATE_LF(arg) double arg = 0.0;


int main() {
  
    CREATE_LF(a)
    CREATE_LF(b)
    CREATE_LF(h)
    printf("Введіть значення початку інтервалу табулювання: ");
    scanf("%lf", &a);
    printf("Введіть значення кінця інтервалу табулювання: ");
    scanf("%lf", &b);
    printf("Введіть крок табулювання: ");
    scanf("%lf", &h);
    printf("\n\n");
    
    void (*pTable_2)(double, double, double);
    
    int method = 0;
    
    
    printf("\n\nВиберіть метод табулювання. Якщо хочете протабулювати функцію за допомогою циклу for - введіть 1, якщо хочете протабулювати функцію за допомогою циклу while - введіть 2, якщо хочете протабулювати функцію за допомогою циклу do_while - введіть 3: ");
    scanf("%d", &method);
                
                
    switch (method)
    {
        case 1:
            pTable_2 = for_table;
            break;
        case 2:
            pTable_2 = while_table;
            break;
        case 3:
            pTable_2 = do_while_table;
            break;
        default:
            pTable_2 = error_table;
            break;
    }
                
    (*pTable_2)(a, b, h);
                
    return 0;
}
