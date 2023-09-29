#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "hang_man_header.h"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

int main() {
    hang::hang_man game1;
    std::ifstream words("word_list.txt");
    std::string input_char;
    std::string key_word;
    int wrong_count = 0;
    key_word = game1.pick_word(words);
    std::cout << key_word << std::endl;
    transform(key_word.begin(), key_word.end(), key_word.begin(), ::tolower);
    game1.print();
    game1.print_blank(key_word);
    game1.print_used_chars();

    while (wrong_count <= 5) {
        std::cout << std::endl;
        if (game1.is_game_over()) {
            break;
        }

        std::cout << "> ";
        while (std::cin >> input_char) {
            transform(input_char.begin(), input_char.end(), input_char.begin(), ::tolower);
            std::cout << std::endl;
            if (game1.is_char_valid(input_char) == false) {
                std::cout << std::endl;
                std::cout << RED << "Your character has already been entered or was invalid. Try again." << RESET << std::endl;
                std::cout << std::endl;
            } else {
                break;
            }
        }

        if (game1.is_char_in_key(input_char, key_word) == false) {
            wrong_count++;
            game1.man_printer(wrong_count);
        } else {
            game1.print();
        }
        game1.print_word_status(input_char, key_word);
        game1.print_used_chars();
    }

    if (wrong_count == 6) {
        std::cout << std::endl;
        std::cout << RED << "===== YOU LOSE =====" << RESET << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << GREEN << "===== YOU WIN =====" << RESET << std::endl;
    }

}