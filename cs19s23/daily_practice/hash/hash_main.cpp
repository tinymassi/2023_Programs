#include <iostream>
#include <list>
#include <cstring>


// Hashtable to implement 3 digit phone # w/ names

class HashTable {
    private:
        static const int hashGroups = 10;
        std::list<std::pair<int, std::string>> table[hashGroups];  // List 1, Index 0, List 2, Index 1...

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, std::string value);
        void removeItem(int key);
        std::string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const {
    int sum;
    for (int i = 0; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (sum == 0) {
        return true;
    } else {
        return false;
    }
}

int HashTable::hashFunction (int key) {
    return key % hashGroups;  // gets the index thats embedded within the key
}

void HashTable::insertItem (int key, std::string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];  // create a reference to the list with the data in it
    auto bItr = std::begin(cell);  // iterator to the start of the list
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;  // replace the value in the list if updated version
            std::cout << "[WARNING] Key exists. Value replaced." << std::endl;
            break;
        }
    }

    if (!keyExists) {  // if there is no matching key at this index...
        // add the value with this key to the list at its respective index.
        cell.emplace_back(key, value);  // not sure what emplace back does. Is it a function of lists?
    }

    return;
}

void HashTable::removeItem (int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];  // create a reference to the list with the data in it
    auto bItr = std::begin(cell);  // iterator to the start of the list
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);  // returns the next iterator to bItr after removing data
            std::cout << "Item successfully removed." << std::endl;
            break;
        }
    }

    if (!keyExists) {
        std::cout << "Item not found in Hash Table. Item not removed" << std::endl;
    }

    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;  // skips the over code and moves to next iteration

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {  // move through the list to print stuff
            std::cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << std::endl;
        }
    }
    return;
}

int main() {
    HashTable my_hash_table;
    if (my_hash_table.isEmpty()) {
        std::cout << "The table is empty." << std::endl;
    }

    my_hash_table.insertItem(906, "Tom");
    my_hash_table.insertItem(302, "Hank");
    my_hash_table.insertItem(503, "Bob");
    my_hash_table.insertItem(709, "Tony");
    my_hash_table.insertItem(906, "Rick");

    my_hash_table.printTable();

    my_hash_table.removeItem(302);
    my_hash_table.removeItem(100);

    if (my_hash_table.isEmpty()) {
        std::cout << "The table is empty." << std::endl;
    } else {
        std::cout << "The hash table is not empty" << std::endl;
    }

    return 0;
}

 // contine watching C++ Hash Table Implementation by Coding Jesus on YT...