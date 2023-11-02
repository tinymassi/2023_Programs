#include <iostream>
#include "hash.h"
#include "string"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() {
    hash::hash_map<std::string> my_map;
    bool is_input_valid = true;
    int key;
    std::string value;
    std::string input;

    while (is_input_valid) {
        std::cout << GREEN << "What would you like to do with your hash map?" << RESET << std::endl; 
        std::cout << GREEN <<  "Enter anything other than a, b, & c to exit." << RESET << std::endl;
        std::cout << std::endl;
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
        } else {
            is_input_valid = false;
        }
        std::cout << std::endl;
    }

}