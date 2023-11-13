#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

namespace mcg {

class log {

    private:

    int static const size = 1000;
    std::vector<std::pair<int, std::list<std::pair<std::string, std::string>>>> table [size];

    public:

      // TODO: Serialization of the data in this program? turn it into binady data instead of saving as a data type
      // save it in a known configuration. Utilizing iterators for this could help

      // TODO: Use a text file to send all the data to.
      // pipe information to text file
      // format the text file in a way that the program can read and understand
      // pipe the data from the text file into my logger.h
      // encrypt the data! then decrypt it!
      // use a library for encryption and decyption. There are tons of these. crypt.h, libcrypto
      // check open SSL for this stuff ^


    log() {  // TODO: Make the program save the entries
        int int_password {};  
        std::string str_password {};
        std::string date {};
        std::string entry {};
        std::string terminal_entry{};
        std::string input{};
        bool user_input = true;
        bool check = false;
        while (user_input) {
            std::cout << GREEN << "What would you like to do with your journal?" << RESET << '\n';
            std::cout << GREEN << "Enter anything other than a, b, & c to exit." << RESET << '\n';
            std::cout << '\n';
            std::cout << "a) Make an entry   b) See your entries   c) Remove an entry" << '\n';
            std::cout << "> ";
            std::cin >> input;
            std::cout <<'\n';
            if (input == "a") {
                while (!check) {
                    std::cout << "Enter your password: ";
                    std::cin >> str_password;
                    if (is_password_valid(str_password)) {
                        check = true;
                        int_password = std::stoi(str_password);
                    } else {
                        check = false;
                        std::cout << '\n';
                        std::cout << RED << "Password invalid. Try again." << RESET << '\n';
                        std::cout << '\n';
                    }
                }
                check = false;
                while (!check) {
                    std::cout << "Enter todays date (MM/DD/YY): ";
                    std::cin >> date;
                    if (is_date_valid(date)) {
                        check = true;
                    } else {
                        check = false;
                        std::cout << '\n';
                        std::cout << RED << "Date invalid. Try again." << RESET << '\n';
                        std::cout << '\n';
                    }
                }
                std::cout << '\n';
                std::cout << "Write your entry: " << '\n';
                std::cout << "To finish writing, type 'End' at the bottom: " << '\n';
                std::cout << '\n';
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                while (true) {
                    std::getline(std::cin, terminal_entry);
                    if (terminal_entry == "End" || terminal_entry == "end") {
                        break;
                    } else {
                        entry += "\n";
                        entry += terminal_entry;
                    }
                }
                insert(int_password, date, entry);
                entry = "";
                terminal_entry = "";
            } else if (input == "b") {
                while (!check) {
                    std::cout << "Enter your password to view your entries: ";
                    std::cin >> str_password;
                    if (is_password_valid(str_password)) {
                        check = true;
                        int_password = std::stoi(str_password);
                    } else {
                        check = false;
                        std::cout << '\n';
                        std::cout << RED << "Password invalid. Try again." << RESET << '\n';
                        std::cout << '\n';
                    }
                }
                print_user_log(int_password);
            } else if (input == "c") {
                while (!check) {
                    std::cout << "Enter your password: ";
                    std::cin >> str_password;
                    if (is_password_valid(str_password)) {
                        check = true;
                        int_password = std::stoi(str_password);
                    } else {
                        check = false;
                        std::cout << '\n';
                        std::cout << RED << "Password invalid. Try again." << RESET << '\n';
                        std::cout << '\n';
                    }
                }
                check = false;
                while (!check) {
                    std::cout << "Enter the date (MM/DD/YY) of the entry you wish to remove: ";
                    std::cin >> date;
                    if (is_date_valid(date)) {
                        check = true;
                    } else {
                        check = false;
                        std::cout << '\n';
                        std::cout << RED << "Date invalid. Try again." << RESET << '\n';
                        std::cout << '\n';
                    }
                }
                remove(int_password, date);
            } else {
                user_input = false;
            }
        std::cout << std::endl;
        check = false;
        }
    }

