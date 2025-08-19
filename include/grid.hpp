#pragma once
#define GRID_WIDTH 10
#define GRID_HEIGHT 22
#define WINDOW_BORDER 100
#define GRID_SIZE 30

#include <string>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "shapes.hpp"

namespace Tetris
{
    const sf::Color Orange = sf::Color(255, 136, 0);

    class GridSpace // Class wrapper for GridColour enum 
    {
        public:
            GridSpace();
            std::string GetChar();
            sf::Color col;
    };

    class Grid // Holds the grid that is the tetris board
    {
        
        std::array<std::array<GridSpace, GRID_HEIGHT>, GRID_WIDTH> arrGrid;

        public:
            Grid();
            void AddShape(int slots[4][2], sf::Color col); // Adds shape to grid given slots & colour
            void AddShape(Tetris::Shapes::Shape shape); // Adds shape to grid given Shape object
            std::string ToString(); // Return string representation of grid
            void DrawGrid(sf::RenderWindow &window); // Calls DrawSquare to draw every space on the grid.
            void ClearSpaces(std::array<std::array<int, 2>, 4> spaces); // Sets given squares in grid to transparent
            bool CheckMoveLegal(std::array<std::array<int, 2>, 4> newCoords, Tetris::Shapes::Shape thisShape);
            void DoLineClears();
            bool CheckIfGameOver(Tetris::Shapes::Shape thisShape);
    };


}


