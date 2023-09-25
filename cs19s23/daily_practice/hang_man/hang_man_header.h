#ifndef HANG_MAN_HEADER_H
#define HANG_MAN_HEADER_H
#include <string>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <vector>

namespace hang {

void man_printer() {
    std::vector<std::string> man;
    std::string line;
    std::ifstream("man_file.txt");
    
}

// bool is_char_valid(std::string input_char, std::string word) {

// }

bool game_status() {

}

std::string pick_word(std::ifstream& file) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
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
