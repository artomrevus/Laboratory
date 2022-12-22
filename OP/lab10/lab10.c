/*
З текстового файлу зчитати послідовність записів, які містять дані про результати сесії студентів групи, 
організувавши послідовність структур в однозв’язний список у такому форматі:
<Прізвище>, <Ім’я>, <Дата народження>, <Список екзаменаційних оцінок>. 
Роздрукувати введені дані у вигляді таблиці. Відсортувати студентів у алфавітному порядку за прізвищем.
Реалізувати операцію вставки нового елемента у відсортований список і операцію вилучення зі списку студентів, які отримали на першому іспиті оцінку 2. 
Визначити двох найстарших студентів.
*/

#include "single_func.h"

int main(){
    struct Node * pHead;
    
    ListInit(&pHead);
    
    int count = 0;
    
    count = FileScan("grade.txt", &pHead);
    printf("\nRead data from the file, organized into a list: \n\n");
    PrintList(pHead);
    
    SortSurnameAlpha(&pHead, count);
    printf("\n");
    printf("\nSorted list by surname: \n\n");
    PrintList(pHead);
    
    AddNewElemToList(&pHead, &count);
    printf("\n");
    printf("\nSorted list with new (inserted) items: \n\n");
    PrintList(pHead);
    
    DeleteBadStudents(&pHead, count);
    printf("\n");
    printf("\nSorted list without students who got 2 on the first exam: \n\n");
    PrintList(pHead);
    
    SearchTwoOldestStudentsInList(&pHead, count);
    
    return 0;
}
