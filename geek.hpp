// На вводном уроке было сказано, что файл "geek" можно реализовать самому
namespace geek{
    // Выделяет память для массива и возвращает ссылку на массив
    int* createArray(const int SIZE);
    // Удаляет массив
    void deleteArray(int* array);
    // Инициализирует массив нулем
    void arrayInitZero(int* array, const int SIZE);
    // Инициализирует массив случайным значением больше нуля, но не больше range
    void arrayInitRandom(int* array, const int SIZE, const int range);
    // Выводит  массив в терминал
    void arrayPrint(const int* const array, const int SIZE);
    // Сортировка вставками, сортирует начиная с элемента с индексом begin и заканчивает элементом с индексом end
    void sortInsert(int* array, const int begin, const int end);
    // Разбиение Хоара, возвращает опорный элемент
    // Сортирует так, что слева от опорного, находятся только элементы меньше опорного,
    // А справа от опорного находятся только те, которые больше
    int partition(int* array, const int begin, const int end);
};