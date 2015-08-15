//
//  Graph.cpp
//  
//
//  Created by Keshav Dasu on 8/14/15.
//
//

#include <stdio.h>
#include <queue>
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

void Graph::DFS(GraphNode * root){}
void Graph::detectCycle(GraphNode * root){}
void Graph::djikstras(GraphNode * root){}
void Graph::bellmanFord(GraphNode * root){}