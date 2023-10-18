#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "data_tree.h"


#define CYAN    "\033[36m"

int main() {

    search::tree<int> binary_tree;
    int input_data;
    std::string line;
    std::ifstream data_file("tree_loader.txt");

    while (std::getline(data_file, line)) {
        std::istringstream iss(line);
        int data;
        iss >> data;
        binary_tree.insert(data);
    }

    std::cout << std::endl;
    std::cout << "Search tree filled with " << binary_tree.size() << " integers!" << std::endl;
    

    // std::cout << std::endl;
    // std::cout << CYAN << "Fill your tree with data:" << RESET << std::endl;
    // std::cout << "> ";
    // while (std::cin >> input_data) {
    //     std::transform(input_data.begin(), input_data.end(), input_data.begin(), ::tolower);
    //     if (input_data == "stop") {
    //         break;
    //     }
    //     binary_tree.insert(input_data);
    //     std::cout << "> ";
    // }

    // binary_tree.pre_print();
    // binary_tree.inorder_print();

    std::cout << std::endl;
    std::cout << CYAN << "Find some data in your tree:" << RESET << std::endl;
    std::cout << "> ";
    while (std::cin >> input_data) {
        //std::transform(input_data.begin(), input_data.end(), input_data.begin(), ::tolower);
        if (input_data == 10001) {
            break;
        }
        binary_tree.find(input_data);
        std::cout << "> ";
    }

    return 0;
}