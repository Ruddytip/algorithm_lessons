#include <iostream>
#include <cmath> // Для функции sqrt()
#include "geek.hpp" // Функции для работы с массивами

// Task 1
// Реализовать пузырьковую сортировку двумерного массива например,
// массив 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9
void sort_bub(int** array, const int SIZE_X, const int SIZE_Y){
    const int SIZE = SIZE_X * SIZE_Y;
    int arrayOut[SIZE] = { 0 };

    // Конвертирование двумерного массива в одномерный
    for(int j = 0; j < SIZE_Y; ++j)
        for(int i = 0; i < SIZE_X; ++i)
            arrayOut[j * SIZE_Y + i] = array[j][i];

    // Сортировка
    for(int j = 0; j < SIZE; ++j)
        for(int i = 0; i < SIZE - 1; ++i)
            if(arrayOut[i] > arrayOut[i + 1]){
                int a = arrayOut[i];
                arrayOut[i] = arrayOut[i + 1];
                arrayOut[i + 1] = a;
            }

    // Конвертирование одномерного массива в двумерный
    for(int j = 0; j < SIZE_Y; ++j)
        for(int i = 0; i < SIZE_X; ++i)
            array[j][i] = arrayOut[j * SIZE_Y + i];
}
// ================================================================================================

// Task 2
// Реализовать алгоритм Трабба-Прадо-Кнута
// Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута
// 1) - запросить у пользователя 11 чисел и записать их в последовательность
// 2) - инвертировать последовательность
// 3) - для каждого элемента последовательности произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3)
// и если результат вычислений превышает 400 - проинформировать пользователя.
void Trabba_Prado_Knut(){
    const int SIZE = 11;
    const int border = 400;
    int array[SIZE] = { 0 };
    for(int i = 0; i < SIZE; ++i) std::cin >> array[i]; // Заполнение
    for(int i = 0; i < SIZE / 2; ++i) std::swap(array[i], array[SIZE - 1 - i]); // Инвертирование
    for(int i = 0; i < SIZE; ++i) // Вычисление
        if((sqrt(fabs(array[i])) + 5 * pow(array[i], 3)) > border){
            std::cout << "Element number "
                      << i + 1
                      << " with a value of "
                      << array[i]
                      << " exceeds "
                      << border
                      << "!!!\n";
        }
}
// ================================================================================================

int main(){
    // Проверка первого задания
    const int SIZE_X1 = 4, SIZE_Y1 = 4; // Разсер массива
    int** test2dArray = geek::create2dArray(SIZE_X1, SIZE_Y1);
    geek::array2dInitRandom(test2dArray, SIZE_X1, SIZE_Y1, 10);
    std::cout << "Task 1:\nInit array:\n";
    geek::array2dPrint(test2dArray, SIZE_X1, SIZE_Y1); // Печать массива до сортировки
    sort_bub(test2dArray, SIZE_X1, SIZE_Y1);
    std::cout << "\nSort array:\n";
    geek::array2dPrint(test2dArray, SIZE_X1, SIZE_Y1); // Печать массива после сортировки
    std::cout << std::endl;
    geek::delete2dArray(test2dArray, SIZE_Y1);
    // ==========================================
    
    // Проверка второго задания
    std::cout << "Task 2:\n";
    std::cout << "Enter 11 numbers:\n";
    Trabba_Prado_Knut();
    // ==========================================
    return 0;
}