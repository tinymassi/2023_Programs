#ifndef DATA_TREE_H
#define DATA_TREE_H

namespace search {

template <typename T> class tree {

    struct Node;
    public:
    int count = 0;
    int left = 1;
    int right = 2;

    tree () {  // default constructor for class tree
    }

    void create_node (T data, Node* position, int child) {
        Node* new_node = new Node();
        if (position == root) {
            root = new_node;
            new_node->parent = nullptr;
            new_node->data = data;
            count++;
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
        if (count == 0) {
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

    void pre_tree_print(Node* position) {  // change this function to work with this tree
        
        if (root == nullptr) return;

        std::cout << position->data;
        pre_tree_print(position->left_child);
        pre_tree_print(position->right_child);
    }

    void inorder_tree_print() {  // change this function to work with this tree

        if (root == nullptr) return;

        inorder_tree_print(root->left_child);
        std::cout << root->data;
        inorder_tree_print(root->right_child);
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