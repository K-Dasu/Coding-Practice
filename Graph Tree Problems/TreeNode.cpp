//
//  TreeNode.cpp
//  
//
//  Created by Keshav Dasu on 8/14/15.
//
//

#include <stdio.h>
#include "TreeNode.h"
using namespace std;



TreeNode::TreeNode(){
    leaf = false;
    left = NULL;
    right = NULL;
}


void TreeNode::setLeft(TreeNode * leftSide){
    left = leftSide;
}

void TreeNode::setRight(TreeNode * rightSide){
    right = rightSide;
}

void TreeNode::setLeaf(bool thisALeaf){
    leaf = thisALeaf;
}

bool TreeNode::isLeaf(){
    return leaf;
}

TreeNode * getLeft(){
    return left;
}

TreeNode * getRight(){
    return right;
}


int TreeNode::myType(){
    printf("I am a treenode\n");
    return 1;
}