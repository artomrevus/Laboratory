/*
 З допомогою операторів циклу, протабулювати на відрізку від А до В з області визначення функцію, 
 задану розкладом у ряд Тейлора(довжину ряду ввести з клавіатури). Для порівняння обчислити також у кожній точці табуляції 
 значення функції задане формулою. Результати подати у виді таблиці з коментарями.
 */

#include <stdio.h>
#include <math.h>
int main() {
    
    double res, S = 0, el = 1, dif;
    int n, leng;
    
    printf("Введіть довжину ряду Тейлора, від неї буде залежати точність значень, які знаходитимуться за розкладом (точність вводити цілим числом): ");
    scanf("%d", &leng);
    printf("Маємо функцію (1+x)^-1, визначену на проміжку від -1 до 1. Складемо таблицю з кроком 0.1:\n\n\n");
    printf("Значення х\t\tЗначення за розкладом\t\tЗначення (1+x)^-1\t\t\t   Різниця\n");
    printf("----------------------------------------------------------------------------------------\n");
    
    for(float x = -0.9; x<1; x += 0.1){
        res = pow(1+x, -1);
        n = 0;
        S = 0;
        el = 1;
        while (n<=leng) {
            el = pow(-x, n);
            S += el;
            n++ ;
        }
        
        dif = res - S;
        
// далі виводимо таблицю та робимо її красивою
        
        if(dif<0){
            if(x<0)
                printf("  %.1f\t\t\t  %.15lf\t\t\t%.15lf\t\t %.15lf\n", x, S, res, dif);
            else
                printf("   %.1f\t\t\t  %.15lf\t\t\t%.15lf\t\t %.15lf\n", x, S, res, dif);
        } else {
            if(x<0)
                printf("  %.1f\t\t\t  %.15lf\t\t\t%.15lf\t\t  %.15lf\n", x, S, res, dif);
            else
                printf("   %.1f\t\t\t  %.15lf\t\t\t%.15lf\t\t  %.15lf\n", x, S, res, dif);
        }
        
        
    } //тут кінець циклу for
    
    return 0;
}
