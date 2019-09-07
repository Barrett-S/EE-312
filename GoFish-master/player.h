#ifndef GOFISH2_PLAYER_H
#define GOFISH2_PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "card.h"
using namespace std;

class Player
{
public:
    Player(){
        myName = "";
    }
    Player(string name, int ID) {
        myName = name;
        turnID = ID;
    }

    int turnID;

    string getName() const {
        return myName;
    }
    int getTurnId() const {
        return turnID;
    }
    string addCard(Card c);  //adds a card to the hand
    string bookCards(Card c1, Card c2);

    string askForCard(Card c);
    string answerYes(Card c);
    string goFish();
    string Victory();

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards that make the pair.
    bool checkHandForBook(Card &c1, Card &c2);

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const;

    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const;

    //Remove the exact card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    //Remove card with the same rank as c
    Card removeSameRank(Card c);

    string showHand() const;
    string showBooks() const;

    int getHandSize() const;
    int getBookSize() const;

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    bool sameRankInHand(Card c) const;

private:
    vector <Card> myHand;
    vector <Card> myBook;
    string myName;
};

#endif //GOFISH2_PLAYER_H
