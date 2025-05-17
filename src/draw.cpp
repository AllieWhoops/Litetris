#include "draw.hpp"
#include "shapes.hpp"

void Tetris::Draw::DrawEdges(sf::RenderWindow &window) // Draw the bounding box around the Tetrix grid
{        std::array left_line = {
            sf::Vertex{sf::Vector2f(0.5f*WINDOW_BORDER, 0.5f*WINDOW_BORDER + GRID_SIZE*Y_OFFSET)},
            sf::Vertex{sf::Vector2f(0.5f*WINDOW_BORDER, 0.5f*WINDOW_BORDER + GRID_HEIGHT*GRID_SIZE)}
        };
        std::array bottom_line = {
            sf::Vertex{sf::Vector2f(0.5f*WINDOW_BORDER, 0.5f*WINDOW_BORDER + GRID_HEIGHT*GRID_SIZE)},
            sf::Vertex{sf::Vector2f(0.5f*WINDOW_BORDER + GRID_WIDTH*GRID_SIZE,  0.5f*WINDOW_BORDER + GRID_HEIGHT*GRID_SIZE)}
        };
        std::array right_line = {
            sf::Vertex{sf::Vector2f(0.5f*WINDOW_BORDER + GRID_WIDTH*GRID_SIZE, 0.5f*WINDOW_BORDER + GRID_SIZE*Y_OFFSET)},
            sf::Vertex{sf::Vector2f(0.5f*WINDOW_BORDER + GRID_WIDTH*GRID_SIZE, 0.5f*WINDOW_BORDER + GRID_HEIGHT*GRID_SIZE)}
        };

        window.draw(left_line.data(), left_line.size(), sf::PrimitiveType::Lines);
        window.draw(bottom_line.data(), bottom_line.size(), sf::PrimitiveType::Lines);
        window.draw(right_line.data(), right_line.size(), sf::PrimitiveType::Lines);
}

void Tetris::Draw::DrawSquare(sf::RenderWindow &window, int x, int y, sf::Color col){ // Method for drawing each box in the grid
    sf::RectangleShape rect({GRID_SIZE, GRID_SIZE}); // Create new rectangle that matches the size of each grid space.
    rect.setPosition({WINDOW_BORDER*0.5f + x*GRID_SIZE, WINDOW_BORDER*0.5f + y*GRID_SIZE}); // Sets it to relevant position
    rect.setFillColor(col); // Paints rectangle correct colour
    window.draw(rect); // Draws rect on window
}