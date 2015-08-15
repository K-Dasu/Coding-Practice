#ifndef GRAPH_H_
#define GRAPH_H_

#include "GraphNode.h"
using namespace std;

class Graph{
public:
    // Graph Related
    Graph();
    void BFS(GraphNode * root);
    void DFS(GraphNode * root);
    void detectCycle(GraphNode * root);
    void djikstras(GraphNode * root);
    void bellmanFord(GraphNode * root);
    
};


#endif