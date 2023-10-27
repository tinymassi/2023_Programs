#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <list>

namespace hash {

template <typename T> class hash_map {

    private:
    
    static const int table_size{};  // whats with static const?
    std::list<std::pair<T, T>> table[table_size];  // how does a key other than an int work?

    public:

    bool is_table_empty() const {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() == 0) {
                return false;
            }
        }

        return true;
    }  // why const function what this mean?

    int hash_function (T key) {
        return key % table_size;  // how could this work with other data types that are not int?
    }

    void index_finder() {
        
    }

    void insert(T key, T data) {
        table_size++;
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
            table[index].push_back(key, data);
        }
    }

    void remove(T key) {
        int index = hash_function(key);
        auto& cell = table[key];
        auto iterator = std::begin(cell);
        bool is_item_gone = false;
        for (; itr != std::end(cell); itr++) {
            if (iterator->first == key) {
                iterator = cell.erase(iterator);
                is_item_gone = true;
                break;
            }
        }

        if (is_item_gone) {
            std::cout << "Data has been removed from the table." << std::endl;
        } else {
            std::cout << "Data was not found in table."
        }
    }

    T search_table(T key) {

    }

    void print_table() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() == 0) continue;
            auto& cell = table[i];
            auto iterator = std::begin(cell);
            for (;iterator != std::end(cell); iterator++) {
                std::cout << "KEY: " << iterator->first << "VALUE: " << iterator->second << std::endl;
            }
        }
        return;
    }

};

}  // namespace hash

#endif  // HASH_H