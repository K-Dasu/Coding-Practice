
#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include <string>
using namespace std;

class Node{
private:
    int value;
    bool visited;
public:
    void didVisit(bool visit);
    void setValue(int newValue);
    bool isVisited();
    int getValue();
    virtual int myType();

};

#endif
