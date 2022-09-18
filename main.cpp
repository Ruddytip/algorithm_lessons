#include <iostream>

// Task 1
// Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
// В данном случае, максимальное число для перевода из десятичной формы - 1023.
int decimalToBinary(const int data){
    if(data == 0) return 0;
    int whole = data / 2;
    int remainder = data % 2;
    return (decimalToBinary(whole) * 10 + (remainder?1:0));
}
// ================================================================================================

// Task 2
// Реализовать функцию возведения числа [a] в степень [b]:
int power(const int a, const int b){
    int result = 1;
    for(int i = 0; i < b; ++i) result*= a;
    return result;
}
// ================================================================================================

// Task 3
// Рекурсивно.
int powerRecur(const int a, const int b){
    if(b == 1) return a;
    return powerRecur(a, b - 1) * a;
}
// ================================================================================================

// Task 4
// Рекурсивно, используя свойство чётности степени (то есть, если степень,
// в которую нужно возвести число, чётная, основание возводится в квадрат,
// а показатель делится на два, а если степень нечётная - результат умножается на основание,
// а показатель уменьшается на единицу)
int powerWithProperty(const int a, const int b){
    if(b == 1) return a;
    if(b % 2 == 0) return powerWithProperty(a * a, b / 2);
    return powerWithProperty(a, b - 1) * a;
}
// ================================================================================================

// Task 5
const int SIZE_X = 10;
const int SIZE_Y = 10;
int field[SIZE_X][SIZE_Y] = { 0 };
// Реализовать нахождение количества маршрутов шахматного короля с учётом ограничений на перемещение из урока,
// с препятствиями (где единица - это наличие препятствия, а ноль - свободная для хода клетка)
int routes(const int x, const int y){
    if(x == 0 && y == 0) return 0;
    if(x == 0 ^ y == 0) return 1;
    if(field[x][y] == 1) return 0;
    return routes(x - 1, y) + routes(x, y - 1);
}
// ================================================================================================

// Вспомогательная функция для 5 задания
// Форматирование табличного вывода
void printSpace(const int data){
    if(data >= 10000) std::cout << " ";
    else if(data >= 1000) std::cout << "  ";
    else if(data >= 100) std::cout << "   ";
    else if(data >= 10) std::cout << "    ";
    else std::cout << "     ";
}

int main(){

    // Проверка первого задания
    int decData = 0;
    std::cout << "Enter a decimal number:";
    std::cin >> decData;
    std::cout << "Task 1 result: " << decimalToBinary(decData) << std::endl;
    // ==========================================

    // Проверка второго задания
    int a2 = 0, b2 = 0;
    std::cout << "Enter the number a:"; std::cin >> a2;
    std::cout << "Enter the number b:"; std::cin >> b2;
    std::cout << "Task 2 result: " << power(a2, b2) << std::endl;
    // ==========================================

    // Проверка третьего задания
    int a3 = 0, b3 = 0;
    std::cout << "Enter the number a:"; std::cin >> a3;
    std::cout << "Enter the number b:"; std::cin >> b3;
    std::cout << "Task 3 result: " << powerRecur(a3, b3) << std::endl;
    // // ==========================================

    // Проверка четвертого задания
    int a4 = 0, b4 = 0;
    std::cout << "Enter the number a:"; std::cin >> a4;
    std::cout << "Enter the number b:"; std::cin >> b4;
    std::cout << "Task 4 result: " << powerWithProperty(a4, b4) << std::endl;
    // ==========================================

    // Проверка пятого задания
    field[1][1] = 1;
    field[4][2] = 1;
    field[5][7] = 1;

    std::cout << "Task 5 result:\n";
    for(int i = 0; i < SIZE_X; ++i){
        for(int j = 0; j < SIZE_Y; ++j){
            int data = routes(i, j);
            printSpace(data);
            std::cout << data;
        }
        std::cout << std::endl;
    }
    // ==========================================

    return 0;
}