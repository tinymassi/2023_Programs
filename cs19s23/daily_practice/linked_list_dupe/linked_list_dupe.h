#ifndef LINKED_LIST_DUPE_H
#define LINKED_LIST_DUPE_H
#include <vector>

namespace LinkedList {

template <typename T> class LinkedList {
    struct Node;
    public:

    LinkedList(){  // default constructor
    }

    void push_back(T input_data) {  // takes data from user and puts it in list
        Node* new_tail = new Node();  // create new Node* obj new_tail
        new_tail->data = input_data;  // make Node new_tail store data
        new_tail->prev = tail;  // assign the current tail as previous to new tail
        new_tail->next = nullptr;  // after new tail is end of linked list
        if (tail != nullptr) {  // if the tail exists...
            tail->next = new_tail;  // make tails next be new tail to patch gap
        }
        if (head == nullptr) {  // if there is nothing in list...
            head = new_tail;  // make the head be equal to the new tail
        }
        tail = new_tail;  // mark the tail Node* as new_tail
    }

    std::vector<T> return_list(std::vector<T>& list) {
        Node* current = head;
        while (current->next != nullptr) {
            list.push_back(current->data);
            current = current->next;
        }

        return list;
    }

    void pop_back() {  // this doesnt work maybe make pop_back, pop_front, pop_mid functions?
        Node* new_tail = new Node();
        new_tail = tail;
        if (new_tail->prev == nullptr) {
            delete tail;
        } else {
            new_tail = tail->prev;
            new_tail->next = nullptr;
            delete tail;
        }
        tail = new_tail;
    }

    // Node* pop_mid(Node* position) {

    // }

    void pop_front() {
        Node* new_head = new Node();
        new_head = head;
        if (head->next == nullptr) {
            delete head;
        } else {
            new_head = head->next;
            new_head->prev = nullptr;
            delete head;
        }
        head = new_head;
    }

    void find_dupe(T target_val) {  // this doesnt work
        Node* current = new Node();
        while (current->next != nullptr) {
            if (current->data == target_val) {
                remove(current);
            }
            current = current->next;
        }
    }


    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;
        };
        Node* head = nullptr;
        Node* tail = nullptr;
};


}  // namespace LinkedList

#endif // LINKED_LIST_DUPE_H