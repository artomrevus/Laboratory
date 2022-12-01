/* Використовуючи рекурсію, для кожного елемента з набору цілих чисел вирахувати
залишок від ділення на 3. Масив не оголошувати. */

#include <stdio.h>

void recurs(int count, int start_num){
    int n=0;
    
    printf("Введіть число №%d: ", start_num);
    scanf("%d", &n);
    
    printf("Після вирахування остачі від ділення на 3, число №%d = ", start_num);
    printf("%d\n", n-(n%3));
    
    start_num++;
    if(start_num <= count){
        recurs(count, start_num);
    }
}

int main() {
    int count = 1;
    
    printf("Введіть кількість чисел у наборі: ");
    scanf("%d", &count);
    
    recurs(count, 1);
    
    return 0;
}
