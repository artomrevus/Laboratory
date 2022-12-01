#include "table_ptr.h"
#include <stdio.h>
#include <math.h>


void for_table(double a, double b, double h)
{
   do{
       if(h > 0)
       {
           
           if(a < b && h < (b-a))
           {
               printf("\n\nТабулювання з допомогою циклу for:\n");
               printf("===================\n");
               printf("|    x   |    f(x)|\n");
               printf("===================\n");
               for(; a <= b; a+=h)
               {
                   double func_res = 0;
                   func_res = a * cbrt(1-a);
                   printf("|%7.2lf | %7.2lf|\n", a, func_res);
                   
               }
               printf("===================\n");
               break;
           }
       }
       else if(h < 0)
       {
           
           if(a > b && fabs(h) < (a-b))
           {
               printf("\n\nТабулювання з допомогою циклу for:\n");
               printf("===================\n");
               printf("|    x   |    f(x)|\n");
               printf("===================\n");
               for(; a >= b; a+=h)
               {
                   double func_res = 0;
                   func_res = a * cbrt(1-a);
                   printf("|%7.2lf | %7.2lf|\n", a, func_res);
                   
               }
               printf("===================\n");
               break;
           }
       }
       
       else if (h > 0.00001 && h < -0.00001)
       {
           break;
       }
       
           printf("\nНеможливо протабулювати функцію. Введіть інші вхідні дані.\n\n");
       
   }while(0);
}
    


void while_table(double a, double b, double h)
{
   do{
       if(h > 0)
       {
           
           if(a < b && h < (b-a))
           {
               printf("\n\nТабулювання з допомогою циклу while:\n");
               printf("===================\n");
               printf("|    x   |    f(x)|\n");
               printf("===================\n");
               while(a <= b)
               {
                   double func_res = 0;
                   func_res = a * cbrt(1-a);
                   printf("|%7.2lf | %7.2lf|\n", a, func_res);
                   a+=h;
               }
               printf("===================\n");
               break;
           }
       }
       else if(h < 0)
       {
           
           if(a > b && fabs(h) < (a-b))
           {
               printf("\n\nТабулювання з допомогою циклу while:\n");
               printf("===================\n");
               printf("|    x   |    f(x)|\n");
               printf("===================\n");
               while(a >= b)
               {
                   double func_res = 0;
                   func_res = a * cbrt(1-a);
                   printf("|%7.2lf | %7.2lf|\n", a, func_res);
                   a+=h;
               }
               printf("===================\n");
               break;
           }
       }
       
       else if (h > 0.00001 && h < -0.00001)
       {
           break;
       }
       
           printf("\nНеможливо протабулювати функцію. Введіть інші вхідні дані.\n\n");
       
   }while(0);
    
}
           
           

void do_while_table(double a, double b, double h)
{
   do{
       if(h > 0)
       {
           
           if(a < b && h < (b-a))
           {
               printf("\n\nТабулювання з допомогою циклу do_while:\n");
               printf("===================\n");
               printf("|    x   |    f(x)|\n");
               printf("===================\n");
               do{
                   double func_res = 0;
                   func_res = a * cbrt(1-a);
                   printf("|%7.2lf | %7.2lf|\n", a, func_res);
                   a+=h;
               }while(a <= b);
               printf("===================\n");
               break;
           }
       }
       else if(h < 0)
       {
           
           if(a > b && fabs(h) < (a-b))
           {
               printf("\n\nТабулювання з допомогою циклу do_while:\n");
               printf("===================\n");
               printf("|    x   |    f(x)|\n");
               printf("===================\n");
               do{
                   double func_res = 0;
                   func_res = a * cbrt(1-a);
                   printf("|%7.2lf | %7.2lf|\n", a, func_res);
                   a+=h;
               }while(a >= b);
               printf("===================\n");
               break;
           }
       }
       
       else if (h > 0.00001 && h < -0.00001)
       {
           break;
       }
       
           printf("\nНеможливо протабулювати функцію. Введіть інші вхідні дані.\n\n");
       
   }while(0);
    
}
    
    
    
void error_table(double a, double b, double h)
{
     printf("Невідомий спосіб табулювання! Було ж написано, що ввести 1 або 2 або 3...\n");
}
