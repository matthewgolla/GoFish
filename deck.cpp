//
// Created by Matthew Golla and Iva Sadler on 11/2/2018.
//implements the deck class
#include "deck.h"
#include "card.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Deck::Deck() {
    for(int i = 0; i < 52; i++){
        Card::Suit curSuit;
        if(i<13){
            curSuit = Card::spades;
        }
        else if(i < 26){
            curSuit = Card::hearts;
        }
        else if(i<39){
            curSuit = Card::diamonds;
        }
        else{
            curSuit = Card::clubs;
        }
        Card myCard(i%13+1, curSuit);
        myCards[i] = myCard;
        myIndex = 0;
        srand((unsigned) time(0));
    }
}

void Deck::shuffle() {
    Card temp;
    int index1, index2;
    for(int i = 0; i < 1000; i++){
        index1 = rand()%52;
        index2 = rand()%52;
        temp = myCards[index1];
        myCards[index1] = myCards[index2];
        myCards[index2] = temp;
    }
}

Card Deck::dealCard() {
    myIndex++;
    return myCards[myIndex-1];
}

int Deck::size() const {
    return 52 - (myIndex);
}

