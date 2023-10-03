#include <iostream>

    // the root node is a node that doesnt have a parent
    // can only have 1 root node but multiple leaf nodes
    // a leaf node is a node that has no children
    // parent is a node with children
    // a binary tree basically is that a node cannot have more than 2 children
    // a binary search tree (BST) is like a binary tree but the nodes are 
    // organized in a certain way

struct Node {
    int data;
    Node* left_child;
    Node* right_child;
};

Node* create_node (int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left_child = nullptr;
    new_node->right_child = nullptr;
    // or new_node->left_child = new_node->right_child = nullptr;
    return new_node;
}

int main() {

    

    return 0;
}