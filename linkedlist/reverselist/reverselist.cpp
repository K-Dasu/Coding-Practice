#include <iostream>
#include <vector>
using namespace std;

class node{
public:
    node * next;
    int value;
    
    node(){
        next = NULL;
        value = 0;
    }
};


void print(node * head)
{
    node * temp  = head;
    for(;temp;temp = temp->next)
    {
        printf("%d, ",temp->value);
    }
    cout << endl;
}


void reverse(node * head)
{
    vector<node *> c;
    node * temp = head;
    
    for(;temp;temp = temp->next)
    {
        c.push_back(temp);
    }
    
    for(int i = c.size() - 1; i - 1 >= 0; i--)
    {
        c[i]->next = c[i - 1];
    }
    
    c[0]->next = NULL;
    head = c[c.size() - 1];
    
    print(head);
}


void solution()
{
    node * head = new node;
    head->value = 1;
    
    node * l1 = new node;
    l1->value = 2;
    head->next = l1;
    
    node * l2 = new node;
    l2->value = 3;
    l1->next = l2;
    
    node * l3 = new node;
    l3->value = 4;
    l2->next = l3;
    
    l3->next = NULL;
    
    print(head);
    reverse(head);    
}


int main(){

    solution();
    return 0;
}
