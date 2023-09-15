#ifndef LINKED_LIST_DUPE_H
#define LINKED_LIST_DUPE_H

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

    Node* remove(Node* position) {
    }

    void find_dupe() {
        Node* current = new Node();  // start current node in list
        current = head;  // set current at start of list
        T current_val = current->data;  // set the data we look for
        bool no_dupes = false;  // set to true when successfully removed dupes
        while (no_dupes) {  // think about this
            if (current->next->data = current_val) {
                remove(current->next);
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



}

#endif // LINKED_LIST_DUPE_H