#include <iostream>
#include "data_tree.h"

int main() {

    search::tree<std::string> binary_tree;
    std::string input_data;

    while (std::cin >> input_data) {
        binary_tree.move_through_tree(input_data);
    }

    return 0;
}