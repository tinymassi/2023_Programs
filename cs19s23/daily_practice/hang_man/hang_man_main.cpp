#include <iostream>
#include <string>
#include <fstream>
#include "hang_man_header.h"

int main() {
    std::ifstream words("word_list.txt");
    std::string input_char;
    std::string key_word;
    bool game_is_valid = true;
    key_word = hang::pick_word(words);
    std::cout << key_word << std::endl;

    while (game_is_valid) {
        std::cin >> input_char;

    }

}