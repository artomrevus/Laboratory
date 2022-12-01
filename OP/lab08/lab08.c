/*
 З текстового файлу зчитати послідовність записів, які містять дані про результати сесії студентів групи у такому форматі: 
 <Прізвище>, <Ім’я>, <Дата народження>, <Список екзаменаційних оцінок>. Роздрукувати введені дані у вигляді таблиці.
 Роздрукувати список студентів, які не отримали жодної оцінки 2 на іспитах, у алфавітному порядку за прізвищем. 
 Визначити двох найстарших студентів серед них.
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 20

struct marks {
    char surname[L];
    char name[L];
    int day;
    int month;
    int year;
    int grades[6];
};

int main(){

    struct marks M[L];
    int i = 0, count = 0;
    char str[1000];
    
    FILE * pF;
    pF = fopen("grade.txt", "rt");
    
    if(pF == NULL)
    {
        printf("Error open file\n");
        return (1);
    }
    
    char * ptr;
    
    while (!feof(pF)) {
        
        fgets(str, 1000, pF);
        
        ptr = strtok(str , ",\n");
        strcpy(M[i].surname, ptr);

        ptr = strtok(NULL , ",");
        strcpy(M[i].name, ptr);

        ptr = strtok(NULL , ".");
        M[i].day = atoi(ptr);

        ptr = strtok(NULL , ".");
        M[i].month = atoi(ptr);

        ptr = strtok(NULL , ",");
        M[i].year = atoi(ptr);

        for(int j = 0; j < 6; j++){
            ptr = strtok(NULL, " ");
            M[i].grades[j] = atoi(ptr);
        }
        
        
        count ++;
        i++;
         
    }

    printf("\n                       Зчитані дані:\n\n");
    for (int a = 0; a < count; a++) {
        if(a == 0){
            printf("----------------------------------------------------------------\n");
            printf("|  surname & name   | date of birthday |         marks         |\n");
            printf("----------------------------------------------------------------\n");
        }
        printf("| %s %s \t|    %02d.%02d.%d    | %d | %d | %d | %d | %d | %d |\n", M[a].surname, M[a].name, M[a].day, M[a].month, M[a].year , M[a].grades[0], M[a].grades[1], M[a].grades[2], M[a].grades[3], M[a].grades[4] , M[a].grades[5]);
        printf("----------------------------------------------------------------\n");
    }
    
    int num = 0;
    for(int h = 0; h < count; h++)
    {
        if(M[h].grades[0] != 2 && M[h].grades[1] != 2 && M[h].grades[2] != 2  && M[h].grades[3] != 2 && M[h].grades[4] != 2 && M[h].grades[5] != 2)
        {
            num++;
        }
        
        
    }
    
    
    struct marks not_bad[L];
    for (int i = 0; i < L; i ++) {
        not_bad[i].surname[0] = '\0';
    }
    
    for(int h = 0; h < count; h++)
    {
        if(M[h].grades[0] != 2 && M[h].grades[1] != 2 && M[h].grades[2] != 2  && M[h].grades[3] != 2 && M[h].grades[4] != 2 && M[h].grades[5] != 2)
        {
            for(int g = 0; g < num; g++)
            {
                if(not_bad[g].surname[0] == '\0')
                {

                    strcpy(not_bad[g].surname, M[h].surname);
                    strcpy(not_bad[g].name, M[h].name);
                    not_bad[g].day = M[h].day;
                    not_bad[g].month = M[h].month;
                    not_bad[g].year = M[h].year;
                    for(int i = 0; i < 6; i ++)
                    {
                        not_bad[g].grades[i] = M[h].grades[i];
                    }
                    break;
                }
                else
                    continue;
            }
        }
    }
    
    
    
    for (int i = 0; i < num; i++) {
        for (int j = 1; j < num; j++) {
            if(strcmp(not_bad[j].surname, not_bad[j-1].surname) < 0)
            {
                struct marks temp = not_bad[j];
                not_bad[j] = not_bad[j-1];
                not_bad[j-1] = temp;
            }
        }
    }
    
    printf("\n                Студенти, які не отримали 2:\n\n");
    for (int a = 0; a < num; a++) {
        if(a == 0){
            printf("----------------------------------------------------------------\n");
            printf("|  surname & name   | date of birthday |         marks         |\n");
            printf("----------------------------------------------------------------\n");
        }
        printf("| %s %s \t|    %02d.%02d.%d    | %d | %d | %d | %d | %d | %d |\n", not_bad[a].surname, not_bad[a].name, not_bad[a].day, not_bad[a].month, not_bad[a].year , not_bad[a].grades[0], not_bad[a].grades[1], not_bad[a].grades[2], not_bad[a].grades[3], not_bad[a].grades[4] , not_bad[a].grades[5]);
        printf("----------------------------------------------------------------\n");
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 1; j < num; j++) {
            if(not_bad[j].year < not_bad[j-1].year)
            {
                struct marks temp = not_bad[j];
                not_bad[j] = not_bad[j-1];
                not_bad[j-1] = temp;
            }
        }
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 1; j < num; j++) {
            if(not_bad[j].year == not_bad[j-1].year && not_bad[j].month < not_bad[j-1].month)
            {
                struct marks temp = not_bad[j];
                not_bad[j] = not_bad[j-1];
                not_bad[j-1] = temp;
            }
        }
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 1; j < num; j++) {
            if(not_bad[j].year == not_bad[j-1].year && not_bad[j].month < not_bad[j-1].month && not_bad[j].day < not_bad[j-1].day)
            {
                struct marks temp = not_bad[j];
                not_bad[j] = not_bad[j-1];
                not_bad[j-1] = temp;
            }
        }
    }
    
    
    
    
    printf("\nДва найстарші студенти, які не отримали 2 -");
    printf(" %s %s та %s %s\n\n", not_bad[0].surname, not_bad[0].name, not_bad[1].surname, not_bad[1].name);
    fclose(pF);
    
    
    
    
    return 0;
}
