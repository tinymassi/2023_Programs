#ifndef DATA_TREE_H
#define DATA_TREE_H

namespace search {

template <typename T> class tree {

    struct Node;
    public:
    int count = 0;

    tree () {  // default constructor for class tree
    }

    Node* create_node (T data, Node* position) {  // figure out type
        if (position == root) {
            root->parent == nullptr;
            root->data == input_data;
            count++;
            return position;
        }
        Node* new_node = new Node();
        new_node = position;
        position->data = data;
        return position;
    }

    void move_through_tree (T input_data) {
        if (count == 0) {
            create_node(input_data, root);
            return;
        }

        if (input_data < root->data && root->left_child != nullptr) {
            move_through_tree(root->left_child);
        } else if (input_data < root->data && root->left_child == nullptr) {
            create_node(input_data, root->left_child);
        } else if (input_data < root->data && root->right_child != nullptr) {
            move_through_tree(root->right_child);
        } else if (input_data < root->data && root->right_child == nullptr) {
            create_node(input_data, root->right_child);
        } else {
            return;
        }
    }

    void pre_tree_print(Node* filler) {
        
        if (root == nullptr) return;

        std::cout << root->data;
        pre_tree_print(root->left_child);
        pre_tree_print(root->right_child);
    }

    void inorder_tree_print() {

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