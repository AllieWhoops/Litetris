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
            void AddShape(int slots[4][2], sf::Color col);
            void AddShape(Tetris::Shapes::Shape shape);
            std::string ToString();
            void DrawGrid(sf::RenderWindow &window);
            void ClearSpaces(std::array<std::array<int, 2>, 4> spaces);
            bool CheckMoveLegal(std::array<std::array<int, 2>, 4> newCoords);
            
    };



}


