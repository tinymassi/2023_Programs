#include <iostream>
#include <string>
#include "header_practice.h"

int main (){

    int a;
    int b;

    std::cin >> a;
    std::cin >> b;
    std::cout << "Your a: " << a << std::endl;
    std::cout << "Your b: " << b << std::endl;

    practice::swap(a, b);

    std::cout << "Your a: " << a << std::endl;
    std::cout << "Your b: " << b << std::endl;

    std::string d;
    std::string c;
    std::cin >> d;
    std::cin >> c;

    std::cout << "Your d: " << d << std::endl;
    std::cout << "Your c: " << c << std::endl;

    practice::swap(d, c);

    std::cout << "Your d: " << d << std::endl;
    std::cout << "Your c: " << c << std::endl;
}