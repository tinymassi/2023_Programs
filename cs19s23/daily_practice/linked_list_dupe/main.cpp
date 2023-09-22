  // the point of this program is to create a linked list through
  // user input, and then have the program remove all the 
  // duplicates within the linked list

  #include <iostream>
  #include <string>
  #include "linked_list_dupe.h"
  #include <vector>
  
  int main() {
    std::cout << "Enter integer values to your linked list" << std::endl;
    std::cout << "Enter 'Stop' to finish entering." << std::endl; 

    LinkedList::LinkedList<std::string> mylist;

    std::string values;
    while (std::cin >> values) {
        mylist.push_back(values);
        if (values == "Stop") {
            break;
        }
    }

    std::cout << "Enter data value you want to delete: " << std::endl;
    std::string data;
    std::cin >> data;
    mylist.find_dupe(data);

    std::vector<std::string> list;
    std::string entry;
    int k = 1;
    std::cout << "Would you like to see your list? (y/n)" << std::endl;
    std::cin >> entry;
    if (entry == "y") {
      list = mylist.return_list(list);
      for (auto i : list) {
        if (k == 1) {
          std::cout << "Your linked list is:" << std::endl;
          std::cout << "[ " << i << ", ";
        } else if (k < list.size()) {
          std::cout << i << ", ";
        } else {
          std::cout << i << " ]" << std::endl;
        }
        k++;
      }
    }

    return 0;
  }