#ifndef GOFISH2_DECK_H
#define GOFISH2_DECK_H
#include "card.h"

class Deck
{
    static const int SIZE = 52; //since it isn't specified, it is private?
public:
    Deck();           // pristine, sorted deck
    void shuffle();   // shuffle the cards in the current deck
    Card dealCard();   // get a card, after 52 are dealt, fail
    int size() const; // # cards left in the deck
private:
    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif //GOFISH2_DECK_H
