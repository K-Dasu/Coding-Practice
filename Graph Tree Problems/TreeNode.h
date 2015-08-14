
#ifndef TREENODE_H_
#define TREENODE_H_
#include "Node.h"
class TreeNode: public Node{
private:
    bool isLeaf;
    Node * left;
    Node * right;
public:
    Tree();
    void setLeft(Node * leftSide);
    void setRight(Node * rightSide);
    void setleaf(bool leaf);
    bool isLeaf();
    virtual int myType();
};
#endif