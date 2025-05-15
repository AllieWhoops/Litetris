#pragma once
#define GRID_WIDTH 10
#define GRID_HEIGHT 20

#include <string>
#include <vector>
#include "gridspace.hpp"

namespace Tetris
{

    class Grid // Holds the grid that is the tetris board
    {
        GridSpace myGrid;
        public:
            Grid();
            void AddShape(int slots[4][2]);
            std::string ToString();
    };

}


