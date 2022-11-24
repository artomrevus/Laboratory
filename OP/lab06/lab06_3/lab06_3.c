/* Використовуючи умовну компіляцію, обчислити значення змінної.
Функції max, min, одержання модуля, піднесення до степені, одержання кореня виконати у вигляді макросів. */

#include <stdio.h>
#include <math.h>

#define INT_CREATE(arg) int arg = 0;

#define POW(x, n) pow((x), (n))
#define ABS(x) (((x) < 0) ? -(x) : (x))
#define SQRT(arg) (sqrt(arg))

#define MIN(arg1, arg2) (((arg1) <= (arg2)) ? (arg1) : (arg2))
#define MAX(arg1, arg2) (((arg1) >= (arg2)) ? (arg1) : (arg2))

#define A 1

#if A == 1
#define W(x,y) printf("%.2lf", MAX(POW((x-y), 2), ABS(y-x)));
#else
#define W(x,y) printf("%.2lf", MIN((x+POW(y, 2)), SQRT(x+y)));
#endif

int main() {
    
    INT_CREATE(x)
    INT_CREATE(y)
    
    printf("Введіть x: ");
    scanf("%d", &x);
    printf("Введіть y: ");
    scanf("%d", &y);
    
    printf("Результат: ");

    W(x, y);
    printf("\n");

    return 0;
}
