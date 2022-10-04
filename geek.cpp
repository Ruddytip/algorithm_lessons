#include <iostream>
#include "geek.hpp"

// Очередь

Queue::Queue(){
    size = 0;
    head = tail = nullptr;
}

Queue::~Queue(){
    clear();
}

void Queue::add(int data, int priority){
    node* it = new node;
    it->data = data;
    it->priority = priority;
    it->next = nullptr;
    if(size == 0){
        head = tail = it;
    }else{
        tail->next = it;
        tail = it;
    }
    size++;
}

int Queue::extract(){
    if(size == 0) return 0;

    // Поиска самого большого приоритета
    int priMax = head->priority;
    node* it = head;
    while(it != nullptr){
        if(it->priority > priMax) priMax = it->priority;
        it = it->next;
    }

    // Поиск элемента с самым большим приоритетом
    it = head;
    node* old = nullptr;
    while(it->priority != priMax){
        old = it;
        it = it->next;
    }

    int data;
    data = it->data;
    if(it == head){
        head = head->next;
    }else{
        old->next = it->next;
    }
    delete it;
    size--;
    if(size == 0) head = tail = nullptr;
    return data;
}

void Queue::clear(){
    if(size == 0) return;
    while(head != nullptr){
        node* it = head;
        head = head->next;
        delete it;
    }
    size = 0;
    head = tail = nullptr;
}

void Queue::print(){
    if(size == 0) return;
    node* it = head;
    while(it != nullptr){
        std::cout << it->data << " " << it->priority << std::endl;
        it = it->next;
    }
}

int Queue::getSize(){
    return size;
}

// ==============================================

// Стэк

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
    if(size == 0) return 0;
    node* it = head;
    head = head->next;
    int data = it->data;
    delete it;
    size--;
    return data;
}

int Stack::peek(){
    if(size == 0) return;
    return head->data;
}

void Stack::clear(){
    if(size == 0) return 0;
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

// ==============================================
