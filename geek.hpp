#pragma once
// На вводном уроке было сказано, что файл "geek" можно реализовать самому

// Стек
class Stack{
private:
    // Элемент стека
    struct node{
        int data; // Данные элемента
        node* next; // Следующий элемент стека
    } *head; // Указатель на вершину стека
    int size; // размер стека
public:
    // Конструктор
    Stack();
    // Деструктор
    ~Stack();
    // Добавляет элемент со знаением data
    void push(int data);
    // Возвращает значение вершины стека и извлекает элемент
    int pop();
    // Возвращает значение вершины стека
    int peek();
    // Очищает стек
    void clear();
    // Печать стека
    void print();
    // Возвращает размер стэка
    int getSize();
};

// ==============================================

// Граф
class Graph{
private:
    int size; // Количество элементов в графе
    int** matrix; // Матрица смежности
    struct NodeToPrint{
        int index;
        int numberLinks;
    };
    // Рекурсивная функция обхода графа в глубину
    void recurPrinDepth(const int index, int* visited, Stack* stk);
    // Обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
    void graphTraversalRecur(const int id, int* visited, NodeToPrint* arr);
    // Обход графа по матрице смежности (с подсчётом всех вершин графа)
    void graphTraversalMatrix(NodeToPrint* arr);
public:
    // Конструктор пустого графа
    Graph();
    // Конструктор графа размера SIZE с данными из матрицы смежности mtrx
    Graph(const int SIZE, int mtrx[]);
    // Деструктор
    ~Graph();
    // Инициализирует граф размера SIZE с данными из матрицы смежности mtrx
    void init(const int SIZE, int mtrx[]);
    // Очищает граф
    void clear();
    // Печать в терминал индексов вершин графа в глубину
    void printDepth();
    // списка всех узлов в порядке уменьшения количества ссылок на них
    // 0 - Обход графа по матрице смежности (с подсчётом всех вершин графа)
    // 1 - Обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
    void printTraversal(const int dir);
};
