#pragma once
// На вводном уроке было сказано, что файл "geek" можно реализовать самому

struct TNode{
    int data;
    TNode* next;
};

typedef TNode* PNode;

// Односвязный список
class ListSingl{
private:
    PNode begin, cur, end;
    int size;
public:
    // Конструктор
    ListSingl();
    // Деструктор
    ~ListSingl();
    // Вставляет элемент в начало списка
    void pushBegin(int data);
    // Вставляет элемент с конец списка
    void pushEnd(int data);
    // Извлекает элемент из начала списка
    int eraseBegin();
    // Извлекает элемент из конца списка
    int eraseEnd();
    // Очищает список
    void clear();
    // Возвращает указатель на первый элемент списка
    PNode getBegin();
    // Возвращает указатель на последний элемент списка
    PNode getEnd();
    // Печать списка в консоли
    void print();
    // Task 2
    // Создать функцию, копирующую односвязный список (без удаления первого списка).
    // Копирование списка
    void copy(ListSingl &out);
    // Task 3
    // Реализуйте алгоритм, который определяет, отсортирован ли связный список.
    // Возвращает true если список остортирован (от меньшего к большему)
    bool isSort();
};