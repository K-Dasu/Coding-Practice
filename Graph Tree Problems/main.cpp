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


int main(){
    
    GraphNode * graphnode = new GraphNode();
    TreeNode * treenode = new TreeNode();
    Node * mynode = new Node();
    
    vector<Node *> test1;
    test1.push_back(graphnode);
    test1.push_back(treenode);
    test1.push_back(mynode);
    
    return 0;
}