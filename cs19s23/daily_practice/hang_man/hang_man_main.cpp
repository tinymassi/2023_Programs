#include <iostream>
#include <string>
#include <fstream>
#include "hang_man_header.h"

int main() {
    std::ifstream words("word_list.txt");
    std::string input_char;
    std::string key_word;
    int wrong_count = 0;
    bool game_is_valid = true;
    key_word = hang::pick_word(words);
    hang::man_printer(wrong_count);
    

    // while (hang::game_status()) {
    //     std::cin >> input_char;
    // }

}