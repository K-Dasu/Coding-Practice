#ifndef GraphTreeAlgorithms_H_
#define GraphTreeAlgorithms_H_

// Graph Related
void BFS(Node * root);
void DFS(Node * root);
void detectCycle(Node * root);
void djikstras(Node * root);
void bellmanFord(Node * root);

// binary tree related
void insert(int value, Node * root);
void removeValue(int value, Node * root);
void rotateLeft(Node * root);
void rotateRight(Node * root);
void postorder(Node * root);
void preorder(Node * root);
void inOrder(Node * root);


#endif
