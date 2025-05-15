#include <stdlib.h>
#include "grid.hpp"

using namespace Tetris;

Grid::Grid()
{

}

void Grid::AddShape(int slots[4][2]){
    
}

std::string Grid::ToString(){
    std::string res = "";

    for(int x = 0; x < GRID_WIDTH; x++){
        for(int y = 0; y < GRID_HEIGHT; y++){
            res += this->myGrid.GetChar();//[x*GRID_WIDTH + y].GetChar() + " ";
        }
        res += "\n";
    }

    return res;
}


