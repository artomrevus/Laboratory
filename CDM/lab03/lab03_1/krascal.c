#include "krascal.h"
#include <stdio.h>
extern const int size;

void swap(int array[][3], long pos1, long pos2)
{
    int tmp;
    for (int k = 0; k < 3; k ++) {
        tmp = array[pos1][k];
        array[pos1][k] = array[pos2][k];
        array[pos2][k] = tmp;
    }
}

void sets_of_nodes(int sphere_1[3], int sphere_2[2], int tree_used[size][3], int num){
    {
        int right_1 = 1;
        int right_2 = 1;
        int right_3 = 1;
        
        sphere_1[0] = num;
        for(int i = 0; i < size; i ++){
                if(tree_used[i][1] == num)
                {
                    if(right_1 == 1)
                    {
                        sphere_1[1] = tree_used[i][2];
                        right_1 = 0;
                    }
                    else if (right_1 == 0)
                    {
                        sphere_1[2] = tree_used[i][2];
                    }
                    
                }
                if(tree_used[i][2] == num)
                {
                    if(right_2 == 1)
                    {
                        sphere_1[2] = tree_used[i][1];
                        right_2 = 0;
                    }
                    else if (right_2 == 0)
                    {
                        sphere_1[1] = tree_used[i][1];
                    }
                }
                if(tree_used[i][1] != num && tree_used[i][2] != num)
                {
                    if(right_3 == 0)
                        continue;
                    else
                    {
                        sphere_2[0] = tree_used[i][1];
                        sphere_2[1] = tree_used[i][2];
                        right_3 = 0;
                    }
                }
            }
        printf("{%d, %d, %d}, {%d, %d} ", sphere_1[0], sphere_1[1], sphere_1[2], sphere_2[0], sphere_2[1]);
        }
}

void bubble_sort(int array[][3], int size){
    for(int i = 0; i < size; i ++){
        for (int k = 1; k < size; k ++) {
            if(array[k][0] < array[k-1][0])
                swap(array, k, k-1);
        }
    }
}

