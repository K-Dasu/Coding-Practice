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


//2n O(n)
void reverse(node ** head)
{
    vector<node *> c;
    node * temp = * head;
    
    for(;temp;temp = temp->next)
    {
        c.push_back(temp);
    }
    
    for(int i = c.size() - 1; i - 1 >= 0; i--)
    {
        c[i]->next = c[i - 1];
    }
    
    c[0]->next = NULL;
    * head = c[c.size() - 1];
}

// n O(n)
void reverse2(node ** head)
{
    struct node* prev   = NULL;
    struct node* current = * head;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    * head = prev;
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
    reverse(&head);
    print(head);
}


int main(){

    solution();
    return 0;
}
