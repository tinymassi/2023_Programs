#ifndef DATA_TREE_H
#define DATA_TREE_H

namespace search {

template <typename T> class tree {

    struct Node;
    public:

    


    private:
    struct Node {
        Node* left_child;
        Node* right_child;
        T data;
    }
    Node* root;
}


}  // namespace tree

#endif  // DATA_TREE_H