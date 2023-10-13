#ifndef DATA_TREE_H
#define DATA_TREE_H
#include <iostream>
#include <vector>

namespace search {

template <typename T> class tree {

    struct Node;
    public:
    int root_check = 0;
    int left = 1;
    int right = 2;
    std::vector<T> output;

    tree () {  // default constructor for class tree
    }

    void create_node (T data, Node* position, int child) {
        Node* new_node = new Node();
        if (child == 0) {
            root = new_node;
            new_node->parent = nullptr;
            new_node->data = data;
            root_check++;
            return;
        }
        if (child == 1) {
            position->left_child = new_node;
        } else if (child == 2) {
            position->right_child = new_node;
        }
        new_node->data = data;
    }

    void insert (T input_data) {
        if (root_check == 0) {
            create_node(input_data, root, 0);
            return;
        }
        move_through_tree(input_data, root);
    }

    void move_through_tree (T input_data, Node* position) {

        if (input_data < position->data && position->left_child != nullptr) {
            move_through_tree(input_data, position->left_child);
        } else if (input_data < position->data && position->left_child == nullptr) {
            create_node(input_data, position, left);
            return;
        } else if (input_data > position->data && position->right_child != nullptr) {
            move_through_tree(input_data, position->right_child);
        } else if (input_data > position->data && position->right_child == nullptr) {
            create_node(input_data, position, right);
            return;
        } else {
            return;
        }
    }

    void pre_print() {
        pre_tree_print(root);
        std::cout << "[";
        for (int i = 0; i < output.size(); i++) {
            if (i == output.size() - 1) {
                std::cout << output[i];
            } else {
                std::cout << output[i] << ", ";
            }
        }
        std::cout << "]" << std::endl;
        output.clear();
    }

    void inorder_print() {
        inorder_tree_print(root);
        std::cout << "[";
        for (int i = 0; i < output.size(); i++) {
            if (i == output.size() - 1) {
                std::cout << output[i];
            } else {
                std::cout << output[i] << ", ";
            }
        }
        std::cout << "]" << std::endl;
        output.clear();
    }

    void pre_tree_print(Node* position) {  // prints tree with pre algorithm
        if (position == nullptr) return;
        
        output.push_back(position->data);
        pre_tree_print(position->left_child);
        pre_tree_print(position->right_child);
    }

    void inorder_tree_print(Node* position) {  // prints tree with inorder algorithm
        if (position == nullptr) return;

        inorder_tree_print(position->left_child);
        output.push_back(position->data);
        inorder_tree_print(position->right_child);
    }


    private:
    struct Node {
        Node* parent;
        Node* left_child;
        Node* right_child;
        T data;
    };
    Node* root;
};


}  // namespace tree

#endif  // DATA_TREE_H