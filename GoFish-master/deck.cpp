#include "deck.h"

Deck::Deck(){
    int i = 0;
    for(i=0; i<13; i++)
        myCards[i] = Card(i+1, Card::Suit::spades);
    for(i=0; i<13; i++)
        myCards[i+13] = Card(i+1, Card::Suit::clubs);
    for(i=0; i<13; i++)
        myCards[i+26] = Card(i+1, Card::Suit::diamonds);
    for(i=0; i<13; i++)
        myCards[i+39] = Card(i+1, Card::Suit::hearts);
    myIndex = 0;
}

void Deck::shuffle(){
    int count = 0;
    while(count < 5) { //shuffle 5 times
        for (int i = 0; i < SIZE; i++) {
            int r = rand() % 52; //create random number between 0-51
            Card temp = myCards[i];
            myCards[i] = myCards[r];
            myCards[r] = temp;
        }
        count ++;
    }
}

Card Deck::dealCard(){
    Card retCard = this->myCards[myIndex];
    myIndex ++;
    return retCard;
}

int Deck::size() const {
    int deckSize = 52-myIndex;
    return deckSize;
}