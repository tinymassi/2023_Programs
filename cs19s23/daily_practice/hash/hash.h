#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <list>

namespace hash {

template <typename T> class hash_map {

    private:
    
    static const int table_size{};  // whats with static const?
    std::list<std::pair<T, T>> table;

    public:

    bool is_table_empty() const {

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