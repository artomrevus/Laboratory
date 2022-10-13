/*
 З клавіатури ввести вектор цілих чисел. Визначити значення двох найменших елементів вектора.
 Якщо вони не є однаковими, то замінити ці елементи значенням їх півсуми
 */


#include <stdio.h>
int main() {
    
    int N = 0;
    
    do{
        printf("Введіть кількість елементів вектора (цілим числом не меншим від двох): ");
        scanf("%d", &N);
    } while(N <= 1);
    
    int vect[N];
    
    for(int i = 0; i < N; i++) {
        printf("Введіть ціле число (№%d): ", (i+1));
        scanf("%d",(vect + i));
    }
    
    printf("Ваш вектор чисел: ");
    for(int i = 0; i < N; i++){
        printf("%d   ", *(vect + i));
    }
    

    
    int min_1, min_2, index_1 = 0, index_2 = 0;
    
    min_1 = vect[1];
    
    for(int i = 1; i < N; i++){
        if (vect[i] <= min_1){
            min_1 = vect[i];
            index_1 = i;
        }
        else
            continue;
    }

    min_2 = vect[0];
    
    for(int i = 1; i < N; i++){
        if (i != index_1 && vect[i] <= min_2){
            min_2 = vect[i];
            index_2 = i;
        }
        else
            continue;
    }
        
    printf("\nНайменші елементи: %d та %d\n", min_1, min_2);
    
    if (min_1 == min_2) {
        printf("Найменші елементи однакові.\n");
    } else {
        
        float vector[N];
        
        for(int i = 0; i < N; i ++)
            vector[i] = vect[i];
        
        printf("Найменші елементи різні. Замінимо ці елементи їх півсумою: \n");
        vector[index_1] = (min_1 + min_2) / 2.0;
        vector[index_2] = vector[index_1];
        
        for(int i = 0; i < N; i++)
            printf("%.1f   ", *(vector + i));
    }
    
    
    printf("\n");
    return 0;

}
