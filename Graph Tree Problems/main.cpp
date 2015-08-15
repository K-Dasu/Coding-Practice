//
//  main.cpp
//  
//
//  Created by Keshav Dasu on 8/14/15.
//
//

#include <stdio.h>
#include <vector>
#include "Node.h"
#include "GraphNode.h"
#include "TreeNode.h"
using namespace std;

void processNodeForTest1(Node * test1){
    switch (test1->myType()) {
        case 0:{
            printf("Node value is %d\n",test1->getValue());
            break;
        }
        case 1:{
            TreeNode * tNode = dynamic_cast<TreeNode * >(test1);
            printf("TreeNode value is %d\n",tNode->getValue());
            if(!tNode->isLeaf()){
                printf("Not a leaf\n");
            }else{
                printf("leaf\n");
            }
            break;
        }
        case 2:{
            GraphNode * gNode = dynamic_cast<GraphNode * >(test1);
            printf("GraphNode value is %d and its color %s\n",gNode->getValue(), gNode->getColor().c_str());
            break;
        }
    }
}
//Testing to see if the node classes are working as expected
void test1(){
    GraphNode * graphnode = new GraphNode();
    graphnode->setValue(777);
    graphnode->setColor("red");
    TreeNode * treenode = new TreeNode();
    treenode->setValue(122);
    treenode->setLeaf(true);
    Node * mynode = new Node();
    mynode->setValue(331);
    
    vector<Node *> test1;
    test1.push_back(graphnode);
    test1.push_back(treenode);
    test1.push_back(mynode);
    
    for(int i = 0; i < test1.size(); i++){
        processNodeForTest1(test1[i]);
    }
    
}

int main(){
    test1();
    return 0;
}