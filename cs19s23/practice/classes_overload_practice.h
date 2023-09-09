#include <iostream>
#include <vector>

#ifndef _CLASSES_OVERLOAD_PRACTICE_H
#define _CLASSES_OVERLOAD_PRACTICE_H

namespace cop {
    class practice {
        public:
        int multiply(int);
        int operator~();
        int operator+(std::vector <int>);

        private:
        int num = 5;
    };
}

#endif  //  _CLASSES_OVERLOAD_PRACTICE_H