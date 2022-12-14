/*
Завдання: Написати програму для обчислення арифметичного виразу. Вважати, що X, Y – змінні, значення яких слід вводити з клавіатури.
 */
#include <stdio.h>
#include <math.h>

int main() {
    float x, y, a, b;
    
    printf("Введіть змінну х: ");
    scanf("%f", &x);
    printf("Введіть змінну y: ");
    scanf("%f", &y);
    
    a = y + pow(x + 1, 1.0/3);
    b = pow(a, 0.25);
    if(a>=0)
        printf("Відповідь: приблизно %.3f\n", b);
    else
        printf("Неможливо добути корінь четвертого степеня з від'ємного числа. Введіть інші вхідні дані! \n");
        
    return 0;
}
