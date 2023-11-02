#ifndef LOGGER.H
#define LOGGER.H
#include "vector"

namespace log {

template <typename T> class log {
    int static const size = 10000;
    std::vector<std::vector<std::pair<int, std::list<std::pair<std::string, std::string>>>>> [size];
};

} // namespace log

#endif // LOGGER.H