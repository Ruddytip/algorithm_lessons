#include <iostream>
#include <cmath>
#include "geek.hpp"

// Дерево

Tree::Tree(){
    root = nullptr;
    countNode = depth = 0;
}

// Создаёт и инициализирует элемент дерева
PNode createNode(const int data){
    PNode ptr = new TNode;
    ptr->Data = data;
    ptr->Left = ptr->Right = ptr->Parent = nullptr;
    return ptr;
}

// Перевод строки в дерево
void putNodeStr(PNode ptr, std::string &str, int &count){
    int data = str[count] - 48;
    ptr->Data = data;
    if(str[++count] == '('){
        if(str[++count] != ','){
            --count;
            PNode pl = createNode(0);
            ptr->Left = pl;
            putNodeStr(pl, str, ++count);
        }
        if(str[count] == ','){
            PNode pr = createNode(0);
            ptr->Right = pr;
            putNodeStr(pr, str, ++count);
        }
        ++count;
    }
}

void Tree::putNode(PNode ptr, const int data){
    if(data < ptr->Data){
        if(ptr->Left){
            putNode(ptr->Left, data);
        }else{
            ptr->Left = createNode(data);
            countNode++;
        }
    }else{
        if(ptr->Right){
            putNode(ptr->Right, data);
        }else{
            ptr->Right = createNode(data);
            countNode++;
        }
    }
}

// Проверка баланса скобок
bool checkingBrackets(std::string &str){
    if(str.length() == 0) return false;
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

Tree::Tree(std::string str){
    if(!checkingBrackets(str)){
        std::cerr << "Error brackets!!!\n";
        return;
    }
    int count = 0;
    root = createNode(0);
    putNodeStr(root, str, count);
}

Tree::~Tree(){
    clear();
}

void Tree::push(const int data){
    if(countNode == 0){
        root = createNode(data);
        countNode++;
    }else{
        putNode(root, data);
    }
}

// Удаляет элемент дерева, а так же все его дочерние вершины
void eraseBranch(PNode ptr){
    if(ptr->Left) eraseBranch(ptr->Left);
    if(ptr->Right) eraseBranch(ptr->Right);
    delete ptr;
}

void Tree::clear(){
    if(countNode == 0) return;
    eraseBranch(root);
    root = nullptr;
    countNode = depth = 0;
}

PNode Tree::getRoot(){
    return root;
}

int Tree::getCountNode(){
    return countNode;
}

// Обновляет значение глубины дерева
int updateDepth(PNode ptr, const int count){
    if(!ptr) return count;
    int maxL = updateDepth(ptr->Left, count + 1);
    int maxR = updateDepth(ptr->Right, count + 1);
    return (maxL > maxR ? maxL : maxR);
}

int Tree::getDepth(){
    depth = updateDepth(root, 0);
    return depth;
}

void Tree::nodeToStr(PNode ptr, const int count, std::string* str){
    // Заполнение пробелами пустых поддеревьев
    if(!ptr){
        for(int i = count; i < depth; ++i)
            str[i]+= std::string(pow(2, depth - count - 1) * 2, ' ');
        return;
    }
    nodeToStr(ptr->Left, count + 1, str);
    int delta = pow(2, depth - count - 1); // Длина печати от края и до элемента

    // Отрисовка левой стрелки
    if(ptr->Left){
        str[count]+= std::string((delta - 1) / 2, ' ');
        if(count < depth - 1) str[count]+='+';
        str[count]+= std::string((delta - 1) / 2, '-');
    }else{
        str[count]+= std::string(delta - 1, ' ');
    }

    str[count]+= char(ptr->Data + 48);

    // Отрисовка правой стрелки
    if(ptr->Right){
        str[count]+= std::string(delta / 2 - 1, '-');
        if(count < depth - 1) str[count]+='+';
        str[count]+= std::string(delta / 2, ' ');
    }else{
        str[count]+= std::string(delta, ' ');
    }
    nodeToStr(ptr->Right, count + 1, str);
}

void Tree::printDiagram(){
    depth = updateDepth(root, 0);
    if(depth == 0) return;
    std::string* str = new std::string[depth];
    for(int i = 0; i < depth; ++i) str[i] = "";
    nodeToStr(root, 0, str);
    for(int i = 0; i < depth; ++i) std::cout << str[i] << std::endl;
    delete[] str;
}

// 
void prin(PNode ptr){
    if(ptr->Left) prin(ptr->Left);
    std::cout << ptr->Data << ' ';
    if(ptr->Right) prin(ptr->Right);
}

void Tree::print(){
    if(root) prin(root);
    std::cout << std::endl;
}

// 
int countN(PNode ptr, bool& flag){
    if(!ptr) return 0;
    int left = countN(ptr->Left, flag);
    int right = countN(ptr->Right, flag);
    if(abs(left - right) > 1) flag = false;
    return left + right + 1;
}

bool Tree::isBalanced(){
    if(countNode == 0) return false;
    bool flag = true;
    countN(root, flag);
    return flag;
}

// ==============================================
// Стек для проверки баланса скобок

Stack::Stack(){
    size = 0;
    head = nullptr;
}

Stack::~Stack(){
    clear();
}

void Stack::push(char data){
    node* it = new node;
    it->data = data;
    it->next = head;
    head = it;
    size++;
}

char Stack::pop(){
    if(size == 0) return '_';
    node* it = head;
    head = head->next;
    int data = it->data;
    delete it;
    size--;
    return data;
}

char Stack::peek(){
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
