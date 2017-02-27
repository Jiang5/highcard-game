#include <iostream>
#include <fstream>
#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        string name;
        int budget;
        
    public:
        Card hand;
        
        void copy(Player t){
            this->name = t.getName();
            this->budget = t.getBudget();
        }
        Player(){
            
        }
        
        Player(string name, int budget){
            this->name = name;
            this->budget = budget;
        }
        
        string getName(){
            return this->name;
        }
        
        int getBudget(){
            return this->budget;
        }
        
        bool bet(int amount){
            this->budget -= amount;
            return this->budget >= 0;
        }
        
        void collectWinnings(int amount){
            budget += amount;
            return;
        }
};

#endif