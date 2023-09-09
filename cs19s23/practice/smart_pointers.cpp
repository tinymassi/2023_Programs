#include <iostream>
#include <memory>


template <typename T>
class myClass {
    struct Node;

    public:
    myClass(T filler) {
        unptr = std::make_unique<Node>(Node{filler});
        std::cout << unptr->val << std::endl;
    }
    ~myClass() {
        std::cout << "Destructor Invoked" << std::endl;
    }
    void print() {
        std::cout << this->value << std::endl;
    }

    private:
    struct Node {
        T val;
        Node* head = nullptr;
        Node* tail = nullptr;
    };
    std::unique_ptr<Node> unptr;
};

int main() {

    myClass<int> obj {7};

    // **ALL PTRS**
    // {
    //     std::unique_ptr<myClass> entity = std::make_unique<myClass>();
    //     entity->print();
    // }

    // {
    //     std::weak_ptr<myClass> e0;
    //     {
    //         std::shared_ptr<myClass> entity_shared = std::make_shared<myClass>();
    //         e0 = entity_shared;
    //     }
    // }
    
    // **UNIQUE POINTERS**
    // {
    //     std::unique_ptr<myClass>unPtr1 = std::make_unique<myClass>();  // when this goes out of scope, it deletes
    // }
    // std::unique_ptr<int>unPtr1 = std::make_unique<int>(25);  // definition of a unique ptr
    // std::unique_ptr<int>unPtr2 = move(unPtr1);  // shifted ownership of unPtr1. Once this happens, unPtr1 is nullptr

    // **SHARED POINTERS**
    // {
    //     std::shared_ptr<myClass>shPtr1 = std::make_shared<myClass>();  // allows multiple owners for raw pointer
    //     std::cout << "Shared Count: " << shPtr1.use_count() << std::endl;
    //     {
    //         std::shared_ptr<myClass>shPtr2 = shPtr1;
    //         std::cout << "Shared Count: " << shPtr2.use_count() << std::endl;  // .use_count() returns the num of owners of raw ptr
    //     }
    //     std::cout << "Shared Count: " << shPtr1.use_count() << std::endl;
    // }

    // **WEAK POINTERS**
    // std::weak_ptr<int> wePtr1;  // relies on strong ptrs to keep them alive. if there are no more shared pointers, it dies.
    // {
    //     std::shared_ptr<int> shPtr1 = std::make_shared<int>(25);
    //     wePtr1 = shPtr1;
    // }
}