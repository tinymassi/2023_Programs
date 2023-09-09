#include <iostream>

class Node {
public:
    int val;
    Node* Next;
};

void print_list(Node* n) {
    while (n != NULL) {
        std::cout << n->val << std::endl;
        n = n->Next;
    }
}

void insertAtTheFront(Node** head, int new_val) {
    Node* newNode = new Node();
    newNode->val = new_val;
    newNode->Next = *head;
    *head = newNode;
}

int main(){

    // the head stores the head of the element in the list,
    // and it stores the address of the next element.
    // the next element has its value, and a pointer to the third address, and so on.
    // then, the last element will have a value and a nullptr.
    // advantage of linked lists is that they have dynamic size unlike arrays
    // random access of elements in a linked list is not allowed.
    // If you want to find the third element, you need to go down the ladder.
    
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->val = 1;
    head->Next = second;
    second->val = 2;
    second->Next = third;
    third->val = 3;
    third->Next = NULL;

    insertAtTheFront(&head, -1);
    print_list(head);
    
    return 0;
}