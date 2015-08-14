#ifndef GRAPH_H_
#define GRAPH_H_

class Graph{
public:
    // Graph Related
    void BFS(Node * root);
    void DFS(Node * root);
    void detectCycle(Node * root);
    void djikstras(Node * root);
    void bellmanFord(Node * root);
    
};


#endif