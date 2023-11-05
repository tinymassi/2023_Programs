#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <list>
#include <vector>
#include <cstring>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

namespace hash {

template <typename T> class hash_map {

    private:

    static const int table_size = 1000;
    std::list<std::pair<int, T>> table[table_size];  // how does a key other than an int work?

    public:

    bool is_table_empty() const {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() == 0) {
                return false;
            }
        }

        return true;
    }  // why const function what this mean?

    int hash_function (int key) {
        return key % table_size;  // how could this work with other data types that are not int?
    }

    void insert(int key, T data) {  // first load the vector with some indexes so no floating point exemption?
        int index = hash_function(key);  // get index of data
        auto& cell = table[index];  // start at location of index
        auto iterator = std::begin(cell);  // make iterator to beginning of that cell
        bool is_data_in_hash = false;
        for (; iterator != std::end(cell); iterator++) {
            if (iterator->first == key) {
                if (iterator->second == data) {
                    is_data_in_hash = true;
                }
            }
        }

        if (is_data_in_hash) {
            std::cout << RED << "Data is already in hash map" << RESET << std::endl;
        } else {
            std::cout << GREEN << "Data has been added to the hash map" << RESET << std::endl;
            table[index].emplace_back(key, data);
        }
        std::cout << std::endl;
    }

    void remove(int key, T value) {
        int index = hash_function(key);
        auto& cell = table[key];
        auto iterator = std::begin(cell);
        bool is_item_gone = false;
        for (; iterator != std::end(cell); iterator++) {
            if (iterator->first == key) {
                if (iterator->second == value) {
                    iterator = cell.erase(iterator);
                    is_item_gone = true;
                    break;
                }
            }
        }

        if (is_item_gone) {
            std::cout << GREEN << "Data has been removed from the table." << RESET << std::endl;
        } else {
            std::cout << RED << "Data was not found in table." << RESET << std::endl;
        }
    }

    void search_table(int key, T value) {
        T data;
        int index = hash_function(key);
        auto& cell = table[index];
        auto iterator = std::begin(cell);

        for (; iterator != std::end(cell); iterator++) {
            if (iterator->first == key) {
                if (iterator->second == value) {
                    std::cout << GREEN << "I found the this data in the table" << RESET << std::endl;
                }
            }
        }

        std::cout << RED << "This key has no pair in the table or doesnt exist." << RESET << std::endl;

        return;
    }

    void print_table() {
        for (int i = 0; i < table_size; i++) {
            if (table[i].size() == 0) continue;
            auto& cell = table[i];
            auto iterator = std::begin(cell);
            for (;iterator != std::end(cell); iterator++) {
                std::cout << GREEN << "KEY: " << RESET << iterator->first << GREEN << " VALUE: " << RESET << iterator->second << std::endl;
                std::cout << std::endl;
            }
        }
        return;
    }

};

}  // namespace hash

#endif  // HASH_H