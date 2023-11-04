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
        std::list<std::pair<std::string, std::string>> empty_list;
        int array_index = hash_function(password);
        bool is_data_in_table = false;
        int vector_index{};
        table[array_index].push_back(std::make_pair(password, empty_list));
        if (table[array_index].size() > 0) {
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
            break;
            }
        }

        if (!is_data_in_table) {
            table[array_index][vector_index].second.emplace_back(date, entry);
            std::cout << "Data was added to log!" << std::endl;
        }
    }

    void remove(int password, std::string date) {

    }

    void print_log() {  // this still needs work
        std::list<std::pair<std::string, std::string>> empty_list;
        int array_index{};
        int vector_index{};
        bool valid = true;
        while (valid) {
            if (table[array_index].size() > 0) {
                for (; vector_index < table[array_index].size(); vector_index++) {
                    if (table[array_index][vector_index].second.size() > 0) {
                        auto itr = table[array_index][vector_index].second.begin();
                        for (; itr != table[array_index][vector_index].second.end(); itr++) {
                            std::cout << "[DATE]: " << itr->first << std::endl;
                            std::cout << std::endl;
                            std::cout << "[LOG]: " << std::endl;
                            std::cout << itr->second << std::endl;
                        }
                    } 
                }
            }
            array_index++;
            vector_index = 0;
            if (array_index == 1000) {
                valid = false;
            }
        } 
    }

    int hash_function(int password) {
        return password % size;
    }
    
};

} // namespace log

#endif // LOGGER.H