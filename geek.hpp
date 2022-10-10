#pragma once
// На вводном уроке было сказано, что файл "geek" можно реализовать самому

struct TNode{
    int Data;
    TNode* Left;
    TNode* Right;
    TNode* Parent;
};

typedef TNode* PNode;

// Дерево
class Tree{
private:
    PNode root; // Указатель на корень дерева
    int countNode, depth; // Количество элементов в дереве и его глубина
    // Поиск места в дереве и размещение элемента
    void putNode(PNode ptr, const int data);
    // Подготовка строк перед отрисовкой диаграмы
    void nodeToStr(PNode ptr, const int count, std::string* str);
public:
    // Конструктор пустого дерева
    Tree();
    // Конструктор дерева через строку
    Tree(std::string str);
    // Деструктор
    ~Tree();
    // Вставляет элемент
    void push(const int data);
    // Очищает дерево
    void clear();
    // Возвращает указатель на корень дерева
    PNode getRoot();
    // Возвращает количество нодов в дереве
    int getCountNode();
    // Возвращает глубину дерева
    int getDepth();
    // Печать в терминал диаграмы дерева
    void printDiagram();
    // Печать элементов дерева в консоли в инфиксном порядке
    void print();
    // Task 1
    // Написать функцию проверяющую является ли бинарное дерево сбалансированным
    bool isBalanced();
};

// ==============================================
// Стек для проверки баланса скобок

class Stack{
private:
    // Элемент стека
    struct node{
        char data; // Данные элемента
        node* next; // Следующий элемент стека
    } *head; // Указатель на вершину стека
    int size; // размер стека
public:
    // Конструктор
    Stack();
    // Деструктор
    ~Stack();
    // Добавляет элемент со знаением data
    void push(char data);
    // Возвращает значение вершины стека и извлекает элемент
    char pop();
    // Возвращает значение вершины стека
    char peek();
    // Очищает стек
    void clear();
    // Печать стека
    void print();
    // Возвращает размер стэка
    int getSize();
};