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
    std::string data;
    Node* left_child;
    Node* right_child;
};

Node* create_node (std::string data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left_child = nullptr;
    new_node->right_child = nullptr;
    // or new_node->left_child = new_node->right_child = nullptr;
    return new_node;
}

void printTree_pre (Node* root) {  // Preorder algorithm kinda makes sense...

    if (root == nullptr) return;  // node we are on is null end this recursion

    std::cout << root->data;  // print data
    printTree_pre(root->left_child);  // print all left childs until nullptr
    printTree_pre(root->right_child);  // print all right childs until nullptr
}

void printTree_in (Node* root) {  // inorder algorithm

    if (root == nullptr) return;  // node we are on is null end this recursion

    printTree_in(root->left_child);
    std::cout << root->data;
    printTree_in(root->right_child);
}

int main() {
    // Level 1
    Node* root = create_node("works, ");
    // Level 2
    root->left_child = create_node("in-");
    root->right_child = create_node("sentence ");
    // Level 3
    root->left_child->left_child = create_node("If ");
    root->left_child->right_child = create_node("function ");
    root->right_child->right_child = create_node("sense.");
    root->right_child->left_child = create_node("this ");
    // Level 4
    root->left_child->right_child->left_child = create_node("order ");
    root->right_child->right_child->left_child = create_node("makes ");

    // printTree_pre(root);
    // std::cout << std::endl;
    printTree_in(root);
    std::cout << std::endl;
    

    return 0;
}