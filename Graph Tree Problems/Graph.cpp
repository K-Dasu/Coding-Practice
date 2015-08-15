//
//  Graph.cpp
//  
//
//  Created by Keshav Dasu on 8/14/15.
//
//

#include <stdio.h>
#include <queue>
#include <stack>
#include "Graph.h"


Graph::Graph(){}

//Breadth First Search
void Graph::BFS(GraphNode * root){
    root->didVisit(true);
    queue<GraphNode *> notVisited;
    notVisited.push(root);
    
    while(!notVisited.empty()){
        GraphNode * frontNode = notVisited.front();
        notVisited.pop();
        vector<GraphNode *> neighbors = frontNode->getChildren();
        for(int i = 0; i < neighbors.size(); i++){
            if(!neighbors[i]->isVisited()){
                neighbors[i]->didVisit(true); //set visited as yes
                neighbors[i]->setDistance(frontNode->getDistance() + 1); //update distance to +1 from this current node
                notVisited.push(neighbors[i]);
            }
        }
        frontNode->setColor("The Rainbow");
    }
}

//Can be used for topological sort...
void Graph::RDFS(GraphNode * root){
    root->didVisit(true);
    vector<GraphNode *> neighbors = root->getChildren();
    for(int i = 0; i < neighbors.size(); i++){
        if(!neighbors[i]->isVisited()){
            DFS(neighbors[i]);
        }
    }
    //add to stack for topological sort then print stack and profit
}

void Graph::DFS(GraphNode * root){
    stack<GraphNode *> notVisited;
    nonVisitied.push_back(root);
    
    while (!notVisited.empty()) {
        GraphNode * currentNode = notVisited.pop();
        if(!currentNode->isVisited()){
            currentNode->didVisit(true);
            vector<GraphNode *> neighbors = currentNode->getChildren();
            for(int i = 0; i < neighbors.size(); i++){
                nonVisitied.push_back(neighbors[i]);
            }
        }
    }
    
}



