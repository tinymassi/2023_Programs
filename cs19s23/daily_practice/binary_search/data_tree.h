#ifndef DATA_TREE_H
#define DATA_TREE_H

namespace search {

template <typename T> class tree {

    struct Node;
    public:
    int count = 0;

    tree () {
    }

    void create_node (T input_data) {  // find a way to make the search tree assign
        Node* new_node = new Node();   // children by itself
        if (count == 0) { 
            new_node = root;
            new_node->parent = nullptr;
        }
        new_node->left_child = nullptr;
        new_node->right_child = nullptr;
        new_node->data = input_data;
        count++;
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