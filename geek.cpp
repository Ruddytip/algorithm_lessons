#include <iostream>
#include "geek.hpp"

ListSingl::ListSingl(){
    begin = cur = end = nullptr;
    size = 0;
}

ListSingl::~ListSingl(){
    clear();
}

void ListSingl::pushBegin(int data){
    cur = new TNode;
    cur->data = data;
    cur->next = begin;
    begin = cur;
    if(size == 0) end = begin;
    size++;
}

void ListSingl::pushEnd(int data){
    cur = new TNode;
    cur->data = data;
    cur->next = nullptr;
    if(size) end->next = cur;
    end = cur;
    if(size == 0) begin = end;
    size++;
}

int ListSingl::eraseBegin(){
    if(size == 0) return -1;
    int data = begin->data;
    cur = begin;
    begin = begin->next;
    delete cur;
    size--;
    if(size == 0) begin = cur = end = nullptr;
    return data;
}

int ListSingl::eraseEnd(){
    if(size == 0) return -1;
    cur = begin;
    while(cur->next!=end) cur = cur->next;
    int data = end->data;
    delete end;
    end = cur;
    size--;
    end->next = nullptr;
    if(size == 0) begin = cur = end = nullptr;
    return data;
}

void ListSingl::clear(){
    if(size == 0){
        begin = cur = end = nullptr;
        return;
    }
    for(int i = 0; i < size; ++i){
        cur = begin;
        begin = begin->next;
        delete cur;
    }
    begin = cur = end = nullptr;
    size = 0;
}

PNode ListSingl::getBegin(){
    return begin;
}

PNode ListSingl::getEnd(){
    return end;
}

void ListSingl::print(){
    cur = begin;
    while(cur){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void ListSingl::copy(ListSingl &out){
    if(size == 0) return;
    out.clear();
    cur = begin;
    for(int i = 0; i < size; ++i){
        out.pushEnd(cur->data);
        cur = cur->next;
    }
}

bool ListSingl::isSort(){
    if(size == 0) return false;
    cur = begin;
    while(cur->next){
        if(cur->data > cur->next->data)
            return false;
        cur = cur->next;
    }
    return true;
}
