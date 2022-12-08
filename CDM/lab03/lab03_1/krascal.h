#ifndef krascal_h
#define krascal_h
extern const int size;

void swap(int array[][3], long pos1, long pos2);
void bubble_sort(int array[][3], int size);
void sets_of_nodes(int sphere_1[3], int sphere_2[2], int tree_used[size][3], int num);

#endif
