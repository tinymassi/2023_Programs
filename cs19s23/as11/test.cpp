 #include <iostream>
 #include "cs19_linked_list_raw_pointers.h"

 int main () {
    cs19::LinkedList<char> list;

    //list.resize(3,'b');
    std::cout << list << '\n';

    for (auto c : std::string("")) {
        list.push_back(c);
    }
    //list.resize(1);

    //list.resize(3, 'b');
    //std::cout << list << std::endl;
   cs19::LinkedList<char> list1;
    
    for (auto c : std::string("")) {
        list1.push_back(c);
    }

    if (list == list1) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }

    std::cout << list << '\n';
    //list.pop_back();
    list.reverse();
    std::cout << list << '\n';

    cs19::LinkedList<char> copy = list;
    copy.resize(10, '!');
    list.remove('o');
    copy.unique();
    std::cout << list << '\n' << copy << '\n';
 }