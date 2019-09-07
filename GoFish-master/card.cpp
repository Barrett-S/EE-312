#include "card.h"

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    string strRet = Card::rankString(this->myRank) + Card::suitString(this->mySuit);
    return strRet;
}

bool Card::sameSuitAs(const Card &c) const {
    if(this->mySuit == c.mySuit)
        return true;
    else
        return false;
}

int Card::getRank() const {
    return this->myRank;
}

string Card::suitString(Card::Suit s) const {
    string strRet;
    if(s == spades)
        strRet = "s";
    if(s == hearts)
        strRet = "h";
    if(s == diamonds)
        strRet = "d";
    if(s == clubs)
        strRet = "c";
    return strRet;
}

string Card::rankString(int r) const {
     string strRet;
    if(r == 1)
        strRet = "A";
    else if(r == 11)
        strRet = "J";
    else if(r == 12)
        strRet = "Q";
    else if(r == 13)
        strRet = "K";
    else
        strRet = to_string(r);
    return strRet;
}

bool Card::operator == (const Card& rhs) const{ //true if equal, false if not equal
    if((this->myRank == rhs.myRank) && (this->mySuit == rhs.mySuit))
        return true;
    else return false;
}

bool Card::operator != (const Card& rhs) const{ //true if not equal, false if equal
    if((this->myRank != rhs.myRank) || (this->mySuit != rhs.mySuit))
        return true;
    else return false;
}