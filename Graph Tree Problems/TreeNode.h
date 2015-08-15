
#ifndef TREENODE_H_
#define TREENODE_H_
#include "Node.h"
class TreeNode: public Node{
private:
    bool leaf;
    TreeNode * left;
    Node * right;
public:
    TreeNode();
    void setLeft(TreeNode * leftSide);
    void setRight(TreeNode * rightSide);
    TreeNode * getLeft();
    TreeNode * getRight();
    void setLeaf(bool leaf);
    bool isLeaf();
    virtual int myType();
};
#endif