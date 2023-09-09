#include <iostream>
#include <vector>
#include <map>  // self balancing binary search tree, everything is in order/sorted.  can find elements by comparing them to other elements.
#include <unordered_map>  //  hashtable. uses hash function to figure out what your key lies in. faster than map. use this wherever possible.
#include <string>

using namespace std;

int main()
{

    cout << "Ordered Map Output: " << endl;
    cout << endl;

    // map<key, value> name; in this case, both our key and our value have type string in common
    map<string, string> myDictionary;  // This stores all the stuff below in alphabetical order

    // bascially saying we are going to have both key and element be string types and we have key "apple" and are looking for value "der Apfel" 
    // map_name.insert(pair<key_type, value_type>("key", "value"));
    myDictionary.insert(pair<string,string>("apple", "der Apfel"));
    myDictionary.insert(pair<string,string>("banana", "die Banane"));
    myDictionary.insert(pair<string,string>("orange", "die Orange, die Apfelsine"));
    myDictionary.insert(pair<string,string>("strawberry", "die Erdbeere"));

    // how to access specific value in map or change its value
    cout << myDictionary["strawberry"] << endl;

    // how to check size of your map
    cout <<  myDictionary.size() << endl;

    for (auto pair : myDictionary) {
        cout << pair.first << " - " << pair.second << endl;  // basically outputting everything in dictionary with the key first, then the value second 
    }

    cout << endl;
    cout << "Unordered Map Output: " << endl;
    cout << endl;

    unordered_map<string, string> myDictionary2;  // This stores all the stuff below in the order that they are inserted

    myDictionary2.insert(pair<string,string>("banana", "die Banane"));
    myDictionary2.insert(pair<string,string>("strawberry", "die Erdbeere"));
    myDictionary2.insert(pair<string,string>("apple", "der Apfel"));
    myDictionary2.insert(pair<string,string>("orange", "die Orange, die Apfelsine"));

    for (auto pair : myDictionary2) {
        cout << pair.first << " - " << pair.second << endl;
    }

    // how to clear all elements from your map
    myDictionary.clear();

    // how to remove a specific element in your map 
    myDictionary.erase("apple");
}


