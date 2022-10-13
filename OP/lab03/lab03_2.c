/*
 Ввести прямокутну матрицю дійсних чисел. Циклічно зсунути її рядки на 1 униз. 
 Циклічний зсув передбачає, що елементи останнього рядка матриці заносяться на відповідні місця зсунутих елементів першого рядка.
 */


#include <stdio.h>
int main(){
    
    int N = 0, M = 0;
    printf("Введіть кількість рядків матриці:");
    scanf("%d", &N);
    printf("Введіть кількість стовпчиків матриці:");
    scanf("%d", &M);
    printf("Далі треба ввести дійсні числа, які будуть знаходитися в матриці.\n");
    double fMatrix[N][M];
    double fMatHelp[N][M];
    double fMatPls[N][M];
    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            
            printf("Введіть число, яке знаходитиметься на перетині %d-го стовпця і %d-го рядка матриці:", k+1, i+1);
            scanf("%lf", (*(fMatrix + i) + k));
            fMatHelp[i][k] = fMatrix[i][k];
            fMatPls[i+1][k] = fMatrix[i][k];
        }
    }
    
    
    
    printf("Ваша матриця:\n");

    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            printf("%lf\t\t", *(*(fMatrix + i) + k));
        }
        printf("\n");
    }
    
    
    for (int i = N-1; i >= N-1; i --) {
        for (int k = 0; k < M; k++) {
            fMatPls[0][k] = fMatHelp[i][k];
        }
  }
    
    
    printf("Циклічно зсунута матриця:\n");
    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            printf("%lf\t\t", *(fMatPls[i]+k));
        }
        printf("\n");
    }
    
    
    return 0;
}
