#include "player.h"


string Player::addCard(Card c) {
    myHand.push_back(c);
    cout << this->getName() <<" draws " << c.toString() <<"\n";
    string announce = this->getName() + " draws " +  c.toString() + "\n";
    return announce;
}

string Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    cout << this->getName()<<" books a pair of " << c1.rankString(c1.getRank()) <<"'s. \n";
    string announce = this->getName() + " books a pair of " + c1.rankString(c1.getRank()) + "'s. \n";
    return announce;
}

string Player::askForCard(Card c){
    cout << this->getName()<<" asks: Do you have a "<< c.rankString(c.getRank())<<"? \n";
    string announce = this->getName() + " asks: Do you have a " +  c.rankString(c.getRank()) + "? \n";
    return announce;
}

string Player::answerYes(Card c){
    cout<< this->getName()<<" says: Yes, I have a "<< c.rankString(c.getRank())<<". \n";
    string announce = this->getName() + " says: Yes, I have a " + c.rankString(c.getRank()) + ". \n";
    return announce;
}

string Player::goFish(){
    cout<< this->getName()<<" says: Go Fish! \n \n";
    string announce = this->getName() + " says: Go Fish! \n \n";
    return announce;
}

string Player::Victory(){
    cout<< this->getName()<< " wins! The winning pairs were: \n"<< this->showBooks();
    string announce =  this->getName() + " wins! The winning pairs were: \n" + this->showBooks();
    return announce;
}


bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(int first=0; first<this->myHand.size(); first++){
        c1 = myHand[first];
        for(int second=0; second<myHand.size(); second++){ //double for loop to compare
            if(first != second){  //don't compare the same cards
               c2 = myHand[second];
               int c1Rank = c1.getRank();
               int c2Rank = c2.getRank();
               if(c1Rank == c2Rank) //compare both ranks
                   return true; //returns true while also filling c1 and 2 with the appropriate cards
            }
        }
    }
    return false; //if you get here, there were no books to be had in the hand
}

Card Player::chooseCardFromHand() const{
    if(getHandSize() > 0) {
        int randCard = (rand() % getHandSize()); //pick a card between 0 and the amount of cards you have
        return this->myHand[randCard];
    }
    else return myHand[0];
}

    //only called directly after checking for book
Card Player::removeCardFromHand(Card c) { //assuming that c is definitely in the hand
    vector<Card>::iterator index = myHand.begin(); //iterator index points to the first card in myHand
    while(*index != c) //find index of card to remove using overloaded operator
        index++;
    Card c1 = *index;
    myHand.erase(index); // remove card from hand
    return c1;
}

Card Player::removeSameRank(Card c){       //will definitely have a card with same rank in hand
    for(int i=0; i<getHandSize(); i++){    //iterate through hand to find card
        if (myHand[i].getRank() == c.getRank()) { //if ranks match, remove the card and return it
            Card cardRet = this->removeCardFromHand(myHand[i]); //returns the card we want
            return cardRet;
        }
    }
}


string Player::showHand() const {
    int handSize = getHandSize();
    vector<string> hand; //create a vector of strings
    for(int i=0; i< handSize; i++){ //store all the string values of the cards into the vector
        string cardString = myHand[i].toString();
        hand.push_back(cardString);
    }
    int j = 0;
    string strRet = this->getName() + "'s hand has";
    while(j < handSize){ //concatenate the vector into one string
        strRet += (" " + hand[j]);
        j++;
    }
    return strRet;
}
    //same code with variables changed for book instead of hand
string Player::showBooks() const {
    int bookSize = getBookSize();
    int j = 0;
    string cardString;
    vector<string> book; //create a vector of strings
    for(int i=0; i< bookSize; i++){ //store all the string values of the cards into the vector
        cardString = myBook[i].toString();
        book.push_back(cardString);
    }
    string strRet = "";
    while(j < bookSize) { //concatenate the vector into one string
        strRet += (" " + book[j]);
        j++;
    }
    return strRet;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

bool Player::sameRankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank())
            return true;
    }
    return false;
}

bool Player::cardInHand(Card c) const {
    for(int i=0; i< myHand.size(); i++) {
        if(myHand[i] == c)
            return true;
    }
    return false;
}