#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <list>

namespace hash {

template <typename T> class hash_map {

    private:
    
    static const int table_size{};  // whats with static const?
    std::list<std::pair<T, T>> table[table_size];

    public:

    bool is_table_empty() const {
        bool is_empty = false;
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() == 0) {
                return false;
            }
        }

        return true;
    }  // why const function what this mean?

    void index_finder() {

    }

    void insert(T key, T data) {

    }

    void remove(T key) {

    }

    T search_table(T key) {

    }

    void print_table() {

    }

};

}  // namespace hash

#endif  // HASH_H