#include <iostream>
#include <string>
#include <fstream>
#include "hang_man_header.h"

int main() {
    hang::hang_man game1;
    std::ifstream words("word_list.txt");
    char input_char;
    std::string key_word;
    int wrong_count = 0;
    bool game_is_valid = true;
    key_word = game1.pick_word(words);
    std::cout << key_word << std::endl;

    while (wrong_count <= 5) {
        std::cin >> input_char;
        if (game1.is_char_valid(input_char, key_word) == false) {
            wrong_count++;
        } else {
            
        }
        game1.man_printer(wrong_count);
    }
    

    // while (hang::game_status()) {
    //     std::cin >> input_char;
    // }

}