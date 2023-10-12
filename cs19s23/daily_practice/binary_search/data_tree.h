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
        if (count == 0) {
            Node* new_node = new Node();
            new_node = root;
            root->parent == nullptr;
            root->data == input_data;
            return;
        }

        count++;
        if (root == nullptr) {
            Node* new_node2 = new Node();
            new_node2 = root;
            root->data == input_data;
            return;
        }
        create_node(root->left_child);
        create_node(root->right_child);
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