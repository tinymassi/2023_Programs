#include <iostream>
#include "data_tree.h"

int main() {

    search::tree<std::string> binary_tree;
    std::string input_data;

    std::cout << "> ";
    while (std::cin >> input_data) {
        if (input_data == "Stop") {
            break;
        }
        binary_tree.insert(input_data);
        std::cout << "> ";
    }

    // binary_tree.pre_print();
    // binary_tree.inorder_print();

    std::cout << "> ";
    while (std::cin >> input_data) {
        binary_tree.find(input_data);
        std::cout << "> ";
    }

    return 0;
}