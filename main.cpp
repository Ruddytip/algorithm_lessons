#include <iostream>
#include <cmath> // Для функции sqrt()
#include "geek.hpp" // Функции для работы с массивами

// Task 1
// Описать в коде улучшенный алгоритм быстрой сортировки
void quickSort(int* const array, const int begin, const int end){
    const int SIZE = end - begin;
    if(SIZE <= 1) return;
    if(SIZE <= 10) geek::sortInsert(array, begin, end);
    else{
        int support = geek::partition(array, begin, end);
        quickSort(array, begin, support);
        quickSort(array, support + 1, end);
    }
}
// ================================================================================================

// Task 2
// Сортировать в массиве целых положительных чисел только чётные числа,
// нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
// то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 4 5 9 8 8 7 3]

// ================================================================================================

int main(){
    // Проверка первого задания
    std::cout << "Task 1:\n";
    const int SIZE = 50;
    int* array = geek::createArray(SIZE);
    geek::arrayInitRandom(array, SIZE, 10);
    std::cout << "Array before sorting: ";
    geek::arrayPrint(array, SIZE); // Печать массива в терминале до сортировки
    quickSort(array, 0, SIZE - 1);
    std::cout << "Array after sorting:  ";
    geek::arrayPrint(array, SIZE); // Печать массива в терминале после сортировки
    // ==========================================

    // Проверка второго задания
    std::cout << "\nTask 2:\n";

    // ==========================================
    return 0;
}