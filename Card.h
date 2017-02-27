#include <iostream>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
#ifndef CARD_H
#define CARD_H

using std::string;

class Card{
    private:
        int suit;
        int value;
        
    public:
        std::map<int,string> card;
        
        Card(){}
        
        Card(int suit, int value){
            this->suit=suit;
            this->value=value;
            
            // card.insert(std::pair<int, string>(1, "Club"));
            // card.insert(std::pair<int, string>(2, "Spade"));
            // card.insert(std::pair<int, string>(3, "Diamond"));
            // card.insert(std::pair<int, string>(4, "Heart"));
            card[1] = "Club";
            card[2] = "Diamond";
            card[3] = "Heart";
            card[4] = "Spade";

             
        }
        
        
        int getValue(){
            return this->value;
        }
        
        int getSuitNum(){
            return this->suit;
        }
        
        string getSuitName(){
            int x=this->getSuitNum();
            return card.find(x)->second;
        }
};

#endif 