//Created by Matt Golla and Iva Sadler
//implements the card class
#include "card.h"
#include <string>

using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    string result = rankString(myRank);
    result += suitString(mySuit);
    return result;
}

bool Card::sameSuitAs(const Card &c) const {
    return mySuit == c.mySuit;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {
    string result;
    if(s == spades){
        result = "s";
    }
    else if(s == hearts){
        result = "h";
    }
    else if(s == diamonds){
        result = "d";
    }
    else{
        result = "c";
    }
    return result;
}

string Card::rankString(int r) const {
    string result;
    if(r == 1){
        result = "A";
    }
    else if(r == 11){
        result = "J";
    }
    else if(r == 12){
        result = "Q";
    }
    else if(r == 13){
        result = "K";
    }
    else if(r == 2){
        result = "2";
    }
    else if(r == 3){
        result = "3";
    }
    else if(r == 4){
        result = "4";
    }
    else if(r == 5){
        result = "5";
    }
    else if(r == 6){
        result = "6";
    }
    else if(r == 7){
        result = "7";
    }
    else if(r == 8){
        result = "8";
    }
    else if(r == 9){
        result = "9";
    }
    else if(r == 10){
        result = "10";
    }

    return result;
}

bool Card::operator!=(const Card &rhs) const {
    return (mySuit != rhs.mySuit) && (myRank != rhs.myRank);
}

bool Card::operator==(const Card &rhs) const {
    return (mySuit == rhs.mySuit) && (myRank == rhs.myRank);
}

Card& Card::operator = (const Card& rhs) {
    myRank = rhs.myRank;
    mySuit = rhs.mySuit;
}

ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}


