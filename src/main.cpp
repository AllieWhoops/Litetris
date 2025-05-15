#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <cstdlib>
#include <iostream>
#include "grid.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({640u, 400u}), "Tetris");
    window.setFramerateLimit(144);

    Tetris::Grid myGrid;
    //std::cout << myGrid.ToString();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}
