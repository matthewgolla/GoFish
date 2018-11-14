// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
using namespace std;


class Player
{
public:

    //default constructor
    Player();

    //constructor with name parameter
    //set the name
    //The user of the class will pass in a name.
    Player(string name) {
        myName = name;
    }

    /* FUNCTION - int getName
     * gets the name of the player

     precondition: player is valid

     input params - none

     output params - returns the name of the player(string)
    */
    string getName() const {
        return myName;
    }

    /* FUNCTION - void addCard
     * attempts to add a new card to the hand
     precondition: c is a valid card

     input params - pass a card

     output params - none
    */
    void addCard(Card c);  //adds a card to the hand

    /* FUNCTION - void bookCards
     * takes a book out of the player's hand and adds them to the book
     precondition: c1 and c2 are valid cards

     input params - pass two cards

     output params - none
    */
    void bookCards(Card c1, Card c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //bool rankInHand(Card c) const;

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const;

    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const;

    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    /* FUNCTION - string showHand
     * output is a string representing the player's hand
         o returns the cards in one long string

     precondition:  the cards in the hand are all valid

     input params - none

     output params - return a string of the hand
    */
    string showHand() const;

    /* FUNCTION - string showBooks
     * output is a string representing the player's books
         o returns the books in one long string

     precondition: the cards in the book are all valid and all the books are valid

     input params - none

     output params - return a string of the books
    */
    string showBooks() const;

    /* FUNCTION - int getHandSize
     * gets the number of cards in the player's hand
         o returns an int that is the size of the hand

     precondition: hand is full of valid cards

     input params - none

     output params - return an int of the hand size
    */
    int getHandSize() const;

    /* FUNCTION - int getBookSize
     * gets the number of books in the player's book
         o returns an int that is the size of the book

     precondition: book is full of valid cards

     input params - none

     output params - return an int of the book size
    */
    int getBookSize() const;

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

//    bool sameRankInHand(Card c) const;


private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};


#endif
