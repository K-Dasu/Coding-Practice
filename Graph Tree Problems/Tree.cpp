//
//  Tree.cpp
//  
//
//  Created by Keshav Dasu on 8/15/15.
//
//

#include <stdio.h>
#include <queue>
#include "Tree.h"

TreeNode * TreeNode::getRoot(){
    return root;
}

TreeNode * createNode(int value, bool leaf){
    TreeNode * insertNode = new TreeNode();
    insertNode.setValue(value);
    insertNode.setLeaf(leaf);
    return insertNode;
}

void Tree::insert(int value, TreeNode * myNode){
    
    // value is going toward the left side and is not a leaf node
    if(myNode->left != NULL && value <= myNode->getValue()){
        if(myNode->left->getValue <= value){
            //insert in between on the leftside
            TreeNode * insertNode = createNode(value,false);
            insertNode->setLeft(myNode->left);
            myNode->left = insertNode;
            return;
        }else{
            //recurse
            insert(value,myNode->left);
        }
    }else if(value <= myNode->getValue()){
        //leaf node
        myNode.setLeaf(false);
        TreeNode * insertNode = createNode(value,true);
        myNode.setLeft(insertNode);
        return;
    }
    
    // value is going toward the right side and is not a leaf node
    if(myNode->right != NULL && value > myNode->getValue()){
        if(myNode->right->getValue > value){
            //insert in between on the leftside
            TreeNode * insertNode = createNode(value,false);
            insertNode->setRight(myNode->right);
            myNode->right = insertNode;
            return;
        }else{
            //recurse
            insert(value,myNode->right);
        }
    }else if(value > myNode->getValue()){
        //leaf node
        myNode.setLeaf(false);
        TreeNode * insertNode = createNode(value,true);
        myNode.setRight(insertNode);
        return;
    }
}

void Tree::removeValue(int value){
    
}

void Tree::rotateLeft(TreeNode * node){
    
}

void Tree::rotateRight(TreeNode * node){
    
}

void Tree::printByDepth(TreeNode* node){
    if(!node)return;
    queue<TreeNode * node> currentDepth, nextDepth;
    currentDepth.push(node);
    
    while(!currentDepth.empty()){
        TreeNode * frontNode = currentDepth.front();
        currentDepth.pop();
        
        if(frontNode){
            printf("%d ",frontNode->getValue());
            nextDepth.push(frontNode->left);
            nextDepth.push(frontNode->right);
        }
        
        if(currentDepth.empty()){
            printf("\n");
            currentDepth = nextDepth;
        }
    }
}

void Tree::postOrder(TreeNode * node){
    if(node == NULL) return;
    //left
    preOrder(node->left);
    //right
    preOrder(node->right);
    //print node
    printf("Node Data %d",node->getValue());
}

void Tree::preOrder(TreeNode * node){
    if(node == NULL) return;
    //print node
    printf("Node Data %d, ",node->getValue());
    node->didVisit(false);
    //left
    preOrder(node->left);
    //right
    preOrder(node->right);
}

void Tree::inOrder(TreeNode * node){
    if(node == NULL) return;
    //left
    preOrder(node->left);
    //print node
    printf("Node Data %d",node->getValue());
    //right
    preOrder(node->right);
}

void Tree::deleteTree(TreeNode * root){
    
}