#ifndef TREE_H_
#define TREE_H_
class Tree{
#include "TreeNode.h"
private:
    TreeNode * root;
    
public:
    // binary tree related [BASICS]
    TreeNode * getRoot();
    void insert(int value, TreeNode * myNode);
    void removeValue(int value);
    void rotateLeft(TreeNode * node);
    void rotateRight(TreeNode * node);
    void postorder(TreeNode * node);
    void preorder(TreeNode * node);
    void inOrder(TreeNode * node);
    void printByDepth(TreeNode* node);
    void deleteTree(TreeNode * node);
    // TODO: Implement something fancy and fun here
};
#endif