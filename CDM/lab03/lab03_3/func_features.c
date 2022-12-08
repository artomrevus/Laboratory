#include "func_features.h"
#include <stdio.h>
#define N 4

int reflexive(int arr[N][N]){
    int reflex_T = 1, reflex_F = 1;
    int rf_F = 0, rf_T = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(i == j && arr[i][j] == 1 && reflex_T == 1)
            {
                reflex_T = 1;
                rf_T = 1;
            }
            else if (i == j && arr[i][j] == 0 && reflex_F == 1)
            {
                reflex_F = 1;
                rf_F = 1;
            }
        }
    }
    
    if(reflex_T && !rf_F)
    {
        printf("Відношення рефлексивне\n");
        return 1;
    }
    else if(reflex_F && !rf_T)
    {
        printf("Відношення антирефлексивне\n");
        return 0;
    }
    else
    {
        printf("Відношення ні рефлексивне, ні антирефлексивне\n");
        return -1;
    }
}




int symetric(int arr[N][N]){
    int symetric = 0, antisymetric = 0, sym = 0, antisym = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(arr[i][j] == arr[j][i] && i != j)
            {
                symetric = 1;
                sym = 1;
            }
            if(arr[i][j] != arr[j][i] && i != j)
            {
                antisymetric = 1;
                antisym = 1;
            }
        }
    }
    if(symetric && !antisym)
    {
        printf("Відношення симетричне\n");
        return 1;
    }
    else if(antisymetric && !sym)
    {
        int help = reflexive(arr);
        if(help == 0)
        {
            printf("Відношення асиметричне\n");
            return 2;
        }
        else
        {
            printf("Відношення антисиметричне\n");
            return 0;
        }
        
    }
    else
    {
        printf("Відношення антисиметричне\n");
        return 0;
    }
}




int transistive(int arr[N][N]){
    int transist = 0, antitransist = 0, tr = 0, antitr = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            for(int k = 0; k < N; k ++){
                if(arr[i][j] == 1 && arr[j][k] == 1 && arr[i][k] == 1 && i != j && i != k && j != k)
                {
                    transist = 1;
                    tr = 1;
                }
                if(arr[i][j] == 1 && arr[j][k] == 1 && arr[i][k] != 1 && i != j && i != k && j != k)
                {
                    antitransist = 1;
                    antitr = 1;
                }
            }
        }
    }
    
    if(transist && !antitr)
    {
        printf("Відношення транзистивне\n");
        return 1;
    }
    else if (antitransist && !tr)
    {
        printf("Відношення антитранзистивне\n");
        return 0;
    }
    else
    {
        printf("Відношення ні транзистивне, ні антитранзистивне\n");
        return -1;
    }
}

void relation(int arr[N][N]){
    
    int isReflex = reflexive(arr);
    
    int isSymetric = symetric(arr);
    
    int isTransistive = transistive(arr);
    
    if(isReflex == 1 && isSymetric == 1 && isTransistive == 1)
    {
        printf("Дане відношення є відношенням еквівалентності!\n");
    }
    else if(isReflex == 1 && isSymetric == 1 && isTransistive == 0)
    {
        printf("Дане відношення є відношенням толерантності!\n");
    }
    else if(isTransistive == 1 && isSymetric == 0)
    {
        printf("Дане відношення є відношенням порядку!\n");
    }
    else
    {
        printf("Дане відношення не є відношенням ні еквівалентності, ні толерантності, ні порядку!\n");
    }
    
}
