#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <climits> 
#ifndef TABLE_H
#define TABLE_H

class Table{
  private:
    std::vector<Player> table,losers;
    int numSeats = 0, ante = 0,seat = 0;
    Player temp;
    void evaluate(){
        seat = 0;
        for(int i = 0; i < numSeats; i++){
            if(table.size() > 1){
                if(table[seat].hand.getValue() < table[i].hand.getValue()) seat = i;
                else if(table[seat].hand.getValue() == table[i].hand.getValue()){
                    if(table[seat].hand.getSuitNum() < table[i].hand.getSuitNum()) seat = i;
                } 
            }
        }
    }    
  public:
    Table(int numSeats, int ante){
        this->numSeats = numSeats;
        this->ante = ante;
        }
    
    bool emptySeat(){
        return (table.size() < numSeats);
    }
    
        
    void addPlayer(Player p){
            table.push_back(p);
    }
    
    std::vector<Player> playRound(){
        Deck deck;
        deck.shuffle();
        for(unsigned int i = 0; i < numSeats; i++){
           // std::cout<<"loop i "<<i<<std::endl;
            table[i].bet(ante);
            table[i].hand = deck.draw();
            deck.discard();
            //std::cout<<"card value "<<table[i].hand.getValue()<<std::endl;
        }
        evaluate();
        table[seat].collectWinnings(numSeats * ante);
        
        for(int i = numSeats - 1; i = 0; i--){
            if(i != seat){
                losers.push_back(table.back());
                table.pop_back();
            }
            else{
               temp.copy(table.back());
               table.pop_back();
            }
        }
        table.push_back(temp);
        return losers;
    }
    
    void printWinner(){
        std::cout<<"The winner is"<<table[seat].getName()<<std::endl;
    }
};





#endif