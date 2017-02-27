#include <iostream>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
#include "Card.h"
#ifndef DECK_H
#define DECK_H

class Deck{
  private:

  public:
    std::deque<Card> deck;
    std::deque<Card>::iterator iv,ivt;
    Deck(){
        for(int i=1;i<5;i++){
            for(int j=1;j<14;j++){
                deck.push_back(Card(i,j));
            }
        }
    }
    
    void shuffle(){
        std::random_shuffle(deck.begin(),deck.end());
    }
    
    Card draw(){
        return deck.back();
    }
    
    void discard(){
        iv=deck.end();
        deck.erase(iv);
        return;
    }
};

#endif