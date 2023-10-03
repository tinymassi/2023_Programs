#include <iostream>

    // the root node is a node that doesnt have a parent
    // can only have 1 root node but multiple leaf nodes
    // a leaf node is a node that has no children
    // parent is a node with children
    // a binary tree basically is that a node cannot have more than 2 children
    // a binary search tree (BST) is like a binary tree but the nodes are 
    // organized in a certain way
    // DFS Depths first search
    // BFS Breadth first search

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

void printTree (Node* root) {  // Preorder algorithm kinda makes sense...

    if (root == nullptr) return;  // node we are on is null end this recursion

    std::cout << root->data << std::endl;  // print data
    printTree(root->left_child);  // print all left childs until nullptr
    printTree(root->right_child);  // print all right childs until nullptr
}

int main() {
    // Level 1
    Node* root = create_node(1);
    // Level 2
    root->left_child = create_node(2);
    root->right_child = create_node(3);
    // Level 3
    root->left_child->left_child = create_node(4);
    root->left_child->right_child = create_node(5);
    root->right_child->right_child = create_node(7);
    root->right_child->left_child = create_node(6);
    // Level 4
    root->left_child->right_child->left_child = create_node(9);
    root->right_child->right_child->left_child = create_node(15);

    printTree(root);
    

    return 0;
}