#include <iostream>
#include "data_tree.h"

int main() {

    search::tree<std::string> my_tree;
    // Level 1
    my_tree.create_node("works, ");
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