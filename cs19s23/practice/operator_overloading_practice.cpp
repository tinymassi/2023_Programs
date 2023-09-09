#include <iostream>

class Position{
public:
    int x = 15;
    int y = 20;
    Position operator + (Position pos) { 
        Position new_pos;
        new_pos.x = x + pos.x;
        new_pos.y = y + pos.y;

        return new_pos;
    }
    bool operator == (Position pos) {
        if (x == pos.x && y == pos.y) {
            return true;
        } else {
            return false;
        }
    }

private:
};

class Test {
    int x;
public:
    Test(int x = 0):x{x} {}
    friend std::istream& operator >> (std::istream& input, Test& obj);
    friend std::ostream& operator << (std::ostream& output, Test& obj);
};

std::istream& operator >> (std::istream& input, Test& obj) {
    input >> obj.x;
    return input;
}

std::ostream& operator << (std::ostream& output, Test& obj) {
    output << "[";
    for (int i = 0; i < 10; i++) {
        output << obj.x << " , ";
    }
    output << "]";
    return output;
}

int main() {

    Position pos1, pos2;
    Position pos3 = pos1 + pos2;  // so when the '+' operator is used in this case, pos1 is the instance of the class Position, and pos2 is thrown in the operator overloader constructor!
                                  // its really like how functions work.
    std::cout << pos3.x << std::endl;
    std::cout << pos3.y << std::endl;

    Position pos4, pos5;
    // pos4.x = 50;
    bool equals = pos4 == pos5;
    if (equals) {
        std::cout << "Both the objects have matching x and y member variables." << std::endl;
    } else {
        std::cout << "The objects do not have matching member variables." << std::endl;
    }

    Test t;
    std::cin >> t;
    std::cout << t;

    return 0;
}