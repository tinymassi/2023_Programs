#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

void saveDataToFile(const std::vector<std::string>& container,const std::string& file_name) {
    std::ofstream save_to_file (file_name, std::ios::app);
    if (save_to_file.is_open()) {
        for (int i = 0; i < container.size(); i++) {
            save_to_file << container[i] << '\n';
        }
        save_to_file.close();
        std::cout << "Data successfully transferred to " << file_name << '\n';
    } else {
        std::cerr << "Unable to open file: " << file_name << '\n';
    }
}

void loadDataFromFile (std::vector<std::string>& container, std::string& file_name) {
    std::ifstream take_from_file (file_name);
    if (take_from_file.is_open()) {
        std::string line{};
        while (std::getline(take_from_file, line)) {
            container.push_back(line);
        }
        take_from_file.close();
    } else {
        std::cerr << "Unable to open file: " << file_name << std::endl;
    }
}

int main() {

    std::cout << "Enter data:" << '\n';
    std::string text_file_name = "text_file.txt";
    std::string input{};
    std::vector<std::string> container;
    bool check = true;
    while (check) {
        while (std::cin >> input) {
            if (input == "end" || input == "End") {
                check = false;
                break;
            } else {
                container.push_back(input);
            }
        }
    }

    saveDataToFile(container, text_file_name);

    loadDataFromFile(container, text_file_name);

    for (auto i : container) {
        std::cout << i << '\n';
    }

    return{};
}