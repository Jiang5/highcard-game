#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Player.h"
#ifndef HEAP_H
#define HEAP_H

//max heap
class Heap{
    private:
        std::vector<Player> array;
        
        void swap(int pos, int j){
            Player temp(array[pos].getName(),array[pos].getBudget());
            array[pos] = array[j];
            array[j] = temp;
        }
        
        void siftdown(int pos){
          if(pos < 0 || pos >= array.size()) {
              return;}
          while(left(pos) != -1 && right(pos) != -1){  //whether is leaf
              int j = left(pos);
              if((j+1 < array.size()) && (array[j].getBudget() < array[j+1].getBudget())) j++;
              if(array[pos].getBudget() > array[j].getBudget()) return;
              swap(pos, j);
              pos = j;
          }
          if(array.size()==2){
              int j = left(pos);
              if(array[pos].getBudget() > array[j].getBudget()) return;
              swap(pos, j);
          }
          return;
        }
        
        int left(int parent){
            int i = parent * 2  + 1;
            return (i < array.size()) ? i : -1;
        }
        
        int right(int parent){
            int i = parent * 2 + 2;
            return (i < array.size()) ? i : -1;
        }
        
        int parent(int child){
            if(child != 0){
                int i = (child - 1) / 2;
                return i;
            }
            return -1;
        }  
        
        void buildheap(){
            for(int i = parent(array.size()-1) ; i >= 0; i --) siftdown(i);
            return;
        }
        
        
        
    public:
        Heap(Heap & h){
            for(int i = 0; i < h.size(); i++){
                this->array.push_back(h.getArray().at(i));
            }
            
        }
        Heap(string filename){
            string name;
            int budget;
            std::ifstream myfile(filename.c_str());
            
            if(!myfile.is_open()) std::cerr<<"failed to open file/n";
            else{
                while(std::getline(myfile,name)){
                    myfile>>budget;
                    array.push_back(Player(name, budget));
                    myfile.ignore();
                }
                myfile.close();
               buildheap();
            }
            
             for(unsigned int i=0;i<array.size();i++){
                int x = (array[i].getBudget());
            }
            
            return;
        }
        

        
        void addPlayer(Player newPlayer){
            array.push_back(newPlayer);
            buildheap();
        }
        
        Player getPlayer(){

            Player *temp = new Player(array[0].getName(),array[0].getBudget()); 
            array[0] = array[array.size() - 1];
            array.pop_back();
            siftdown(0);
            return *temp;
        }
        
        std::vector<Player> getArray(){
            return array;
        }
        
        bool empty(){
            return array.size() == 0;
        }
        
        unsigned int size(){
            return array.size();
        }
};

#endif