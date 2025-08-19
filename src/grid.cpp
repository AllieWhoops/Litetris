#include <stdlib.h>
#include "grid.hpp"
#include "draw.hpp"
#include "shapes.hpp"
#include <iostream>
#include <array>
#include <vector>

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

bool Grid::CheckMoveLegal(std::array<std::array<int, 2>, 4> newCoords, Tetris::Shapes::Shape thisShape){ // If any space is not transparent, returns false
    int problemPoints = 0;

    for(auto point : newCoords){

        std::cout << point[0] << " " << point[1] << "\n";

        if(point[0] >= GRID_WIDTH || point[0] < 0){
            std::cout << "X coord not in range";
            return false;
        }
        if(point[1] >= GRID_HEIGHT || point[1] < 0){
            std::cout << "Y coord not in range" << "\n";
            return false;
        }

        if(arrGrid[point[0]][point[1]].col != sf::Color::Transparent){
            problemPoints++;

            for(auto myPoint : thisShape.GetCoords()){
                if(point == myPoint){
                    problemPoints--;
                }   
            }  
        }
    }

    if(problemPoints > 0){
        return false;
    }

    return true;
}

void Grid::DoLineClears(){
    std::vector<int> fullLines = {};
    int rowNo = 0;
    for(int y = 0; y < GRID_HEIGHT; y++){
        
        bool isRowFull = true;

        for(int x = 0; x < GRID_WIDTH; x++){
            if(arrGrid[x][y].col == sf::Color::Transparent) isRowFull = false;
        }
        if(isRowFull){
            fullLines.push_back(rowNo);
        }
        rowNo++;
    }

    std::cout << "No. full lines: " << fullLines.size() << "\n";

    for(auto rowIdx : fullLines){
        for(int x = 0; x < GRID_WIDTH; x++){
            arrGrid[x][rowIdx].col = sf::Color::Transparent;
        }
        for(int row = rowIdx; row > 0; row--){
            for(int x = 0; x < GRID_WIDTH; x++){
                arrGrid[x][row] = arrGrid[x][row-1];
            }
        }
        for(int x = 0; x < GRID_WIDTH; x++){
            arrGrid[x][0].col = sf::Color::Transparent;
        }
        std::cout << "Cleared row " << rowIdx << "\n";
    }

}

bool Grid::CheckIfGameOver(Tetris::Shapes::Shape thisShape){
    for(auto point : thisShape.GetCoords()){
        if(point[1] < 2){
            return true;
        }
    }
    return false;

}


