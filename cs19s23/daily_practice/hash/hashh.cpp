#include <iostream>
#include "hash.h"
#include "string"

int main() {
    hash::hash_map<std::string> my_map;
    bool is_input_valid = true;
    int key;
    std::string value;

    while (is_input_valid) {
        std::cout << "Enter key > ";
        std::cin >> key;
        std::cout << std::endl;
        std::cout << "Enter data > ";
        std::cin >> value;
        my_map.insert(key, value);
        std::cout << std::endl;
    }

}