//
//  Node.cpp
//  
//
//  Created by Keshav Dasu on 8/14/15.
//
//

#include <stdio.h>
#include "Node.h"
using namespace std;

void Node::didVisit(bool visit){ visited = visit; }


void Node::setValue(int newValue){ value = newValue; }

bool Node::isVisited(){ return visited; }

int Node::getValue(){return value;}

int Node::myType(){
    printf("I am a parent\n");
    return 0;
}


