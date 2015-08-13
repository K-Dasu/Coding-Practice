#include "linkedlist.h"

Node * makeNode(int value);

Node * makeNode(int value){
    Node * newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

List * newList(){
    List * newList = malloc(sizeof(List));
    newList->head = NULL;
    return newList;
}


void insert(int value, List * list, int insertposition){
    Node * currentNode;
    int currentPosition = 0;
    if(insertposition < 0){
        printf("Invalid position did not insert value\n");
        return;
    }
    
    for(currentNode = list->head; currentNode->next != NULL; currentNode = currentNode->next, currentPosition++){
        if(currentPosition + 1 == insertposition - 1){
            printf("Value has been inserted into list at position %d\n",insertposition);
            Node * newNode = makeNode(value);
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return;
        }
    }
    
    //insert at the back
    Node * newNode = makeNode(value);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void pushback(int value, List * list){
    if(list->head == NULL){
        list->head = makeNode(value);
        return;
    }
    Node * currentNode;
    for(currentNode = list->head; currentNode->next != NULL; currentNode = currentNode->next);
    //insert at the back
    Node * newNode = makeNode(value);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void print(List * list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }
    
    Node * currentNode;
    printf("List Contents: ");
    for(currentNode = list->head; currentNode != NULL; currentNode = currentNode->next){
        printf("%d, ",currentNode->value);
    }
    printf("\n");
}

void pop(List * list){
    if(list->head == NULL)return;
    
    Node * nodeToDelete = list->head;
    list->head = nodeToDelete->next;
    nodeToDelete->next = NULL;
    free(nodeToDelete);
}

void popAtIndex(int index, List * list){
    if(index == 0){
        pop(list);
        return;
    }else if(index > 0){
        int currentPosition;
        Node * currentNode;
        for(currentPosition = 1, currentNode = list->head; currentNode->next != NULL;
            currentNode = currentNode->next, currentPosition++){
            if(currentPosition == index){
                Node * nodeToDelete = currentNode->next;
                currentNode->next = nodeToDelete->next;
                nodeToDelete->next = NULL;
                free(nodeToDelete);
                return;
            }
        }
    }
    printf("Failed to pop invalid index\n");
}

void reverse(List * list){
    Node * previous = NULL;
    Node * current = list->head;
    Node * next;
    
    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    
    list->head = previous;
}











