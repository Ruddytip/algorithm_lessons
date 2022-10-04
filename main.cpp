#include <iostream>
#include "geek.hpp"

// Task 1
// Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
// Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
// неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{. Например: (2+(2*2)) или [2/{5*(4+7)}]
// 
// Алгоритм проверяет только скобки, все остальные символы не имеют значения
bool checkingBrackets(std::string &str){
    Stack stk;
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == '[' || str[i] == '(' || str[i] == '{'){
            if(str[i] == '[') stk.push(']');
            if(str[i] == '(') stk.push(')');
            if(str[i] == '{') stk.push('}');
            continue;
        }
        if(str[i] == ']' || str[i] == ')' || str[i] == '}'){
            if(stk.pop() != str[i]) return false;
            continue;
        }
    }
    return true;
}
// ================================================================================================

// Task 2
// Создать функцию, копирующую односвязный список (без удаления первого списка).
// Реализован в файле geek.hpp, в классе ListSingl
// ================================================================================================

// Task 3
// Реализуйте алгоритм, который определяет, отсортирован ли связный список.
// Реализован в файле geek.hpp, в классе ListSingl
// ================================================================================================

int main(){
    // Проверка первого задания
    std::string str("[2/{5*(4+7)}]");
    std::cout << "Task1:\n";
    std::cout << "String - " << str << std::endl;
    std::cout << "Balance brackets is " << (checkingBrackets(str) ? "True" : "False") << std::endl;
    std::cout << std::endl;
    // ==========================================

    // Проверка второго задания
    std::cout << "Task2:\n";
    ListSingl l1, l2;
    for(int i = 0; i < 5; ++i) l1.pushEnd(i);
    for(int i = 0; i < 10; ++i) l2.pushEnd(0);
    std::cout << "Before copy\n";
    std::cout << "List 1: "; l1.print();
    std::cout << "List 2: "; l2.print();
    std::cout << std::endl;

    l1.copy(l2); // Копирование списка
    l1.clear();  // Изменение первого списка для демонстрации
    l1.pushBegin(1); l1.pushBegin(200); l1.pushBegin(555);

    std::cout << "After copy\n";
    std::cout << "List 1: "; l1.print();
    std::cout << "List 2: "; l2.print();
    std::cout << std::endl;
    // ==========================================

    // Проверка третьего задания
    std::cout << "Task3:\n";
    ListSingl l3;
    for(int i = 0; i < 10; ++i) l3.pushEnd(i);
    std::cout << "List: ";
    l3.print();
    std::cout << "Sort is ";
    std::cout << (l3.isSort() ? "True" : "False") << std::endl;
    // ==========================================
    return 0;
}