#include <iostream>
#include <cmath> // Для функции sqrt() и pow()
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
void basketSort_onlyEven(int* const array, const int SIZE){
    const int countBuckets = 10; // Кол-во корзин
    int buckets[countBuckets][SIZE + 1]; // (+ 1) - дополнительная ячейка для счётчика внутри корзины
    // Обнуление счётчика корзин
    for(int i = 0; i < countBuckets; ++i) buckets[i][SIZE] = 0;
    bool flags[SIZE]; // Массив флагов чётности чисел в массиве
    int max = array[0]; // Максимальное число в массиве, используется в дальнейшем
    for(int i = 0; i < SIZE; ++i){
        flags[i] = ((array[i]%2==0) ? true : false);
        if(array[i] > max) max = array[i];
    }
    // Поиск самого большого числа и расчет его разрядности
    int count = 1;
    for(; max > 0; ++count) max/= 10;
    int numberDigits = std::pow(10, count); // Максимальная разрядность числа, которые учитываются при сортировке
    // Использовал std::pow() исключительно для уменьшения кода, при необходимости могу реализовать самостоятельно
    // Цикл сортировки
    for(int digit = 1; digit <= numberDigits; digit*=countBuckets){
        // Цикл поиска подходящей корзины для записи элемента
        for(int i = 0; i < SIZE; ++i){
            if(flags[i]){
                int numberBucket = (array[i] / digit) % countBuckets;
                int index = buckets[numberBucket][SIZE]++;
                buckets[numberBucket][index] = array[i];
            }
        }
        // Цикл перезаписи элементов из корзин в исходный массив
        for(int i = 0, idx = 0; i < countBuckets; ++i){
            for(int j = 0; j < buckets[i][SIZE]; ++j){
                while(!flags[idx]) ++idx;
                array[idx++] = buckets[i][j];
            }
            buckets[i][SIZE] = 0;
        }
    }
}
// ================================================================================================

int main(){
    // Проверка первого задания
    std::cout << "Task 1:\n";
    const int SIZE = 20;
    int* array = geek::createArray(SIZE);
    geek::arrayInitRandom(array, SIZE, 100);
    std::cout << "Array before sorting: ";
    geek::arrayPrint(array, SIZE); // Печать массива в терминале до сортировки
    quickSort(array, 0, SIZE - 1);
    std::cout << "Array after sorting:  ";
    geek::arrayPrint(array, SIZE); // Печать массива в терминале после сортировки
    // ==========================================

    // Проверка второго задания
    std::cout << "\nTask 2:\n";
    const int SIZE_2 = 20;
    int* array2 = geek::createArray(SIZE_2);
    geek::arrayInitRandom(array2, SIZE_2, 100);
    std::cout << "Array before sorting: ";
    geek::arrayPrint(array2, SIZE_2); // Печать массива в терминале до сортировки
    basketSort_onlyEven(array2, SIZE_2);
    std::cout << "Array after sorting:  ";
    geek::arrayPrint(array2, SIZE_2); // Печать массива в терминале после сортировки
    // ==========================================
    return 0;
}
