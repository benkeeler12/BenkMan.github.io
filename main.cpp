#include <iostream>
#include "maze.h"
#include <vector>
#include <string>



int main(int argc, char*argv[]){ 
    
    int seed = std::stoi(argv[1]);
    int N = std:: stoi(argv[2]);
    int M = std:: stoi(argv[3]);
    std:: string fileName = std:: string(argv[4]);

    
    
    Maze checkmaze = Maze(N, M, seed, fileName);
    
    
    
    
    
    
    return 0; 
    
    
    
}