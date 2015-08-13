#include <stdio.h>
#include "linkedlist.h"


void testcase1(){
    List * myList = newList();
    pushback(0,myList);
    pushback(1,myList);
    pushback(2,myList);
    pushback(3,myList);
    pushback(4,myList);
    pushback(5,myList);
    pushback(6,myList);
    pushback(7,myList);
    
    print(myList);
    insert(5,myList,3);
    print(myList);
    pop(myList);
    print(myList);
    popAtIndex(4,myList);
    print(myList);
    reverse(myList);
    print(myList);
}

int main(){
    testcase1();
    return 0;
}
