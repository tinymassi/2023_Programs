#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <list>
#include <vector>

namespace hash {

template <typename T> class hash_map {

    private:
    
    // int table_size{};  // whats with static const?
    std::vector<std::list<std::pair<int, T>>> table;  // how does a key other than an int work?

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
        return key % table.size();  // how could this work with other data types that are not int?
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
            std::cout << "Data is already in hash map" << std::endl;
        } else {
            std::cout << "Data has been added to the hash map" << std::endl;
            table[index].emplace_back(key, data);
        }
    }

    void remove(int key) {
        int index = hash_function(key);
        auto& cell = table[key];
        auto iterator = std::begin(cell);
        bool is_item_gone = false;
        for (; iterator != std::end(cell); iterator++) {
            if (iterator->first == key) {
                iterator = cell.erase(iterator);
                is_item_gone = true;
                break;
            }
        }

        if (is_item_gone) {
            std::cout << "Data has been removed from the table." << std::endl;
        } else {
            std::cout << "Data was not found in table." << std::endl;
        }
    }

    T search_table(int key) {
        T data;
        int index = hash_function(key);
        auto& cell = table[index];
        auto iterator = std::begin(cell);

        for (; iterator != std::end(cell); iterator++) {
            if (iterator->first == key) {
                return iterator->second;
            }
        }

        return "This key has no pair in the table or doesnt exist.";
    }

    void print_table() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() == 0) continue;
            auto& cell = table[i];
            auto iterator = std::begin(cell);
            for (;iterator != std::end(cell); iterator++) {
                std::cout << "KEY: " << iterator->first << " VALUE: " << iterator->second << std::endl;
            }
        }
        return;
    }

};

}  // namespace hash

#endif  // HASH_H