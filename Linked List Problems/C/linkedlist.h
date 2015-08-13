#ifndef LinkedList_H_
#define LinkedList_H_

#include <stdio.h>
#include <stdlib.h>

typedef int BOOL;
#define YES 1
#define NO 0

typedef struct node{
   struct node * next;
   int value;
}Node;

typedef struct list{
    Node * head;
}List;

List * newList();
void insert(int value, List * list, int insertposition);
void popAtIndex(int index, List * list);
void pop(List * list);
void pushback(int value, List * list);
void print(List * list);
void reverse(List * list);
BOOL detectCycle(List * list);
List * deepCopy(List * list);
void clearList(List * list);


#endif
