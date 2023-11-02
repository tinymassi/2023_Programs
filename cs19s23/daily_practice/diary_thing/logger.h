#ifndef LOGGER.H
#define LOGGER.H
#include "vector"

namespace log {

template <typename T> class log {

    private:
    int static const size = 1000;
    std::vector<std::vector<std::pair<int, std::list<std::pair<std::string, std::string>>>>> [size];

    public:

    void insert(int password, std::string date, std::string entry) {

    }

    void remove(int password, std::string date) {

    }

    void print_log() {

    }

    int hash_function(int password) {

    }
    
};

} // namespace log

#endif // LOGGER.H