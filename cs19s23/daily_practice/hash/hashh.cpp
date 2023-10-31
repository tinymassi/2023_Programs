#include <iostream>
#include "hash.h"
#include "string"

int main() {
    hash::hash_map<std::string> my_map;
    bool is_input_valid = true;
    int key;
    std::string value;
    std::string input;

    while (is_input_valid) {
        std::cout << "What would you like to do with your hash map?" << std::endl;
        std::cout << "a) Enter a key & value   b) See your table   c) Remove a key & value" << std::endl;
        std::cout << "> ";
        std::cin >> input;
        std::cout << std::endl;
        if (input == "a") {
            std::cout << "Enter key > ";
            std::cin >> key;
            std::cout << std::endl;
            std::cout << "Enter data > ";
            std::cin >> value;
            my_map.insert(key, value);
            std::cout << std::endl;
        } else if (input == "b") {
            my_map.print_table();
        } else if (input == "c") {
            std::cout << "Enter key to remove > ";
            std::cin >> key;
            std::cout << std::endl;
            std::cout << "Enter data to remove > ";
            std::cin >> value;
            my_map.remove(key, value);
        }
    }

}