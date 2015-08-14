
#ifndef NODE_H_
#define NODE_H_
#include <vector>

class Node{
private:
    int value;
    bool visited;
public:
    void didVisit(bool visited);
    void setValue(int newValue);
    bool isVisited();
    int getValue();
    virtual int myType();

};

#endif
