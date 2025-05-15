#pragma once

#include "grid.hpp"

namespace Tetris
{
    class GridSpace // Class wrapper for GridColour enum 
    {
        enum GridColour col;

        public:
            GridSpace();
            char GetChar();
    };

    enum GridColour{
        None,
        Blue,
        Indigo,
        Orange,
        Yellow,
        Green,
        Purple,
        Red
    };
}

