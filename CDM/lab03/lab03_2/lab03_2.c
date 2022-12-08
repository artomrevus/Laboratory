#include <stdio.h>
#include <stdbool.h>
#include "pruffer_func.h"
#define N 10
#define M (N+2)

int main() {

  int v = 0, eX;
  int kode_pruf[N] = {6, 6, 7, 4, 4, 3, 6, 7, 8, 8}, hights[M] = {1, 2, 3 , 4, 5, 6, 7, 8, 9, 10, 11, 12};
  bool marked[M] = {0};
  
        printf("\n");
        printf("------------------------------------------------------------------------------- \n| Step |  vX  |   vT   |          T            |            X                 |\n------------------------------------------------------------------------------- \n|   0  |   0  |        | ");
        v = kode_pruf[0];
        print_pruffer(kode_pruf, N, 0);
        printf("  ");
        print_hights(hights, M, marked);
        eX = marked_hights(kode_pruf, N, hights, M, marked);
        printf("\n------------------------------------------------------------------------------- \n");
        
        for (int i = 1; i < N+1; i++) {
            printf("| %3.1d  | %3.1d  | %4.1d   | ", i, eX, v);
            delete_pruffer(kode_pruf, N, i-1);
            if( i < N ) v = kode_pruf[i];
            print_pruffer(kode_pruf, N, i);
            printf("  ");
            print_hights(hights, M, marked);
            
            eX = marked_hights(kode_pruf, N, hights, M, marked);
            printf("  \n------------------------------------------------------------------------------- \n");
        }
    
//    список ребер:
    
    int kode_pruf_1[N] = {6, 6, 7, 4, 4, 3, 6, 7, 8, 8}, hights_1[M] = {1, 2, 3 , 4, 5, 6, 7, 8, 9, 10, 11, 12};
    bool marked_1[M] = {0};
    printf("\n");
    printf("Cписок ребер:");
    
    v = kode_pruf_1[0];
    eX = marked_hights(kode_pruf_1, N, hights_1, M, marked_1);
    printf("\n----------------- \n");
    
    for (int i = 1; i < N+1; i++) {
        printf("| %3.1d  | %4.1d   | ", eX, v);
        delete_pruffer(kode_pruf_1, N, i-1);
        if( i < N ) v = kode_pruf_1[i];
    
        eX = marked_hights(kode_pruf_1, N, hights_1, M, marked_1);
        printf("  \n----------------- \n");
    }
    
    for(int i = 0; i < M; i++){
        if(marked_1[i] == false){
            printf("|   %d  |   12   |", eX);
        }
    }
    printf("  \n----------------- \n");
    
  return 0;

}

