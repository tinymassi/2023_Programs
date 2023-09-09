#include <iostream>
#include <set>

int main(){
    std::set<char> s1 = {'D', 'C', 'D', 'C'};  // the set will only display c and d because the set only cares if something exists.

    s1.insert('B');  // to add something to the set
    s1.erase('C');  // how to erase something from a set

    if (s1.find('C') == s1.end()){
        std::cout << "This element does not exist in the set." << std::endl; 
    } else {
        std::cout << "Found C!" << std::endl;
    }

    for (auto itr = s1.begin(); itr != s1.end(); ++itr){
        std::cout << *itr << std::endl;
    }

    std::string test = "hhhaaaammmmbbbbuuurrrgggggggeeeeeeerrrrr";
    std::string find = "hamburger";
    std::set<char> exists;

    for (int i = 0; i < test.length(); ++i){
        char letter = test[i];
        exists.insert(letter);
    }

    int i = 0;
    int no = 0;
    int yes = 0;
    for (auto itr = exists.begin(); itr != exists.end(); ++itr, ++i){
        if (exists.find(find[i]) != exists.end()){
            std::cout << "The letter '" << find[i] << "' is in the set 'test'." << std::endl;
            yes++;
        }
    }
    if (yes == find.length()){
        std::cout << "All the characters of the string '" << find << "' are in the set!" << std::endl; 
    } else {
        std::cout << "Not all of the letters of the string '" << find << "' are in the set." << std::endl;
    }

    std::string test2 = "hamburger";
    std::set<std::string> set_test;

    set_test.insert(test2);
    for (auto iter = set_test.begin(); iter != set_test.end(); ++iter){
        if (test2[iter] == )
            std::cout << *iter << std::endl;
    }
}