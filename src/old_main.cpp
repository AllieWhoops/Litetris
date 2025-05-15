#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <cstdlib>

int oldmain()
{
    auto window = sf::RenderWindow(sf::VideoMode({640u, 400u}), "Can't catch me!", sf::Style::Default);
    window.setFramerateLimit(144);

    
    int dx = sf::VideoMode::getDesktopMode().size.x;
    int dy = sf::VideoMode::getDesktopMode().size.y;
    
    int grid[3][3][2];
    
    for(int x = 1; x < 4; x++){
        for(int y = 1; y < 4; y++){
            
            grid[x-1][y-1][0] = (int)std::round((float)x / (float)4 * dx - 0.5 * window.getSize().x) ;
            grid[x-1][y-1][1] = (int)std::round((float)y / (float)4 * dy - 0.5 * window.getSize().y);
        }
    }

    window.setPosition(sf::Vector2i(grid[0][0][0], grid[0][0][1]));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
            else if(const auto* hover = event->getIf<sf::Event::MouseEntered>()){
                int nx, ny;
                
                do{
                    nx = rand() % 3;
                    ny = rand() % 3;
                } while(grid[nx][ny][0] == window.getPosition().x && grid[nx][ny][1] == window.getPosition().y);

                window.setPosition(sf::Vector2i(grid[nx][ny][0], grid[nx][ny][1]));
            }

        
        }
        window.clear();
        window.display();
    }
}
