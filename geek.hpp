// На вводном уроке было сказано, что файл "geek" можно реализовать самому
namespace geek{
    // Выделяет память для двумерного массива и возвращает ссылку на массив
    int** create2dArray(const int SIZE_X, const int SIZE_Y);
    // Удаляет двумерный массив
    void delete2dArray(int** array, const int SIZE_Y);
    // Инициализирует двумерный массив значением 0
    void array2dInitZero(int** array, const int SIZE_X, const int SIZE_Y);
    // Инициализирует двумерный массив случайным значением больше нуля, но не больше range
    void array2dInitRandom(int** array, const int SIZE_X, const int SIZE_Y, const int range);
    // Выводит двумерный массив в терминал
    void array2dPrint(int** const array, const int SIZE_X, const int SIZE_Y);
};