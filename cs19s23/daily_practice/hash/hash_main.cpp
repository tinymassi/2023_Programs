#include <iostream>
#include <list>
#include <cstring>


// Hashtable to implement 3 digit phone # w/ names

class HashTable {
    private:
        static const int hashGroups = 10;
        std::list<std::pair<int, std::string>> table[hashGroups];  // List 1, Index 0, List 2, Index 1...
        // what does this list look like as a data structure?

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

int HashTable::hashFunction (int key) {  // what is the point of this function?
    return key % hashGroups; 
}

void HashTable::insertItem (int key, std::string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];  // what?
    auto bItr = begin(cell);  // what??
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            break;
        }
    }
}

 // contine watching C++ Hash Table Implementation by Coding Jesus on YT...