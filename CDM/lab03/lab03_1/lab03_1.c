/*

 Написати програму, яка реалізує знаходження мінімального остовного (кістякового) дерева (МОД) 
 неорієнтованого зваженого зв'язного графа, заданого ваговою матрицею за алгоритмом Краскала.
 Етапи розв'язання задачі виводити на екран.
 
 */

#include <stdio.h>
#include "krascal.h"
#include <ctype.h>
const int size = 8;


int main() {
    int count = 0;
    int tree[size][3] = {
        {1, 1, 2},
        {4, 1, 4},
        {5, 1, 5},
        {8, 2, 3},
        {7, 2, 5},
        {10, 3, 4},
        {1, 3, 5},
        {13, 4, 5}
    };
    
    
    for(int i = 0; i < size; i ++){
        for (int k = 0; k < 3; k ++) {
            if(tree[i][k] <= 0 || isalpha(tree[i][k])){
                printf("Incorrect input");
                return 0;
            }
        }
    }
    
    
    bubble_sort(tree, size);
    printf("Вхідні дані, відсортовані в порядку зростання: \n\n");
    for(int i = 0; i < size; i ++){
        for (int k = 0; k < 3; k ++) {
            printf("%d  ", tree[i][k]);
        }
        printf("\n");
    }
    
    int tree_used[size][3] = {0};
    
    for(int i = 0; i < size; i ++){
        for (int k = 0; k < 3; k ++) {
            int audit_1 = 0;
            for(int p = 0; p < size; p++){
                if((tree[i][1] == tree_used[p][1] || tree[i][1] == tree_used[p][2]))
                {
                    
                    for (int q = 0; q < size; q++) {
                        if((tree[i][2] == tree_used[q][1] || tree[i][2] == tree_used[q][2]))
                        {
                            audit_1 = 1;
                        }
                    }
                }
            }
            if(audit_1 == 0)
            {
                tree_used[i][0] = tree[i][0];
                tree_used[i][1] = tree[i][1];
                tree_used[i][2] = tree[i][2];
                count++;
            }
        }
    }
    
    
    printf("\n");
    printf("Дві підмножини, з яких утворюватиметься остовне дерево: \n");
    
    if(count == 4){
            return 0;
        }
    
        
    int one = 0, two = 0, three = 0, four = 0, five = 0;
    
    printf("\n");
    for(int i = 0; i < size; i ++){
        for (int k = 1; k < 3; k ++) {
            if(tree_used[i][k] == 1)
                one++;
            if(tree_used[i][k] == 2)
                two++;
            if(tree_used[i][k] == 3)
                three++;
            if(tree_used[i][k] == 4)
                four++;
            if(tree_used[i][k] == 5)
                five++;
        }
        
    }
    

    int sphere_1[3] = {0};
    int sphere_2[2] = {0};
    if(one >= two && one >= three && one >= four && one >= five)
    {
        sets_of_nodes(sphere_1, sphere_2, tree_used, 1);
    }
    if (one <= two && two >= three && two >= four && two >= five)
    {
        sets_of_nodes(sphere_1, sphere_2, tree_used, 2);
    }
    if (one <= three && two <= three && three >= four && three >= five)
    {
        sets_of_nodes(sphere_1, sphere_2, tree_used, 3);
    }
    if (one <= four && two <= four && three <= four && four >= five)
    {
        sets_of_nodes(sphere_1, sphere_2, tree_used, 4);
    }
    if (one <= five && two <= five && three <= five && four <= five)
    {
        sets_of_nodes(sphere_1, sphere_2, tree_used, 5);
    }
    
    
    
    for(int i = 0; i < size; i ++){
        
            if((tree[i][1] == sphere_1[0] || tree[i][1] == sphere_1[1] || tree[i][1] == sphere_1[2]) && (tree[i][2] == sphere_2[0] || tree[i][2] == sphere_2[1]))
            {
                for(int k = 0; k < 3; k++){
                    tree_used[i][k] = tree[i][k];
                }
                break;
            }
        
            if((tree[i][2] == sphere_1[0] || tree[i][2] == sphere_1[1] || tree[i][2] == sphere_1[2]) && (tree[i][1] == sphere_2[0] || tree[i][1] == sphere_2[1]))
            {
                for(int k = 0; k < 3; k++){
                    tree_used[i][k] = tree[i][k];
                }
                break;
            }
        
    }
    
    int power = 0;
    printf("\n");
    printf("\nМінімальне остовне (кістякове) дерево (МОД):\n");
    for(int i = 0; i < size; i ++){
            if(tree_used[i][1] != 0 || tree_used[i][2] != 0)
            {
                printf("\nПозначення ребра: %d-%d. Його вага = %d. ", tree_used[i][1], tree_used[i][2], tree_used[i][0]);
                power += tree_used[i][0];
            }
    }
    printf("\n\nЗагальна вага мінімального остовного дерева = %d", power);
    printf("\n\n");

    
    return 0;
}
