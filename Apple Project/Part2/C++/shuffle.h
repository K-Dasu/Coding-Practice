#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>
using namespace std;

vector<int> createDeck();
vector<int>  shuffle(vector<int> deck);
void reshuffle(vector<int> p , vector<int> c);
void shuffle_cards();
bool slow_duplicate_check(vector<int> prev, vector<int> cur);
bool faster_duplicate_check(vector<int> prev, vector<int> cur);
bool question1(vector<int> prev, vector<int> cur, int sequence_len);
string create_label(int count);
void printDeck(vector<int> deck, string label);


//create a standard deck of 52 cards ID (1 - 52)
vector<int> createDeck()
{
    vector<int> deck;
    
    for(int i = 1; i < 53; i++)
    {
        deck.push_back(i);
    }
    return deck;
}

// shuffle the deck pick a random card from the available 52 and swap it with the last card
// of the deck. Then pick a random card from the remaing 51 cards and swap it with the second to last
vector<int>  shuffle(vector<int> deck)
{
    int deck_size = deck.size();
    
    for(int i = 0; i < deck_size;i++)
    {
        int shuf = rand() % (deck_size - 1);
        int temp = deck[shuf];
        deck[shuf] = deck[deck_size - 1];
        deck[deck_size - 1] = temp;
        deck_size--;
    }
    return deck;
}

void reshuffle(vector<int> p , vector<int> c){
    
    vector<int> previous = p;
    vector<int> current = c;
    int count = 3;
    
    //while a duplicate sequence exists between the previous shuffle and the current shuffle
    while(question1(previous,current,3))
    {
        //set current deck to previous deck
        previous = current;
        //shuffle the current deck again
        current = shuffle(current);
        //shuffle #
        string label = create_label(count);
        //print the deck
        printDeck(current,label);
        count++;
    }
    
}


void shuffle_cards()
{
    srand (time(NULL));
    
    //create deck of cards
    vector<int> deck = createDeck();
    
    //show the new deck
    printDeck(deck, "New deck\n\t");
    
    //1st shuffle
    vector<int> first_shuffle = shuffle(deck);
    printDeck(first_shuffle, "Shuffle 1\n\t");
    
    //2nd shuffle
    vector<int> second_shuffle = shuffle(first_shuffle);
    printDeck(second_shuffle, "Shuffle 2\n\t");
    
    //reshuffle till there are no sequences of size 2 in common between a shuffle
    reshuffle(first_shuffle,second_shuffle);
}


//O(n^2) operation...BRUTE FORCE method
bool slow_duplicate_check(vector<int> prev, vector<int> cur){
    for(int i = 0; (i + 1) < prev.size(); i++){
        for(int j = 0; j < cur.size(); j++)
        {
            if(prev[i] == cur[j] && prev[i + 1] == cur[j + 1])
            {
                //reshuffle cards try again...
                return true;
            }
        }
    }
    return false;
}

//O(n) operation improvement in speed
bool faster_duplicate_check(vector<int> prev, vector<int> cur)
{
    //take previous shuffle place in a 52x2 matrix
    //for each card store the card id -> right neighbor
    int matrix[52][2];
    for(int i = 0; i + 1 < prev.size(); i++)
    {
        matrix[prev[i]][0] = prev[i + 1];
    }
    
    //for the current shuffle look up for that card id in the matrix
    //and compare essentially the previous ones neighbor with the current neighbor
    //if they match then a duplicate has occurred.
    for(int j = 0; j + 1 < cur.size(); j++)
    {
        if(matrix[cur[j]][0] == cur[j + 1])
        {
            return true;
        }
    }
    
    return false;
}


// 1) How might you adapt your code to check for sequences of 3, 4, or more cards from the previous shuffle?
// make sure that two back to back shuffles do not have a sequence of length N in common
// O(kn) where k is the sequence length
bool question1(vector<int> prev, vector<int> cur, int sequence_len)
{
    //take previous shuffle place in a 52x2 matrix
    //for each card store the card id -> right neighbor
    int matrix[52][sequence_len];
    
    int neighbors = sequence_len - 1;
    for(int i = 0; i < prev.size(); i++)
    {
        for(int j = 0; j < neighbors; j++ )
        {
            matrix[prev[i] - 1][j] = prev[i + j + 1];
        }
    }
    
    
    for(int k = 0; k < cur.size(); k++)
    {
        int sequence_match = 0;
        for(int j = 0; j < neighbors; j++ )
        {
            if(matrix[cur[k] - 1][j] == cur[k + j + 1])
            {
                sequence_match++;
            }
        }
        if(sequence_match == neighbors) return true;
    }
    
    return false;
}

//used for noting shuffle #
string create_label(int count)
{
    string label = "Shuffle #";
    char buf[20];
    sprintf(buf, "%d", count);
    label += buf;
    label += "\n\t";
    return label;
}



//print the deck (each card is represented by a number 1 - 52)
void printDeck(vector<int> deck, string label)
{
    cout << label;
    for(int i = 0; i < deck.size(); i++)
    {
        if(i > 1 && i % 13 == 0){
            cout << endl << "\t";
        }
        cout << deck[i] << ", ";
        
    }
    cout << "\n-------------------------------------------------\n";
}





