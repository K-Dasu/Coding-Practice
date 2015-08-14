
#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_
#include "Node.h"
class GraphNode: public Node{
private:
    vector<Node *> children;
    string color;
public:
    GraphNode();
    vector<Node *> getChildren;
    virtual int myType();
};
#endif