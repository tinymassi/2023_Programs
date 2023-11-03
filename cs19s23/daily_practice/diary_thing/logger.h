#ifndef LOGGER.H
#define LOGGER.H
#include <iostream>
#include <vector>
#include <string>
#include <list>

namespace log {

class log {

    private:
    int static const size = 1000;
    std::vector<std::vector<std::pair<int, std::list<std::pair<std::string, std::string>>>>> table [size];

    public:

    void insert(int password, std::string date, std::string entry) {
        int index = hash_function(password);
        bool is_data_in_table = false;
        int i = 0;
        for (; i < table[index].size(); i++) {
            if (table[index][i].size() > 0) {
                auto itr = table[index][i].second.begin();
                for (; itr != table[index][i].second.end(); itr++) {
                    if (itr->first-> == date) {
                        if (itr->second == entry) {
                            std::cout << "Data already in log." << std::endl;
                            is_data_in_table = true;
                        }
                    }
                }
            }
        }

        if (is_data_in_table == false) {
            table[index][i].emplace_back(date, entry);
        }

    }

    void remove(int password, std::string date) {

    }

    void print_log() {

    }

    int hash_function(int password) {
        return password % size;
    }
    
};

} // namespace log

#endif // LOGGER.H