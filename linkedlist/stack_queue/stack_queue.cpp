#include <iostream>
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


class stackQ{
private:
    node * head;
public:
    stackQ(){
        head = NULL;
    }
    
    
    int pop(){
        node * temp = head;
        for(;temp;temp = temp->next)
        {
            if(temp->next->next == NULL)
            {
                int sol = temp->next->value;
                node * remove = temp->next;
                delete(remove);
                temp->next = NULL;
                return sol;
            }
        }
        
        //error stack empty;
        printf("stack empty returning -1\n");
        return -1;
    }
    
    int dequeue(){
        node * temp = head;
        head = temp->next;
        int sol = temp->value;
        delete(temp);
        return sol;
    }
    
    void push(int val)
    {
        if(head == NULL)
        {
            node * new_node = new node;
            new_node->value = val;
            new_node->next = NULL;
            head = new_node;
            return;
        }
        
        node * temp = head;
        for(;temp; temp = temp->next)
        {
            if(temp->next == NULL)
            {
                node * new_node = new node;
                new_node->value = val;
                new_node->next = NULL;
                temp->next = new_node;
                return;
            }
        }
    }
    
    void print()
    {
        node * temp = head;
        
        for(;temp;temp = temp->next)
        {
            printf("%d, ",temp->value);
        }
        cout << endl;
    }
    
    ~stackQ(){
        node * temp = head;
        while(temp)
        {
            node * nxt = temp->next;
            delete(temp);
            temp->next = NULL;
            temp = nxt;
        }
    }
};



void test1()
{
    stackQ myStackQ;
    myStackQ.push(2);
    myStackQ.push(21);
    myStackQ.push(3);
    myStackQ.print();
    myStackQ.push(5);
    myStackQ.push(48);
    myStackQ.print();
    printf("Popped %d\n", myStackQ.pop());
    myStackQ.print();
    myStackQ.push(103);
    printf("Dequeued %d\n", myStackQ.dequeue());
    myStackQ.print();
}

int main()
{
    test1();
    return 0;
}