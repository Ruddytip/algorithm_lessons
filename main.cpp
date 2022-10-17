#include <iostream>

// Task 1
// Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
// 
// Ограничений только на символы алфавита не было
std::string EncryptCaesar(const std::string &str, const int key){
    if(str.length() == 0 || key == 0) return str;
    std::string out = str;
    for(int i = 0; i < str.length(); ++i) out[i]+=key;
    return out;
}
std::string DecipherCaesar(const std::string &str, const int key){
    if(str.length() == 0 || key == 0) return str;
    std::string out = str;
    for(int i = 0; i < str.length(); ++i) out[i]-=key;
    return out;
}
// ================================================================================================

// Task 2
// Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов
std::string EncryptionPermutation(const std::string &str, const int key){
    if(key < 2 || key >= str.length()) return str;
    int x = key;
    int y = str.length() / key + 1;
    char* matrix = new char[x * y];

    int index = 0;
    for(int j = 0; j < y; ++j)
        for(int i = 0; i < x; ++i)
            matrix[j * x + i] = (index < str.length() ? str[index++] : ' ');

    std::string out = "";
    for(int j = 0; j < y; ++j)
        for(int i = 0; i < x; ++i)
            out+=matrix[i * y + j];

    delete[] matrix;
    return out;
}
std::string DecryptionPermutation(const std::string &str, const int key){
    if(key < 2 || key >= str.length()) return str;
    int x = key;
    int y = str.length() / key;
    char* matrix = new char[x * y];

    int index = 0;
    for(int j = 0; j < y; ++j)
        for(int i = 0; i < x; ++i)
            matrix[i * y + j] = str[index++];

    std::string out = "";
    for(int j = 0; j < y; ++j)
        for(int i = 0; i < x; ++i)
            out+=matrix[j * x + i];

    // Удаление лишних пробелов, которые были вставленны в конец строки
    index = out.length() - 1;
    for(;out[index] == ' ';--index){}
    out.erase(index + 1, out.length() - 1);

    delete[] matrix;
    return out;
}
// ================================================================================================

int main(){
    // Проверка первого задания
    std::cout << "Task1: \n";
    const int key1 = 15;
    std::string input1 = "Hello world!!! 1234567890";
    std::string intermediate1 = EncryptCaesar(input1, key1);
    std::string output1 = DecipherCaesar(intermediate1, key1);
    std::cout << "Input string:        " << input1 << std::endl;
    std::cout << "Intermediate string: " << intermediate1 << std::endl;
    std::cout << "Output string:       " << output1 << std::endl;
    std::cout << std::endl;
    // ==========================================

    // Проверка второго задания
    std::cout << "Task2: \n";
    const int key2 = 15;
    std::string input2 = "Hello world!!! 1234567890";
    std::string intermediate2 = EncryptionPermutation(input2, key2);
    std::string output2 = DecryptionPermutation(intermediate2, key2);
    std::cout << "Input string:        " << input2 << std::endl;
    std::cout << "Intermediate string: " << intermediate2 << std::endl;
    std::cout << "Output string:       " << output2 << std::endl;
    std::cout << std::endl;
    // ==========================================
    return 0;
}