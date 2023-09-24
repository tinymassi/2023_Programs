#ifndef HANG_MAN_HEADER_H
#define HANG_MAN_HEADER_H
#include <string>
#include <fstream>
#include <unordered_map>

namespace hang {

void man_printer() {

}

bool is_char_valid(std::string input_char, std::string word) {

}

std::string pick_word(std::ifstream& file) {
    std::string line;
    std::unordered_map<int, std::string> words;
    int word_num = 1;
    while (std::getline(file, line)) {
        words.insert(std::make_pair(word_num, line));
        word_num++;
    }
    int rand_num = (rand() % word_num) + 1;
    std::string word = words[rand_num];
    return word;
}

}  // namespace hang

#endif  // HANG_MAN_HEADER_H
