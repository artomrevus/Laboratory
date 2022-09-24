/*
 Надрукувати усі тризначні натуральні числа, сума цифр яких дорівнює 16.
 */
#include <stdio.h>

int main() {
    
    int sum = 0, number_3;
    float number_2, number_1;
    
    for(int i = 100; i<=999; i++) {
        
        number_3 = i % 10;
        number_2 = (int)(i % 100) / 10;
        number_1 = (int)(i / 100);
        
        sum = number_1 + number_2 + number_3;
        
        if(sum == 16)
            printf("%d\n", i);
        else
            continue;
        
    }
    return 0;
}
