#include <stdbool.h>

#ifndef pruffer_func_h
#define pruffer_func_h


void print_hights(int* ArrX, int sizeX, bool* Ex_X);
int marked_hights(int* ArrT, int sizeT, int* ArrX, int sizeX, bool* Ex_X);
void print_pruffer(int* ArrT, int sizeT, int indexT);
void delete_pruffer(int* ArrT, int sizeT, int indexT);

#endif
