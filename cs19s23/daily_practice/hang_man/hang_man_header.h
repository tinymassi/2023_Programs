#ifndef HANG_MAN_HEADER_H
#define HANG_MAN_HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <vector>

namespace hang {

class hang_man {

public:
std::vector<std::string> hang;
std::vector<std::string> word_stat;
int num = 0;

hang_man(){
    std::string line;
    std::ifstream file("man_file.txt");
    while (std::getline(file, line)) {
        hang.push_back(line);
    }
}

void print() {
    for (auto i : hang) {
        std::cout << i << std::endl;
    }
}

void man_printer(int wrong_count) {
    if (wrong_count == 1) {
        hang[2] += "O";
        print();
    } else if (wrong_count == 2) {
        hang[3] += " ";
        hang[3] += "|";
        print();
    } else if (wrong_count == 3) {
        hang[3].pop_back();
        hang[3].pop_back();
        hang[3] += "/|";
        print();
    } else if (wrong_count == 4) {
        hang[3] += "\\";
        print();
    } else if (wrong_count == 5) {
        hang[4] += "/";
        print();
    } else if (wrong_count == 6) {
        hang[4] += " \\";
        print();
    }
}

void print_blank (std::string key_word) {
    for (auto i : key_word) {
        word_stat.push_back("_");
    }
    for (auto i : word_stat) {
        std::cout << i;
    }
}

bool is_game_over() {
    for (int i = 0; i < word_stat.size(); i++) {
        if (word_stat[i] == "_") {
            return false;
        }
    }

    std::cout << std::endl;
    std::cout << " ===== YOU WIN! ===== " << std::endl;

    return true;
}

bool is_char_valid(char input_char) {

}

void print_word_status (char input, std::string key_word) {
    int count = 0;

    for (int i = 0; i < word_stat.size(); i++) {
        if (key_word[i] == input) {
            word_stat[i].pop_back();
            word_stat[i] = input;
            count++;
        }
    }

    for (auto i : word_stat) {
        std::cout << i;
    }

    std::cout << std::endl;
}

bool is_char_valid(char input_char, std::string key_word) {
    int count = 0;
    for (int i = 0; i < key_word.size(); i++) {
        if (key_word[i] == input_char) {
            count++;
        }
    }
    if (count > 0) {
        return true;
    } else {
        return false;
    }
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

};
}  // namespace hang

#endif  // HANG_MAN_HEADER_H
