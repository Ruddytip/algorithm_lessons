#include <iostream>
#include "geek.hpp"

// Граф

Graph::Graph(): size(0){}

Graph::Graph(const int SIZE, int mtrx[]){
    init(SIZE, mtrx);
}

Graph::~Graph(){
    clear();
}

void Graph::init(const int SIZE, int mtrx[]){
    size = SIZE;
    matrix = new int*[size];
    for(int j = 0; j < size; j++){
        matrix[j] = new int[size];
        for(int i = 0; i < size; i++){
            matrix[j][i] = mtrx[j * SIZE + i];
        }
    }
}

void Graph::clear(){
    if(size == 0) return;
    for(int i = 0; i < size; ++i)
        delete[] matrix[i];
    delete[] matrix;
    size = 0;
}

void Graph::recurPrinDepth(const int index, int* visited, Stack* stk){
    stk->push(index);
    visited[index] = 1;
    for(int next = 0; next < size; ++next)
        if(matrix[index][next] == 1 && !visited[next])
            recurPrinDepth(next, visited, stk);
}

void Graph::printDepth(){
    int* visited = new int[size];
    for(int i = 0; i < size; ++i)
        visited[i] = 0;
    Stack stk;
    recurPrinDepth(0, visited, &stk);
    std::cout << "Verts: ";
    for(int i = 0; i < size; ++i)
        visited[i] = stk.pop();
    for(int i = size - 1; i >= 0; --i)
        std::cout << visited[i] << ' ';
    std::cout << std::endl;
    delete[] visited;
}

void Graph::graphTraversalRecur(const int id, int* visited, NodeToPrint* arr){
    visited[id] = 1;
    arr[id].index = id;
    for(int i = 0; i < size; ++i) if(matrix[id][i] == 1) arr[id].numberLinks++;
    for(int i = 0; i < size; ++i) if(matrix[id][i] == 1 && !visited[i]) graphTraversalRecur(id + 1, visited, arr);
}

void Graph::graphTraversalMatrix(NodeToPrint* arr){
    for(int i = 0; i < size; ++i){
        arr[i].index = i;
        arr[i].numberLinks = 0;
        for(int j = 0; j < size; ++j)
            if(matrix[i][j]) arr[i].numberLinks++;
    }
}

void Graph::printTraversal(const int dir){
    if(size == 0) return;
    NodeToPrint* arr = new NodeToPrint[size];
    for(int i = 0; i < size; ++i){
        arr[i].index = -1;
        arr[i].numberLinks = 0;
    }

    int index = 0;
    int* visited = new int[size];
    for(int i = 0; i< size; ++i) visited[i] = 0;
    switch(dir){
        case 0: graphTraversalMatrix(arr); break;
        case 1: graphTraversalRecur(index, visited, arr); break;
        default: return; break;
    }
    delete[] visited;

    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            if(arr[i].numberLinks > arr[j].numberLinks)
            std::swap(arr[i], arr[j]);

    for(int i = 0; i < size; ++ i)
        if(arr[i].index >= 0)
            std::cout << "Varts: " << arr[i].index << " - links: " << arr[i].numberLinks << std::endl;
    
    delete[] arr;
}

// ==============================================
// Стек

Stack::Stack(){
    size = 0;
    head = nullptr;
}

Stack::~Stack(){
    clear();
}

void Stack::push(int data){
    node* it = new node;
    it->data = data;
    it->next = head;
    head = it;
    size++;
}

int Stack::pop(){
    if(size == 0) return '_';
    node* it = head;
    head = head->next;
    int data = it->data;
    delete it;
    size--;
    return data;
}

int Stack::peek(){
    if(size == 0) return '_';
    return head->data;
}

void Stack::clear(){
    if(size == 0) return;
    while(size > 0) pop();
    size = 0;
    head = nullptr;
}

void Stack::print(){
    if(size == 0) return;
    node* it = head;
    while(it != nullptr){
        std::cout << it->data << " " << std::endl;
        it = it->next;
    }
}

int Stack::getSize(){
    return size;
}
