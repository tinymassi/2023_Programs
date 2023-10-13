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
    int node_count = 0;
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
            node_count++;
            std::cout << "I am the root: " << new_node->data << std::endl;
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
    }

    void inorder_print() {
        inorder_tree_print(root);
    }

    void pre_tree_print(Node* position) {  // change this function to work with this tree
        
        if (count  == node_count) {
            for (auto i : output) {
                std::cout << i << ", ";
            }
            output.pop_back();
        }
        if (position == nullptr) return;
        int count = 0;
        output.push_back(position->data);
        count++;
        
        // // this doesnt work...
        // if (position->right_child == nullptr && position->left_child == nullptr && root_check == 3) {
        //     std::cout << position->data << std::endl;
        // } else {
        //     std::cout << position->data << ", ";
        // }
        
        pre_tree_print(position->left_child);
        pre_tree_print(position->right_child);
    }

    void inorder_tree_print(Node* position) {  // change this function to work with this tree

        if (position == nullptr) return;
        if (position == root) {
            root_check++;
        }
        
        // this doesnt work...
        if (position->right_child == nullptr && position->left_child == nullptr && root_check == 3) {
            std::cout << position->data << std::endl;
        } else {
            std::cout << position->data << ", ";
        }

        inorder_tree_print(position->left_child);
        std::cout << position->data << ", ";
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