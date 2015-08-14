//
//  Node.cpp
//  
//
//  Created by Keshav Dasu on 8/14/15.
//
//

#include <stdio.h>
#include "Node.h"


Node::void didVisit(bool visit){ visited = visit; }


Node::void setValue(int newValue){ value = newValue; }

Node::bool isVisited(){ return visit; }

Node::int getValue(){return value;}

Node::virtual int myType(){
    printf("I am a parent\n");
    return 0;
}