    bool is_password_valid (std::string password) {
        for (int i = 0; i < password.size(); i++) {
            if (password[i] >= '0' && password[i] <= '9') {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }

    bool is_date_valid (std::string date) {  // add this to check validity of entries
        if (date.size() == 8) {
            for (int i = 0; i < date.size(); i++) {
                if (i != 2 && i != 5) {
                    if (date[i] >= '0' && date[i] <= '9') {
                        continue;
                    } else {
                        return false;
                    }
                } else if (i == 2 && i == 5) {
                    if (date[i] != '/') {
                        return false;
                    }
                }
            }
        } else {
            return false;
        }
        return true;
    }

    void insert(int password, std::string date, std::string entry) {
        std::list<std::pair<std::string, std::string>> empty_list;
        int array_index = hash_function(password);
        bool is_data_in_table = false;
        int vector_index{};
        table[array_index].push_back(std::make_pair(password, empty_list));
        if (table[array_index].size() > 0) {
            for (; vector_index < table[array_index].size(); vector_index++) {
                if (table[array_index][vector_index].second.size() > 0) {
                    auto itr = table[array_index][vector_index].second.begin();
                    for (; itr != table[array_index][vector_index].second.end(); itr++) {
                        if (itr->first == date) {
                            if (itr->second == entry) {
                                std::cout << "Data already in log." << '\n';
                                is_data_in_table = true;
                            }
                        }
                    }
                } 
            break;
            }
        }

        if (!is_data_in_table) {
            table[array_index][vector_index].second.emplace_back(date, entry);
            std::cout << '\n';
            std::cout << GREEN << "Data was added to log!" << RESET << '\n';
        }
    }

    void remove(int password, std::string date) {
        int array_index = hash_function(password);
        bool was_data_removed = false;
        int vector_index{};
        
        for (; vector_index < table[array_index].size(); vector_index++) {
            if (table[array_index][vector_index].second.size() > 0) {
                auto itr = table[array_index][vector_index].second.begin();
                for (; itr != table[array_index][vector_index].second.end(); itr++) {
                    if (itr->first == date) {
                        itr = table[array_index][vector_index].second.erase(itr);
                        std::cout << GREEN << "Data from " << date << " has been removed." << RESET << '\n';
                        was_data_removed = true;
                    }
                }
            }
        break;
        }

        if (!was_data_removed) {
            std::cout << RED << "Data from " << date << " is not in the log." << RESET << '\n';
        }
    }

    void print_user_log(int password) {
        int array_index = hash_function(password);
        int vector_index{};
        bool something_printed = false;
        
        for (; vector_index < table[array_index].size(); vector_index++) {
            if (table[array_index][vector_index].second.size() > 0) {
                auto itr = table[array_index][vector_index].second.begin();
                for (; itr != table[array_index][vector_index].second.end(); itr++) {
                    std::cout << '\n';
                    std::cout << GREEN << "+-----------------------------+" << RESET << '\n';
                    std::cout << GREEN << "[DATE]: " << RESET << '\n';
                    std::cout << itr->first << '\n';
                    std::cout << '\n';
                    std::cout << GREEN << "[LOG]: " << RESET;
                    std::cout << itr->second << '\n';
                    std::cout << GREEN << "+-----------------------------+" << RESET << '\n';
                    std::cout << '\n';
                    something_printed = true;
                }
            }
        break;
        }

        if (!something_printed) {
            std::cout << '\n';
            std::cout << RED << "There are no entries under this password." << RESET << '\n';
            std::cout << '\n';
        }
    }

    void print_entire_log() {  // prints out the entire hash map
        int array_index{};
        int vector_index{};
        bool valid = true;
        bool something_printed = false;
        while (valid) {
            if (table[array_index].size() > 0) {
                for (; vector_index < table[array_index].size(); vector_index++) {
                    if (table[array_index][vector_index].second.size() > 0) {
                        auto itr = table[array_index][vector_index].second.begin();
                        for (; itr != table[array_index][vector_index].second.end(); itr++) {
                            std::cout << '\n';
                            std::cout << GREEN << "+-----------------------------+" << RESET << '\n';
                            std::cout << GREEN << "[DATE]: " << RESET << '\n';
                            std::cout << itr->first << '\n';
                            std::cout << '\n';
                            std::cout << GREEN << "[LOG]: " << RESET << '\n';
                            std::cout << itr->second << '\n';
                            std::cout << GREEN << "+-----------------------------+" << RESET << '\n';
                            std::cout << '\n';
                            something_printed = true;
                        }
                    } 
                }
            }
            array_index++;
            vector_index = 0;
            if (array_index == 1000) {
                valid = false;
            }
        }
        
        if (!something_printed) {
            std::cout << '\n';
            std::cout << RED << "There are no entries under this password." << RESET << '\n';
            std::cout << '\n';
        }
    }

    int hash_function(int password) {
        return password % size;
    }
    
};

} // namespace log

#endif // LOGGER.H