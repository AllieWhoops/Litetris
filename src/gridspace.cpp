#include "grid.hpp"
#include <string>

using namespace Tetris;

GridSpace::GridSpace(){ // Constructor for GridSpace class
    col = sf::Color::Transparent;
}

std::string GridSpace::GetChar(){ // Returns character representation of grid space
    if(col == sf::Color::Cyan){
        return "C";
    }
    else if(col == sf::Color::Blue){
        return "B";
    }
    else if(col == Tetris::Orange){
        return "O";
    }
    else if(col == sf::Color::Yellow){
        return "Y";
    }
    else if(col == sf::Color::Green){
        return "G";
    }
    else if(col == sf::Color::Magenta){
        return "P";
    }
    else if(col == sf::Color::Red){
        return "R";
    }
    else{
        return "-";
    }
}
