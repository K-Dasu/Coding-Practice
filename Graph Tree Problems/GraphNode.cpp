//
//  GraphNode.cpp
//  
//
//  Created by Keshav Dasu on 8/14/15.
//
//

#include <stdio.h>
#include <vector>
#include "GraphNode.h"
using std::vector;
using namespace std;


GraphNode::GraphNode(){
    color = "";
}

vector<Node *> GraphNode::getChildren(){
    return children;
}

void GraphNode::addChild(Node * child){
    children.push_back(child);
}

string GraphNode::getColor(){
    return color;
}

void GraphNode::setColor(string newColor){
    color = newColor;
}

int GraphNode::myType(){
    printf("I am a graph node\n");
    return 2;
}