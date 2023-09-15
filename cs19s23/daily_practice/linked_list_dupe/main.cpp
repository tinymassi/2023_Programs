  // the point of this program is to create a linked list through
  // user input, and then have the program remove all the 
  // duplicates within the linked list

  #include <iostream>
  #include <string>
  #include "linked_list_dupe.h"
  
  int main() {
    std::cout << "Enter integer values to your linked list" << std::endl;
    std::cout << "Enter '00000' to finish entering." << std::endl; 

    LinkedList::LinkedList<int> mylist;

    int values = 0;
    while (std::cin >> values) {
        mylist.push_back(values);
        if (values == 00000) {
            break;
        }
    }


    return 0;
  }