
#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_
#include "Node.h"
class graphNode: public Node{
private:
    vector<Node *> getChildren;
    string color;
public:
    
    virtual int myType();
};
#endif