
#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_
#include "Node.h"


class GraphNode: public Node{
    
private:
    vector<GraphNode *> children;
    int distance;
    string color;
    
public:
    GraphNode();
    vector<GraphNode *> getChildren();
    string getColor();
    int getDistance();
    
    void setColor(string newColor);
    void setDistance(int length);
    void addChild(GraphNode * child);
    virtual int myType();
};
#endif