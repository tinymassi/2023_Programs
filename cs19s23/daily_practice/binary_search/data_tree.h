#ifndef DATA_TREE_H
#define DATA_TREE_H

namespace search {

template <typename T> class tree {

    struct Node;
    public:

    tree () {  // default constructor
        if (root == nullptr) {
            root->data == input_data;
            root->left_child = nullptr;
            root->right_child = nullptr;
            return root;
        }
    }

    Node* create_node (T input_data) {  // make default constructor make the root from function call

        Node* new_node = new Node();
        new_node->left_child = nullptr;
        new_node->right_child = nullptr;
        new_node->data = input_data;

        return new_node;
    }


    private:
    struct Node {
        Node* left_child;
        Node* right_child;
        T data;
    }
    Node* root;
};


}  // namespace tree

#endif  // DATA_TREE_H