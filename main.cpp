#include <iostream>

// Task 1
// Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
int getHesh(const std::string &str){
    int result = 0;
    for(int i = 0; i < str.length(); ++i) result+= int(str[i]);
    return result;
}
// ================================================================================================

// Task 2
// Имеются монеты номиналом 50, 10, 5, 2, 1 коп.
// Напишите функцию которая минимальным количеством монет наберет сумму 98 коп.
// Для решения задачи используйте “жадный” алгоритм.
// 
// Предполагается, что в наличии всегда есть монеты с номиналом 1
void calculateCoin(const int summ, const int &size, const int* range, int* count){
    int result = summ;
    while(result){
        int max = 0;
        int index = 0;
        for(int i = 0; i < size; ++i) if(range[i]>max && range[i]<=result){
            max = range[i];
            index = i;
        }
        result-=max;
        count[index]++;
    }
}

void printCoin(const int &size, const int* range, const int* count){
for(int i = 0; i < size; ++i)
    std::cout << "Coin " << range[i] << " - " << count[i] << " pieces" << std::endl;
}
// ================================================================================================

int main(){
    // Проверка первого задания
    std::cout << "Task1: \n";
    const std::string INPUT = "test";
    std::cout << "String input: " << INPUT << std::endl;
    std::cout << "Hesh result:  " << getHesh(INPUT) << std::endl;
    std::cout << std::endl;
    // ==========================================

    // Проверка второго задания
    std::cout << "Task2: \n";
    const int SUMM = 98;
    const int SIZE = 5;
    const int RANGE[SIZE] = {1, 2, 5, 10, 50};
    int result[SIZE] = {0};
    std::cout << "Total summ: " << SUMM << std::endl;
    std::cout << "Range coins: ";
    for(int i = 0; i < SIZE; ++i) std::cout << RANGE[i] << ", ";
    std::cout << std::endl;
    calculateCoin(SUMM, SIZE, RANGE, result);
    printCoin(SIZE, RANGE, result);
    std::cout << std::endl;
    // ==========================================
    return 0;
}