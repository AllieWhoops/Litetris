#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "grid.hpp"
#include "draw.hpp"
#include "shapes.hpp"

#define DEFAULT_GAME_TICK 1

float gameTickLength = DEFAULT_GAME_TICK;


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({GRID_WIDTH*GRID_SIZE + WINDOW_BORDER, GRID_HEIGHT*GRID_SIZE + WINDOW_BORDER}), "Tetris");
    window.setFramerateLimit(144);

    Tetris::Shapes::SevenBag myBag;

    Tetris::Grid myGrid;
    Tetris::Shapes::Shape newShape(myBag.GetShape());
    myGrid.AddShape(newShape);

    time_t lastTickTime = time(NULL);

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
                    if(myGrid.CheckMoveLegal(newShape.TryRotate(), newShape)){
                        myGrid.ClearSpaces(newShape.GetCoords());
                        newShape.Rotate();
                        myGrid.AddShape(newShape);
                    }
                    else{
                        std::cout << "Illegal\n";
                    }  

                    //std::cout << myBag.GetShape();
                }
                if(keyPressed->scancode == sf::Keyboard::Scancode::S){
                    if(myGrid.CheckMoveLegal(newShape.TryMove(Tetris::Shapes::Direction::Down), newShape))
                    {   
                        myGrid.ClearSpaces(newShape.GetCoords());
                        newShape.Move(Tetris::Shapes::Direction::Down);
                        
                        myGrid.AddShape(newShape);
                    }
                    else{
                        std::cout << "Illegal\n";
                    }
                }

                if(keyPressed->scancode == sf::Keyboard::Scancode::A){
                    if(myGrid.CheckMoveLegal(newShape.TryMove(Tetris::Shapes::Direction::Left), newShape))
                    {   
                        myGrid.ClearSpaces(newShape.GetCoords());
                        newShape.Move(Tetris::Shapes::Direction::Left);
                        
                        myGrid.AddShape(newShape);
                    }
                    else{
                        std::cout << "Illegal\n";
                    }
                }
                if(keyPressed->scancode == sf::Keyboard::Scancode::D){
                    if(myGrid.CheckMoveLegal(newShape.TryMove(Tetris::Shapes::Direction::Right), newShape))
                    {   
                        myGrid.ClearSpaces(newShape.GetCoords());
                        newShape.Move(Tetris::Shapes::Direction::Right);
                        
                        myGrid.AddShape(newShape);
                    }
                    else{
                        std::cout << "Illegal\n";
                    }
                }
                    
            }
        }
        time_t now = time(NULL);
        if(difftime(now, lastTickTime) >= gameTickLength){ // DoGameTick
            lastTickTime = now;
            if(myGrid.CheckMoveLegal(newShape.TryMove(Tetris::Shapes::Direction::Down), newShape))
            {   
                myGrid.ClearSpaces(newShape.GetCoords());
                newShape.Move(Tetris::Shapes::Direction::Down);
                
                myGrid.AddShape(newShape);
            }
            else{
                myGrid.AddShape(newShape);
                newShape = myBag.GetShape();
            }
        }

        //Check line clears
        myGrid.DoLineClears();

        window.clear();
        
        myGrid.DrawGrid(window);
        Tetris::Draw::DrawEdges(window);

        window.display();
    }

    std::cout << myGrid.ToString();
}
