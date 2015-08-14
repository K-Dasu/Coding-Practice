#ifndef TREE_H_
#define TREE_H_
class Tree{
    
public:
    // binary tree related
    void insert(int value, Node * root);
    void removeValue(int value, Node * root);
    void rotateLeft(Node * root);
    void rotateRight(Node * root);
    void postorder(Node * root);
    void preorder(Node * root);
    void inOrder(Node * root);
};
#endif