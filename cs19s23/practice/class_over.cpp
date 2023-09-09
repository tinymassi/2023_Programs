#include "classes_overload_practice.h"
#include <vector>

namespace cop {
    int practice::multiply(int A){
        return A * num;
    }

    int practice::operator+(std::vector <int> A){
        int total = 0;
        for (int i = 0; i < A.size(); i++){
            total += A[i];
        }

        return total + num;
    }

    int practice::operator~(){
        return -num;
    }
}