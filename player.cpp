//
// Created by Matt Golla and Iva Sadler on 11/2/2018.
//implements thed player class
#include "player.h"
#include "deck.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdlib.h>

using namespace std;

Player::Player(){
    myName = "";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1); //add cards to book
    myBook.push_back(c2);
    removeCardFromHand(c1);//take them from the hand
    removeCardFromHand(c2);
}

Card Player::removeCardFromHand(Card c) {
    for(vector<Card>::iterator iter = myHand.begin(); iter != myHand.end(); ++iter){
        if((*iter) == c){
            Card temp = (*iter);
            myHand.erase(iter);
            return temp;
        }
    }
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(vector<Card>::iterator iter = myHand.begin(); iter != myHand.end(); ++iter){
        for(vector<Card>::iterator it = iter; it != myHand.end(); ++it){
            if (((*iter).getRank() == (*it).getRank()) && (iter != it)){
                c1 = *iter;
                c2 = *it;
                return true;
            }
        }
    }
    return false;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    for(vector<Card>::iterator iter = myHand.begin(); iter != myHand.end(); ++iter){
        if((*iter).getRank() == c1.getRank()){
            c2 = *iter;
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    int num = rand() % getHandSize();
    Card c;
    for (vector<Card>::const_iterator iter = myHand.begin(); num>=0; ++iter)
    {
        c = (*iter);
        num--;
    }
    return c;
}

bool Player::cardInHand(Card c) const {
    for(vector<Card>::const_iterator iter = myHand.begin(); iter != myHand.end(); ++iter){
        if(*iter == c){
            return true;
        }
    }
    return false;
}

string Player::showHand() const {
    string result = "";
    for(vector<Card>::const_iterator iter = myHand.begin(); iter != myHand.end(); ++iter){
        result += (*iter).toString() + " ";
    }
    return result;
}

string Player::showBooks() const {
    string result = "(";
    int y = 0;
    for(vector<Card>::const_iterator iter = myBook.begin(); iter != myBook.end(); ++iter) {
        if(y != 0){
            result +=  "; (";
        }
        int x = 0;
        while (x != 2){
            result += (*iter).toString();
            if(x == 0){
                result += ", ";
                ++iter;
            }
            x++;
        }
        y=1;
        result += ")";


    }
    return result;
}

int Player::getHandSize() const{
    int num = 0;
    for(vector<Card>::const_iterator iter = myHand.begin(); iter != myHand.end(); ++iter){
        num++;
    }
    return num;
}

int Player::getBookSize() const {
    int num = 0;
    for(vector<Card>::const_iterator iter = myBook.begin(); iter != myBook.end(); ++iter){
        num++;
    }
    return num/2;
}

