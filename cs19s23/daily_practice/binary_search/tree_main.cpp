#include <iostream>
#include "data_tree.h"

int main() {

    search::tree<std::string> my_tree;
    // Level 1
    std::string data_entry;

    while (std::cin >> data_entry) {
        my_tree.create_node(data_entry);
    }

    return 0;

}