#include "pruffer_func.h"
#include <stdio.h>
#include <stdbool.h>

void print_hights(int* hights, int size, bool* marked) {
  int space = 0;
    printf("|");
  for (int i = 0; i < size; i++)
  {
    if (marked[i] == 0) {
      printf("%d ", hights[i]);
    }
    else {
      space++;
    }
  }
  for (int i = 0; i < space; i++)
  {
    printf("  ");
  }
    printf("   |");
}

int marked_hights(int * kode_pruf, int size_pruf, int * hights, int size_hights, bool * marked) {
  int count;
  int exl = 0;
  for (int i = 0; i < size_hights; i++)
  {
    count = 0;
    for (int j = 0; j < size_pruf; j++)
    {
      if (hights[i] == kode_pruf[j] || marked[i] == 1) {
        count++;
      }
    }
    if (count == 0) {
      exl = i;
      break;
    }
  }
  marked[exl] = 1;
  return (exl + 1);
}

void delete_pruffer(int* ArrT, int sizeT, int indexT) {
  ArrT[indexT] = 0;
}

void print_pruffer(int * kode, int size, int index) {
  int space = 0;
  if (index == size)
  {
    printf("0");
    space += size-1;
  }
  else {
    
    for (int i = 0; i < size; i++)
    {
      if (kode[i] != 0)
      {
        printf("%d ", kode[i]);
      }
      else
      {
        space ++;
      }
    }

  }
  for (int i = 0; i < space; i++)
  {
    printf("  ");
      
  }
 
}
