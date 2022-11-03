/*
 Скласти програму на мові С, яка обчислюватиме значення виразу "lab01.1". Значення параметрів X, Y, Z прочитати із заданого
 бінарного файлу (вводиться користувачем з клавіатури). Результат записати у файл, теж вказаний користувачем. Формат файлу
 (бінарний чи текстовий) також задається користувачем. При цьому робота програми повинна бути запротокольована. Виконання
 основних подій, починаючи зі старту програми, має бути відображене у log-файлі з часовими мітками (розміщення вибрати
 самостійно). Старі записи у log-файлі мають зберігатися. Перелік подій для логування:
 - старт програми;
 - відкриття файлу з параметрами;
 - обчислення значення виразу;
 - запис обчисленого значення у вихідний файл;
 - завершення програми.
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    do{
        FILE * plog = fopen("log.txt", "a");
    
        if(plog == NULL)
        {
            printf("ERROR\n");
            break;
        }
            
        time_t now = time(NULL);
        struct tm *cur_time = localtime(&now);
        int day, month;
        day = cur_time->tm_mday;
        month = cur_time->tm_mon;
        char sec[3];
        strftime(sec, 100, ".0%S", cur_time);
            
            
        fprintf(plog, "\n[%d.%02d.%02d %02d:%02d%s] Program started.", cur_time->tm_year + 1900, cur_time->tm_mday, cur_time->tm_mon+1, cur_time->tm_hour, cur_time->tm_min, sec);
            
            
        char arrFile[100];
        char x_y_z[100];
        char * pAdressY;
        char * pAdressZ;
        double x, y, z, result;
        char mode[2] = {'w'};
        int correct = 0;
            
        printf("Ведіть назву файлу, з якого хочете зчитати змінні: ");
        fgets(arrFile, 100, stdin);
        strtok(arrFile, "\n");
            
        FILE * pFile = fopen(arrFile, "rb");
        
        if(pFile == NULL)
        {
            printf("ERROR\n");
            break;
        }
    

        fread(x_y_z, sizeof(double), 3, pFile);
        x = strtod(x_y_z, &pAdressY);
        y = strtod(pAdressY, &pAdressZ);
        z = strtod(pAdressZ, NULL);
        fclose(pFile);
                
                
        fprintf(plog, "\n[%d.%02d.%02d %02d:%02d%s] Parameters file \"%s\" opened. X=%.3lf, Y=%.3lf, Z=%.3lf", cur_time->tm_year + 1900, cur_time->tm_mday, cur_time->tm_mon+1, cur_time->tm_hour, cur_time->tm_min, sec, arrFile, x, y, z);
                
                
        result = pow(y + pow(x + 1, 1/3.0), 1/4.0);
                
                
        fprintf(plog, "\n[%d.%02d.%02d %02d:%02d%s] Expression calculated. Result = %.3lf", cur_time->tm_year + 1900, cur_time->tm_mday, cur_time->tm_mon+1, cur_time->tm_hour, cur_time->tm_min, sec, result);
                
                
        while (correct != 1)
        {
            printf("Ведіть формат файлу, в який хочете записати результат ('t' або 'b'): ");
            mode[1] = getchar();
            getchar();
                    
            if(mode[1] != 't' && mode[1] != 'b')
                printf("Ви неправильно ввели формат файлу! ");
            else
                correct = 1;
        }
        
        if(mode[1] == 't')
        {
            printf("Ведіть назву файлу, в який хочете записати результат: ");
            fgets(arrFile, 100, stdin);
            strtok(arrFile, "\n");
            
            pFile = fopen(arrFile, mode);
            if(pFile == NULL)
            {
                printf("ERROR\n");
                break;
            }
            
            fprintf(pFile, "%lf", result);
            fclose(pFile);
            
            
            fprintf(plog, "\n[%d.%02d.%02d %02d:%02d%s] Output file \"%s\" saved.", cur_time->tm_year + 1900, cur_time->tm_mday, cur_time->tm_mon+1, cur_time->tm_hour, cur_time->tm_min, sec, arrFile);
            
            
            fprintf(plog, "\n[%d.%02d.%02d %02d:%02d%s] Program ended.", cur_time->tm_year + 1900, cur_time->tm_mday, cur_time->tm_mon+1, cur_time->tm_hour, cur_time->tm_min, sec);
            
            
            
            fclose(plog);
        }
        else if (mode[1] == 'b')
        {
            printf("Ведіть назву файлу, в який хочете записати результат: ");
            fgets(arrFile, 100, stdin);
            strtok(arrFile, "\n");
            
            pFile = fopen(arrFile, mode);
            if(pFile == NULL)
            {
                printf("ERROR\n");
                break;
            }
            
            fprintf(pFile, "%lf", result);
            fwrite(&result, sizeof(double), 1, pFile);
            fclose(pFile);
            
            
            fprintf(plog, "\n[%d.%02d.%02d %02d:%02d%s] Output file \"%s\" saved.", cur_time->tm_year + 1900, cur_time->tm_mday, cur_time->tm_mon+1, cur_time->tm_hour, cur_time->tm_min, sec, arrFile);
            
            
            fprintf(plog, "\n[%d.%02d.%02d %02d:%02d%s] Program ended.", cur_time->tm_year + 1900, cur_time->tm_mday, cur_time->tm_mon+1, cur_time->tm_hour, cur_time->tm_min, sec);
            
            
            
            fclose(plog);
        }
        
    } while(0);
    
    
    return 0;
}
