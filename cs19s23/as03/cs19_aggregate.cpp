#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "cs19_aggregate.h"

int main(){

    // //ALL MUST BE TRUE

    if (cs19::all(std::string("CS_19")) == true){ //Should be true [GOOD]
        std::cout << "This is true" << std::endl;
    } else {
        std::cout << "This is false" << std::endl;
    }

    if (cs19::all(std::vector<int>{2, 4, 6, 0, 1}) == true){ //Should be false [GOOD]
        std::cout << "This is true" << std::endl;
    } else {
        std::cout << "This is false" << std::endl;
    }

    if (cs19::all(std::vector<bool>{true, true, false, true}) == true){  //Should be false [GOOD]
        std::cout << "This is true" << std::endl;
    } else {
        std::cout << "This is false" << std::endl;
    }

    std::cout << std::endl;
    // //ANY CAN BE TRUE

    if (cs19::any(std::string("CS 19!")) == true){ //Should be true [GOOD]
        std::cout << "This is true" << std::endl;
    } else {
        std::cout << "This is false" << std::endl;
    }

    if (cs19::any(std::vector<int>{2, 4, 6, 0, 1}) == true){ //Should be true [GOOD]
        std::cout << "This is true" << std::endl;
    } else {
        std::cout << "This is false" << std::endl;
    }

    if (cs19::any(std::vector<bool>{false, false, false, false}) == true){  //Should be false [GOOD]    
        std::cout << "This is true" << std::endl;
    } else {
        std::cout << "This is false" << std::endl;
    }
    
    std::cout << (cs19::max(std::vector<char>{'z','A','c','d','e','f','g'})) << std::endl; //Should display z [GOOD]
    std::cout << (cs19::max(std::vector<double>{1.0,10.3,11.0,23.0,54.0,34.0})) << std::endl; //Should display 54 [GOOD]
    std::cout << (cs19::min(std::vector<char>{'a','b','c','d','e','f','g'})) << std::endl; //Should diplay 'a' [BAD]
    std::cout << (cs19::min(std::string{"abcdefg"})) << std::endl; //Should display 'a' [BAD]
    std::cout << (cs19::max(std::string{"abcdefg"})) << std::endl; //Should display 'g' [GOOD]



    // std::cout << (cs19::max(std::vector<int>{2, 4, 6, 0, 1})) << std::endl; //should equal 6 [GOOD]
    // std::cout << (cs19::min(std::vector<int>{2, 4, 6, 0, 1})) << std::endl; //should equal 0 [GOOD]
    std::cout << (cs19::sum(std::string("CS 19!"), 0)) << std::endl; //should equal 321 [GOOD]
    std::cout << (cs19::sum(std::vector<int>{2, 4, 6, 0, 1}, 0.0)) << std::endl; //should equal 13.0 [MAYBE?]

}