// FILE: go_fish.cpp
//Created by Matt Golla and Iva Sadler
//file in which the computer plays one game of two-player Go Fish.
//results are written to a seperate text file instead of being printed
#include <iostream>    // Provides myfile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    // setting up the file
    ofstream myfile;
    myfile.open("gofish_results.txt");

    //setting up and starting the game
    int numCards = 7;
    Player p1("Matt");
    Player p2("Iva");
    Deck d;  //create a deck of cards
    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    Card c1, c2;
    //removing pairs from the hands that were dealt
    while(p1.checkHandForBook(c1,c2)){
        p1.bookCards(c1,c2);
    }
    while(p2.checkHandForBook(c1,c2)){
        p2.bookCards(c1,c2);
    }
    myfile << p1.getName() <<" has : " << p1.showHand() << endl;
    myfile << p2.getName() <<" has : " << p2.showHand() << endl;

    while (d.size() > 0 || p1.getHandSize() !=0 || p2.getHandSize() !=0){
        //give player 1 a turn
        if (p1.getHandSize() != 0){
            c1 = p1.chooseCardFromHand();
            myfile <<p1.getName() << " asks, \"Do you have a " << c1.rankString(c1.getRank())<< "?\"" <<endl;
            if (p2.checkHandForPair(c1,c2)){
                c2 = p2.removeCardFromHand(c2);
                p1.addCard(c2);
                myfile << p2.getName() << " says, \"Yes. I have a " << c1.rankString(c1.getRank()) << ".\"" << endl;
                myfile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << "!"<< endl;
                p1.bookCards(c1,c2);
            }
            else {
                Card temp = d.dealCard();
                p1.addCard(temp);
                myfile << p2.getName() <<" says, \"No. Go Fish:P\"" << endl;
                myfile << p1.getName() << " draws " << temp << "." << endl;
                if (p1.checkHandForBook(c1,c2)){
                    p1.bookCards(c1,c2);
                    myfile << p1.getName() << " books the " << temp.rankString(temp.getRank()) << "!"<< endl;
                }
            }
        }
        else {
            Card temp = d.dealCard();
            p1.addCard(temp);
            myfile << p1.getName() << " draws " << temp << "." << endl;
        }

        myfile << endl;
        //give player 2 a turn
        if (d.size() > 0 || p1.getHandSize() !=0 || p2.getHandSize() !=0) {
            if (p2.getHandSize()!=0){

                c1 = p2.chooseCardFromHand();
                myfile <<p2.getName() << " asks, \"Do you have a " << c1.rankString(c1.getRank())<< "?\"" <<endl;
                if (p1.checkHandForPair(c1,c2)){
                    c2 = p1.removeCardFromHand(c2);
                    p2.addCard(c2);
                    myfile << p1.getName() << " says, \"Yes. I have a " << c1.rankString(c1.getRank()) << ".\"" << endl;
                    myfile << p2.getName() << " books the " << c1.rankString(c1.getRank()) << "!"<< endl;
                    p2.bookCards(c1,c2);
                }
                else {
                    Card temp = d.dealCard();
                    p2.addCard(temp);
                    myfile << p1.getName() <<" says, \"No. Go Fish:P\"" << endl;
                    myfile << p2.getName() << " draws " << temp << "." << endl;
                    if (p2.checkHandForBook(c1,c2)){
                        p2.bookCards(c1,c2);
                        myfile << p2.getName() << " books the " << temp.rankString(temp.getRank()) << "!"<< endl;
                    }
                }
            }
            else {
                Card temp = d.dealCard();
                p2.addCard(temp);
                myfile << p2.getName() << " draws " << temp << "." << endl;
            }
        }
        myfile<<endl;
    }

    //find a winner or tie
    myfile << "The game has ended." << endl;
    myfile << p1.getName() << " has " << p1.getBookSize() << " books which are "  << p1.showBooks() << endl;
    myfile << p2.getName() << " has " << p2.getBookSize() << " books which are "  << p2.showBooks() << endl;
    if (p1.getBookSize()>p2.getBookSize()){
        myfile << p1.getName() << " won the game!!" << endl;
    }
    else if (p2.getBookSize()>p1.getBookSize()){
        myfile << p2.getName() << " won the game!!" << endl;
    }
    else if ( p1.getBookSize() == p2.getBookSize()){
        myfile << p1.getName() << " and " << p2.getName() << " tied." << endl;
    }
    myfile.close();
    return EXIT_SUCCESS;

}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
