#include <iostream>
#include "data_tree.h"

int main() {

    search::tree<std::string> binary_tree;
    std::string input_data;

    while (std::cin >> input_data) {
        binary_tree.insert(input_data);
    }

    return 0;
}