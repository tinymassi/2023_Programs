#include <iostream>
#include "classes_overload_practice.h"
#include <vector>

int main(){

    cop::practice obj;
    
    std::vector <int> myVect{1,1,1,1};
    std::vector <int> myVect2{1,1,1,1};

    int vector_add = myVect + obj;

    int a = 1;

    int b = obj.multiply(a);

    int tilda = ~obj;

    
}
