#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "grid.hpp"

namespace Tetris::Draw{
    void DrawEdges(sf::RenderWindow &window);
    
    void DrawSquare(sf::RenderWindow &window, int x, int y, sf::Color col);
}