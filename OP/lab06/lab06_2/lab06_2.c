/* У функцію зі змінним числом параметрів надходять дійсні числа, кількість яких задана
першим параметром. Знайти і вивести кількість додатніх та від’ємних чисел. */

#include <stdio.h>
#include "func_change.h"



int main() {
    
    pos_neg_count(16, 887.1, -21.212, -5.0, -2.0, -3.0, 4.0,  887.1, 21.2142, -5.0, -121.0512, 6080.0, -325.215, 2.1, 2.90, 78.0, -12.4);
    pos_neg_count(7, 887.1, -21.2142, -2.43620, 3.250, -3254.0, 12.3, 5.1);
          
    return 0;
}
