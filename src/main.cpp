#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "grid.hpp"
#include "draw.hpp"
#include "shapes.hpp"

#define DEFAULT_GAME_TICK 0.6
#define ENGINE_TICK 0.03

float gameTickLength = DEFAULT_GAME_TICK;

const sf::Font font("./Bytesized-Regular.ttf");


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({GRID_WIDTH*GRID_SIZE + WINDOW_BORDER, GRID_HEIGHT*GRID_SIZE + WINDOW_BORDER}), "LiTetris");
    window.setFramerateLimit(144);

    Tetris::Shapes::SevenBag myBag;

    Tetris::Grid myGrid;
    Tetris::Shapes::Shape newShape(myBag.GetShape());
    myGrid.AddShape(newShape);

    time_t lastTickTime = time(NULL);
    time_t lastEngineTickTime = time(NULL);

    bool isGameOngoing = true;

    while (window.isOpen())
    {
        window.clear();

        if(isGameOngoing){   
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
                        lastTickTime = time(NULL);
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
                        lastTickTime = time(NULL);
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
                        lastTickTime = time(NULL);
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
                        lastTickTime = time(NULL);
                    }
                        
                }
            }
            time_t now = time(NULL);
            if(difftime(now, lastTickTime) > gameTickLength){ // DoGameTick
                lastTickTime = now;
                if(myGrid.CheckMoveLegal(newShape.TryMove(Tetris::Shapes::Direction::Down), newShape))
                {   
                    myGrid.ClearSpaces(newShape.GetCoords());
                    newShape.Move(Tetris::Shapes::Direction::Down);
                    
                    myGrid.AddShape(newShape);
                }
                else{
                    if(!myGrid.CheckIfGameOver(newShape)){
                        myGrid.AddShape(newShape);
                        newShape = myBag.GetShape();
                        myGrid.DoLineClears();
                    }
                    else{
                        isGameOngoing = false;
                    }
                }
            }
        }
        else{
            sf::Text text(font, "Game Over. Press Esc to Quit.");
            text.setCharacterSize(28);
            window.draw(text);
            while (const std::optional event = window.pollEvent())
            {
                if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                    if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                        window.close();
                    }
                }
            }
        }



        Tetris::Draw::DrawGuidelines(window);
        
        myGrid.DrawGrid(window);
        Tetris::Draw::DrawEdges(window);

        window.display();
    }

    std::cout << myGrid.ToString();
}
