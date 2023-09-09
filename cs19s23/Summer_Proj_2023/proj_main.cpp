  // **
  // Creator: Massimo Ginella (massimoginella12@gmail.com)
  // This program is designed to calculate simpsons, trapezoidal, and midpoint rule
  // from an input polynomial. This project will start off with simple functions, but
  // will hopefully grow more advanced as time goes on as my programming
  // skills become more proficient.
  // **

#include <iostream>
#include "function_parser.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main() {
    std::string function;
    std::string method;
    std::string limit_b;
    std::string limit_a;
    bool check = false;
    int n;
    double delta_x;
    std::cout << "Enter a polynomial function: \n";
    std::cout << "Ex: 4x^3 + 1x^2 - 3x^1 + 2x^0 \n";
    std::getline(std::cin, function);
    if (par::poly_check(function) == false) {
        while (check == false) {
            std::cout << "\n";
            std::cout << RED << "Invalid syntax for polynomial expression. " 
                      << "Please follow the example syntax exaclty." << RESET << std::endl;
            std::cout << "Ex: 4x^3 + 1x^2 - 3x^1 + 2x^0\n";
            std::cin >> function;
            if (par::poly_check(function) == true) {
                check = true;
            }
        }
    }

    check = false;
    std::cout << "\n";
    std::cout << "Enter your limits of integration: \n";
    std::cout << "Enter b: ";
    std::cin >> limit_b;
    std::cout << "Enter a: ";
    std::cin >> limit_a;
    std::cout << "\n";
    if (par::limit_check(limit_a, limit_b) == false) {
        while (check == false) {
            std::cout << "\n";
            std::cout << RED << "Invalid a or b value. Please try again." << RESET << std::endl;
            std::cout << RED << "Make sure that b > a and that a & b are positive integers." << RESET << std::endl;
            std::cout << "Enter b: ";
            std::cin >> limit_b;
            std::cout << "Enter a: ";
            std::cin >> limit_a;
            std::cout << "\n";
            if (par::limit_check(limit_a, limit_b) == true) {
                check = true;
            }
        }
    }

    check = false;
    std::cout << "\n";
    std::cout << "Enter one of these methods: \n";
    std::cout << "Simpsons (s), Trapezoidal (t), Midpoint (m) \n";
    std::cin >> method;
    if (method != "s" && method != "t" && method != "m") {
        while (!check) {
            std::cout << "\n";
            std::cout << RED << "Invalid character for desired method. Please try again." << RESET << std::endl;
            std::cout << "Simpsons (s), Trapezoidal (t), Midpoint (m) \n";
            std::cin >> method;
            if (method == "s" || method == "t" || method == "m") {
                check = true;
            }
        }
    }

    check = false;
    std::cout << "\n";
    std::cout << "Finally, enter your n value: \n";
    std::cin >> n;
    if (method == "s" && n % 2 != 0) {
        while (!check) {
            std::cout << std::endl;
            std::cout << RED << "Simpsons rule must have an even n value." << RESET << std::endl;
            std::cout << RED << "Please change your n value to an even integer." << RESET << std::endl;
            std::cout << "Please re-enter your n value:" << std::endl;
            std::cin >> n;
            if (n % 2 == 0) {
                check = true;
            }
        }
    }

    std::cout << std::endl;
    delta_x = (stod(limit_b) - stod(limit_a)) / n;
    
    if (method == "s") {
        std::cout << GREEN << "The area under your curve from x = " << limit_a << " to x = "
        << limit_b << " is " << par::simpsons(function, delta_x, limit_a, limit_b) << RESET << std::endl;
    } else if (method == "t") {
        std::cout << GREEN << "The area under your curve from x = " << limit_a << " to x = "
        << limit_b << " is " << par::trapezoidal(function, delta_x, limit_a, limit_b) << RESET << std::endl;
    } else {
        std::cout << GREEN << "The area under your curve from x = " << limit_a << " to x = "
        << limit_b << " is " << par::midpoint(function, delta_x, limit_a, limit_b) << RESET << std::endl;
    }

    return 0;
}
