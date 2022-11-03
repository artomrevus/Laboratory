/*
 Замінити у введеному реченні слово з заданим порядковим номером відповідною кількістю
однакових заданих користувачем символів. У випадку, коли номер перевищує введену кількість слів друкувати відповідне повідомлення про реальну кількість слів у введеному реченні.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int words, num = 1;
    char str[100] = {0};
    char input_sym = '?';
    
    printf("Введіть номер слова, яке хочете замінити: ");
    scanf("%d", &num);
    getchar();
    
    printf("Введіть речення: ");
    fgets(str, sizeof(str), stdin);
    
    printf("Введіть символ:");
    scanf("%c", &input_sym);
    
    if(isalpha(str[0]))
        words = 1;
    else
        words = 0;
    
    int i = 0;
    while (i < strlen(str)) {
        if(isspace(str[i]) && isalpha(str[i+1]))
            words ++;
        if(words == num && isalpha(str[i]))
            str[i] = input_sym;
        i++;
    }
    
    if(num > words)
        printf("Номер слова, яке потрібно замінити перевищує кількість введених слів(%d)!\n", words);
    else{
        printf("Змінене речення: ");
        fputs(str, stdout);
    }
     
    return 0;
}
