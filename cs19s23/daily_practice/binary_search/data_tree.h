#ifndef DATA_TREE_H
#define DATA_TREE_H

namespace search {

template <typename T> class tree {

    struct Node;
    public:

    tree () {  // default constructor
    }

    Node* create_node (T input_data) {  // make default constructor make the root from function call

        Node* new_node = new Node();
        new_node->left_child = nullptr;
        new_node->right_child = nullptr;
        new_node->data = input_data;

        return new_node;
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
        Node* left_child;
        Node* right_child;
        T data;
    };
    Node* root;
};


}  // namespace tree

#endif  // DATA_TREE_H