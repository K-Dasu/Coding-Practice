/*
 Keshav Dasu
 
 Please complete the following task in C, C++, or Objective-C. You are free to use whatever data structures and design you prefer.

1) create a deck of cards, and print/display the cards (currently printing by id)
2) shuffle the deck of cards, and display the cards (in their shuffled order)
3) reshuffle the deck, and display the cards (in their shuffled order)
4) look for any 2-card sequence that was also present in the previous shuffle. If any are found, go back to step 3
5) when two back to back shuffles do not contain a duplicate sequence, you're done.


 */




#include <iostream>
#include "shuffle.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>


using namespace std;



int main()
{
    shuffle_cards();
}




