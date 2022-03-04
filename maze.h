#ifndef Maze_h
#define Maze_h
#include <iostream> 
#include <vector>
#include <string>
#include <utility>



class Maze {
    
    private:
    
    int height;
    int width;
    int seed; 
    std:: string fileName;

    
    std:: vector<std:: vector <int>> maze;
    std:: vector<std:: vector <bool>> visit;
    std:: vector< std:: pair<int, int>> A;
 
    
    public:
    
    Maze(int h, int w, int s, std::string file);
    void initialize_Maze();
    void mazeGen();
    void printmaze();
    
    
    
  
  
    #endif 

};

    
    
    