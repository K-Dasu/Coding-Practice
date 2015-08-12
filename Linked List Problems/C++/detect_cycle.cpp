#include <iostream>
#include <unordered_map>
#include <sstream> //for std::stringstream
#include <string>  //for std::string
using namespace std;

//Find a Cycle in a Linked List
class node{
public:
    node * next;
    unsigned char value;
    
    node()
    {
        next = NULL;
        value = 0;
    }

};


bool detect_cycle(node * head)
{
    node * temp = head;
    unordered_map<string, int> mymap;
    
    for(;temp;temp = temp->next)
    {
        stringstream ss;
        ss << temp;
        string address = ss.str();
        unordered_map<string,int>::const_iterator got = mymap.find (address);
        if ( got == mymap.end() ){
            pair<string,int> item (address,2);
            mymap.insert(item);
        }else{
            return true;
        }
    }
    
    return false;
}

void solution()
{
  //create a list with a cycle
    node * head = new node;
    node * link1 = new node;
    node * link2 = new node;
    head->next = link1;
    link1->next = link2;
    link2->next = head;
    

    
    
    if(detect_cycle(head)){
        printf("Cycle\n");
    }else{
       printf("No Cycle\n");
    }
}


int main()
{
    solution();
    return 0;
}