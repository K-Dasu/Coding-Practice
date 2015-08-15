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
    distance = 0;
}

vector<GraphNode *> GraphNode::getChildren(){
    return children;
}

void GraphNode::addChild(GraphNode * child){
    children.push_back(child);
}

string GraphNode::getColor(){
    return color;
}

void GraphNode::setColor(string newColor){
    color = newColor;
}


int GraphNode::getDistance(){
    return distance;
}

void GraphNode::setDistance(int length){
    distance = length;
}

int GraphNode::myType(){
    printf("I am a graph node\n");
    return 2;
}