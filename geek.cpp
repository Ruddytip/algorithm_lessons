#include <iostream>
#include "geek.hpp"
#include <ctime> // Для обновления таймера рандома

int** geek::create2dArray(const int SIZE_X, const int SIZE_Y){
    int** arrayOut = new int*[SIZE_Y];
    for(int j = 0; j < SIZE_Y; ++j)
        arrayOut[j] = new int[SIZE_X];
    return arrayOut;
}

void geek::delete2dArray(int** array, const int SIZE_Y){
    for(int j = 0; j < SIZE_Y; ++j)
        delete[] array[j];
    delete array;
}

void geek::array2dInitZero(int** array, const int SIZE_X, const int SIZE_Y){
    for(int i = 0; i < SIZE_X; ++i)
        for(int j = 0; j < SIZE_Y; ++j)
            array[j][i] = 0;
}

void geek::array2dInitRandom(int** array, const int SIZE_X, const int SIZE_Y, const int range){
    srand(time(0));
    for(int i = 0; i < SIZE_X; ++i)
        for(int j = 0; j < SIZE_Y; ++j)
            array[j][i] = rand() % range;
}

void geek::array2dPrint(int** const array, const int SIZE_X, const int SIZE_Y){
    for(int i = 0; i < SIZE_X; ++i){
        for(int j = 0; j < SIZE_Y; ++j){
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}