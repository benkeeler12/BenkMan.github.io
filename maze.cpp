#include "maze.h"
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <fstream>
#include <cstdlib>






Maze::Maze(int h, int w, int s, std:: string file){
    this->height = h;
    this->width = w;
    this->seed = s;
    this->fileName = file;
    std::srand(seed); 
    
    
    initialize_Maze();
    mazeGen();
    printmaze();


    
    
  
    
}


void Maze::initialize_Maze(){
    
    for (int i = 0; i < height; i++){
         std:: vector <bool> tempboolVec;
         std:: vector <int> tempVec;
        for(int j = 0; j < width; j++){
            tempVec.push_back(15);
            tempboolVec.push_back(false);
        }
        this->maze.push_back(tempVec);
        this->visit.push_back(tempboolVec);
    }
    
    
    this->maze[0][0] = 7;
    this->maze[height-1][width-1] = 11;
    
    if (width == 1 && height == 1){
        this->maze[0][0] = 3;
    }
  
    
}


 void Maze::mazeGen() {
     this->visit[0][0] = true;
     this->A.push_back(std::make_pair(0,0));
     
     
     //BEGIN ALGORITHM
     
     while (!A.empty()){
         std::pair<int, int> curr = this->A.back();
         this->A.pop_back();
         
         // check for neighbors 

         int a = curr.first;
         int b = curr.second;
         std::vector<std::pair< char, std::pair <int, int>>> temp;
         if (((a - 1) >= 0) && this->visit[a-1][b] == false){
             temp.push_back(std::make_pair('N', std:: make_pair( (a-1),b)));
         }
         
         
         if ( (a + 1) <= (height - 1) && this->visit[a+1][b] == false){
             temp.push_back(std::make_pair('S', std:: make_pair( (a+1),b)));
         }
         
          if ( (b + 1) <= (width - 1) && this->visit[a][b+1] == false){
             temp.push_back(std::make_pair('E', std:: make_pair(a,(b+1))));
         }
         
           if ( ((b - 1) >= 0) && this->visit[a][b-1] == false){
             temp.push_back(std::make_pair('W', std:: make_pair(a,(b-1))));
         }
         
         std:: vector < std:: pair <char, std:: pair <int, int>>> neighbors = temp;

    
         
         if (!neighbors.empty()){
             this->A.push_back(curr);
       //      std::srand(this->seed);
             int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
            std::pair<char, std:: pair <int, int>> check = neighbors[idx];
             if (check.first == 'N'){
                 this->maze[curr.first-1][curr.second] += -4;
                 this->maze[curr.first][curr.second] += -8;
                 
             }
              if (check.first == 'S'){
                 this->maze[curr.first+1][curr.second] += -8;
                 this->maze[curr.first][curr.second] += -4;
               
             }
             
             if (check.first == 'E'){
                 this->maze[curr.first][curr.second+1] += -1;
                 this->maze[curr.first][curr.second] += -2;
                 
             }
             
             if (check.first == 'W'){
                 this->maze[curr.first][curr.second-1] += -2;
                 this->maze[curr.first][curr.second] += -1;
             }
             this->visit[check.second.first][check.second.second] = true;
             this->A.push_back(std:: make_pair(check.second.first, check.second.second));
             
             
             
         }
 
     }
     
 
 
 }
 


 
    
void Maze::printmaze(){
     std::ofstream outFile(fileName); 
     
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            outFile << this->maze[i][j] << " "; 
        }
         outFile << "\n";
   
    }
       
   outFile.close();
    
    
}
     
 
 