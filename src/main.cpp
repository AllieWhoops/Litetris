#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <cstdlib>
#include <iostream>
#include "grid.hpp"
#include "draw.hpp"
#include "shapes.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({GRID_WIDTH*GRID_SIZE + WINDOW_BORDER, GRID_HEIGHT*GRID_SIZE + WINDOW_BORDER}), "Tetris");
    window.setFramerateLimit(144);

    Tetris::Grid myGrid;
    Tetris::Shapes::Shape newShape(Tetris::Shapes::I);
    myGrid.AddShape(newShape);
    

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            
            else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::R){
                    myGrid.ClearSpaces(newShape.GetCoords());
                    newShape.Rotate();
                    myGrid.AddShape(newShape);
                }
                if(keyPressed->scancode == sf::Keyboard::Scancode::S){
                    myGrid.ClearSpaces(newShape.GetCoords());
                    newShape.Lower();
                    myGrid.AddShape(newShape);
                }
                    
            }
        }

        window.clear();
        


        
        
        myGrid.DrawGrid(window);
        Tetris::Draw::DrawEdges(window);
        
        

        window.display();
    }

    std::cout << myGrid.ToString();
}
