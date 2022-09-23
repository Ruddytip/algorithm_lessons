#include <iostream>
#include "geek.hpp"
#include <ctime> // Для обновления таймера рандома

int* geek::createArray(const int SIZE){
    int* arrayOut = new int[SIZE];
    return arrayOut;
}

void geek::deleteArray(int* array){
    delete array;
}

void geek::arrayInitZero(int* array, const int SIZE){
    for(int i = 0; i < SIZE; ++i) array[i] = 0;
}

void geek::arrayInitRandom(int* array, const int SIZE, const int range){
    srand(time(0));
    for(int i = 0; i < SIZE; ++i) array[i] = rand() % range;
}

void geek::arrayPrint(const int* const array, const int SIZE){
    for(int i = 0; i < SIZE; ++i) std::cout << array[i] << " ";
    std::cout << std::endl;
}

void geek::sortInsert(int* array, const int begin, const int end){
    const int SIZE = end - begin;
    if(SIZE <= 1) return;
    for(int j = begin; j <= end; ++j){ // Цикл от первого к последнему элементу неотсортированного массива
        const int dir = array[j];
        int i = j - 1; // Индекс самого большого отсортированного числа в массиве
        // Цикл от последнего к первому элементу отсортированного массива
        for(; i >= 0 && array[i] > dir; --i) array[i + 1] = array[i]; // Сдвиг элементов
        array[i + 1] = dir; // Вставка элемента
    }
}

int geek::partition(int* array, const int begin, const int end){
    int median = (array[begin] + array[end]) / 2;
    int i = begin, j = end;
    while(true){
        for(;array[i] < median; ++i){}
        for(;array[j] > median; --j){}
        if (i >= j) return j;
        std::swap(array[i++], array[j--]);
    }
}