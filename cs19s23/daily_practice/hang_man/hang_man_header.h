#ifndef HANG_MAN_HEADER_H
#define HANG_MAN_HEADER_H
#include <string>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <vector>

namespace hang {

void man_printer(int wrong_count) {
    std::vector<std::string> hang;
    std::vector<std::string> man = {"O","/|\\","/ \\"};  // change so that the man is drawn piece by piece not in 3
    std::string line;
    std::ifstream file("man_file.txt");
    while (std::getline(file, line)) {
        hang.push_back(line);
    }
    for (int i = 0; i < hang.size(); i++) {
        if (i == 2 && wrong_count == 1) {
            hang[i] += man[0];
        } else if (i == 3) {
            hang[i] += man[1];
        } else if (i == 4) {
            hang[i] += man[2];
        }
    }
}

// bool is_char_valid(std::string input_char, std::string word) {

// }

// bool game_status() {

// }

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
