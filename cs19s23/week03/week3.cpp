#include <iostream>
#include <string>
#include "header_file.h"

int main(){

    int number;
    std::string word;
    double decimal_num;
    std::cin >> number;
    std::cin >> word; 
    std::cin >> decimal_num;

    std::cout << balls::printer(number) << std::endl;
    std::cout << balls::printer(word) << std::endl;
    std::cout << balls::printer(decimal_num) << std::endl;
 

}