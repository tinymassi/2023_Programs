#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <cctype>
#include <algorithm>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

int get_randnum (int min, int max) {
    return min + (rand() % max - min + 1); 
}

std::vector<int> split_num (int parts, int num) {
    int base = num / parts;
    int remainder = num % parts;
    std::vector <int> split_numbers;

    for (int i = 0; i < parts; i++) {
        int piece = base + (i < remainder ? 1 : 0);
        split_numbers.push_back(piece);
    }

    return split_numbers;
}

int main() {
    std::string cp_name;
    int num1 = 1;
    std::vector <std::string> cp_names;
    std::cout << GREEN << "Enter the names of available CP's: " << RESET << std::endl;
    std::cout << GREEN "Enter 'STOP' when all CP's have been entered." << RESET << std::endl;
    std::cout << std::endl;
    std::cout << num1 << ". ";
    while (std::cin >> cp_name) {
        num1++;
        std::transform(cp_name.begin(), cp_name.end(), cp_name.begin(), ::tolower);
        if (cp_name == "stop") {
            break;
        } else {
            cp_names.push_back(cp_name);
        }
        
        std::cout << std::endl;
        std::cout << num1 << ". ";
    }
    num1-=2;

    std::cout << std::endl;
    std::string student_name;
    std::unordered_map <int,std::string> students;
    int num2 = 0;
    int i = 1;
    std::cout << GREEN << "Enter the names of available students: " << RESET << std::endl;
    std::cout << GREEN << "Enter 'STOP' when all students have been entered." << RESET << std::endl;
    std::cout << std::endl;
    std::cout << i << ". ";
    while (std::cin >> student_name) {
        i++;
        std::transform(student_name.begin(), student_name.end(), student_name.begin(), ::tolower);
        if (student_name == "stop") {
            break;
        } else {
            students.insert(std::make_pair(num2, student_name));
        }
        std::cout << std::endl;
        std::cout << i << ". ";
        num2++;
    }

    std::vector<int> pieces;
    pieces = split_num(num1, num2);

    srand(static_cast<unsigned int>(time(nullptr)));
    std::unordered_map <int, std::string> perm_map;
    int random_num = 0;
    std::cout << std::endl;
    std::cout << RED << "*** Here are your room assignments ***" << RESET << std::endl;
    std::cout << std::endl;
    std::string entry;
    bool response = true;

    for (int i = 0; i < students.size(); i++) {
        perm_map.insert(std::make_pair(i, students[i]));
    }

    while (response) {
        for (int k = 0; k < pieces.size(); k++) {
            if (cp_names[k].back() == 's') {
                if (k > 1 || k == 1) {std::cout << std::endl;}
                std::cout << GREEN << cp_names[k] << "' group:" << RESET << std::endl;
            } else {
                if (k > 1 || k == 1) {std::cout << std::endl;}
                std::cout << GREEN << cp_names[k] << "'s group:" << RESET << std::endl;
            }  // use vector shuffle instead of gross loop
            for (int j = 0; j < pieces[k]; j++) {
                random_num = get_randnum(1, num2);
                if (students.find(random_num) != students.end()) {
                    std::cout << students[random_num] << std::endl;
                } else {
                    while (students.find(random_num) == students.end()) {
                        if (students.size() == 1) {
                            random_num = students.begin()->first;
                        } else {
                            random_num = get_randnum(1, num2);
                        }
                    }
                    std::cout << students[random_num] << std::endl;
                }
                if (students.size() > 1) {students.erase(random_num);}
                if (students.size() == 0) {break;}
            }
        }
        for (int i = 0; i < perm_map.size(); i++) {
            students.insert(std::make_pair(i, perm_map[i]));
        }
        std::cout << std::endl;
        std::cout << GREEN << "Would you like to shuffle again? (Yes/No)" << RESET << std::endl;
        std::cout << "> ";
        std::cin >> entry;
        std::cout << std::endl;
        std::transform(entry.begin(), entry.end(), entry.begin(), ::tolower);
        if (entry != "yes") {
            response = false;
        } else {
            std::cout << std::endl;
            std::cout << RED << "*** Here is your new shuffle ***" << RESET << std::endl;
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;

    return 0;
}