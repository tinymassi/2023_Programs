#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <vector>
#include <string>
#include <list>

namespace log {

class log {

    private:

    int static const size = 1000;
    std::vector<std::pair<int, std::list<std::pair<std::string, std::string>>>> table [size];

    public:

    void insert(int password, std::string date, std::string entry) {
        int array_index = hash_function(password);
        bool is_data_in_table = false;
        int vector_index{};
        for (; vector_index < table[array_index].size(); vector_index++) {
            if (table[array_index][vector_index].second.size() > 0) {
                auto itr = table[array_index][vector_index].second.begin();
                for (; itr != table[array_index][vector_index].second.end(); itr++) {
                    if (itr->first == date) {
                        if (itr->second == entry) {
                            std::cout << "Data already in log." << std::endl;
                            is_data_in_table = true;
                        }
                    }
                }
            }
        }

        if (is_data_in_table == false) {
            table[array_index][vector_index].second.emplace_back(date, entry);
        }
    }

    void remove(int password, std::string date) {

    }

    void print_log() {  // this still needs work
        int array_index{};
        for (int vector_index{}; vector_index < table[array_index].size(); vector_index++) {
            if (table[array_index].size() > 0) {
                if (table[array_index][vector_index].second.size() > 0) {
                    auto itr = table[array_index][vector_index].second.begin();
                    for (; itr != table[array_index][vector_index].second.end(); itr++) {
                        std::cout << "[DATE]: " << itr->first << std::endl;
                        std::cout << "[LOG]: " << itr->second << std::endl;
                    }
                }
            }
            array_index++;
        }
    }

    int hash_function(int password) {
        return password % size;
    }
    
};

} // namespace log

#endif // LOGGER.H