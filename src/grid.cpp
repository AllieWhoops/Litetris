#include <stdlib.h>
#include "grid.hpp"
#include "draw.hpp"
#include "shapes.hpp"
#include <iostream>
#include <array>

using namespace Tetris;

Grid::Grid() // Constructor for Grid class (doesn't do anything :pensive:)
{

}

void Grid::DrawGrid(sf::RenderWindow &window){ // Calls DrawSquare to draw every space on the grid.
    for(int x = 0; x < GRID_WIDTH; x++){
        for(int y = 0; y < GRID_HEIGHT; y++){
            if(arrGrid[x][y].col == sf::Color::Transparent){ // Skips drawing if transparent (since basically doing nothing)
                continue;
            }
            else{
                Draw::DrawSquare(window, x, y, arrGrid[x][y].col); // Draws square in grid slot with given colour
            }
        }
    }
}

void Grid::AddShape(int slots[4][2], sf::Color col){ // Adds shape to grid given slots & colour
   for(int i = 0; i < 4; i++){
        arrGrid[slots[i][0]][slots[i][1]].col = col;
   }
}

void Grid::AddShape(Tetris::Shapes::Shape shape){ // Adds shape to grid given Shape object
    std::array<std::array<int, 2>, 4> slots = shape.GetCoords();
    for(int i = 0; i < 4; i++){
        arrGrid[slots[i][0]][slots[i][1]].col = shape.ShapeColor();
    }
}

std::string Grid::ToString(){ // Return string representation of grid
    std::string res = "";

    for(int y = 0; y < GRID_HEIGHT; y++){
        for(int x = 0; x < GRID_WIDTH; x++){
            res += arrGrid[x][y].GetChar() + " ";
        }
        res += "\n";
    }

    return res;
}

void Grid::ClearSpaces(std::array<std::array<int, 2>, 4> spaces){ // Sets given squares in grid to transparent

    for(int i = 0; i < 4; i++){
        arrGrid[spaces[i][0]][spaces[i][1]].col = sf::Color::Transparent;
    }
    
}

bool Grid::CheckMoveLegal(std::array<std::array<int, 2>, 4> newCoords){ // If any space is not transparent, returns false
    for(auto point : newCoords){
        if(arrGrid[point[0]][point[1]].col != sf::Color::Transparent){
            return false;
        }
    }

    return true;
}


