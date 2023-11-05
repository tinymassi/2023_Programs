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

    log() {
        int password {};
        std::string date {};
        std::string entry {};
        bool user_input = true;
        std::string input;
        while (user_input) {
            std::cout << GREEN << "What would you like to do with your journal?" << RESET << '\n';
            std::cout << GREEN << "Enter anything other than a, b, & c to exit." << RESET << '\n';
            std::cout << '\n';
            std::cout << "a) Make an entry   b) See your entries   c) Remove an entry" << '\n';
            std::cout << "> ";
            std::cin >> input;
            std::cout <<'\n';
            if (input == "a") {
                std::cout << "Enter your password: ";
                std::cin >> password;
                std::cout << '\n';
                std::cout << "Enter todays date: ";
                std::cin >> date;
                std::cout << '\n';
                std::cout << "Write your entry: " << '\n';
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, entry);
                insert(password, date, entry);
                std::cout << std::endl;
            } else if (input == "b") {
                print_log();
            } else if (input == "c") {
                std::cout << "Enter your password: ";
                std::cin >> password;
                std::cout << std::endl;
                std::cout << "Enter the date of the entry you wish to remove: ";
                std::cin >> date;
                remove(password, date);
            } else {
                user_input = false;
            }
        std::cout << std::endl;
        }
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

    void print_log() {  // change so it is specific to a password
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