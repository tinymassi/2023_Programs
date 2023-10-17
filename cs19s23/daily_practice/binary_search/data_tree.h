#ifndef DATA_TREE_H
#define DATA_TREE_H
#include <iostream>
#include <vector>
#include <chrono>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

namespace search {

template <typename T> class tree {

    struct Node;
    public:
    int root_check = 0;
    int left = 1;
    int right = 2;
    int node_count = 0;
    std::vector<T> output;
    bool needle_found = false;

    tree () {  // default constructor for class tree
    }
    
    int size() {
        return node_count;
    }

    void create_node (T data, Node* position, int child) {
        Node* new_node = new Node();
        if (child == 0) {
            root = new_node;
            new_node->parent = nullptr;
            new_node->data = data;
            root_check++;
            node_count++;
            return;
        }
        if (child == 1) {
            position->left_child = new_node;
        } else if (child == 2) {
            position->right_child = new_node;
        }
        node_count++;
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

    void find(T needle) {
        auto start = std::chrono::high_resolution_clock::now();
        find_needle(needle, root);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        if (needle_found == true) {
            if (duration.count() == 1) {
                std::cout << GREEN << "I found " << needle << " in " << duration.count() << " microsecond!" << RESET << std::endl;
            } else { 
                std::cout << GREEN << "I found " << needle << " in " << duration.count() << " microseconds!" << RESET << std::endl;
            }
        } else {
            std::cout << RED << needle << " is not in the search tree." << RESET << std::endl;
        }
        needle_found = false;
    }

    void find_needle (T needle, Node* position) {
        if (position == nullptr) return;

        if (position->data == needle) { 
            needle_found = true;
        }

        find_needle(needle, position->left_child);
        find_needle(needle, position->right_child);
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