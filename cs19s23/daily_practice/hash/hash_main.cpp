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

 // contine watching C++ Hash Table Implementation by Coding Jesus on YT...