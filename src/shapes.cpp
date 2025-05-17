#include "shapes.hpp"
#include "grid.hpp"
#include <iostream>


Tetris::Shapes::Shape::Shape(enum ShapeType type){ // Constructor for Shape class
    this->type = type; // sets shape to type
    position = 0; // sets position to default
    SetCoords(); // Configures spawn coordinates
}

void Tetris::Shapes::Shape::SetCoords(){ // Method to configure spawning coordinates for shape
    switch(type){ // Spawning coordinates vary based on the shape
        case I:
            coords = {{
                {0,1},
                {1,1},
                {2,1},
                {3,1}
            }};
            break;
        case O:
            coords = {{
                {1,0},
                {2,0},
                {1,1},
                {2,1}
            }};
            break;
        case T:
            coords = {{
                    {1,0},
                    {0,1},
                    {1,1},
                    {2,1}
                }};
                break;
        case S:
            coords = {{
                {1,0},
                {2,0},
                {0,1},
                {1,1}
            }};
            break;
        case Z:
            coords = {{
                {0,0},
                {1,0},
                {1,1},
                {2,1}
            }};
            break;
        case J:
            coords = {{
                {0,0},
                {0,1},
                {1,1},
                {2,1}
            }};
            break;
        case L:
            coords = {{
                {2,0},
                {0,1},
                {1,1},
                {2,1}
            }};
            break;
        default: return;
    }

    origin = {1,1}; // Sets origin to rotate around
}

void Tetris::Shapes::Shape::Rotate(bool clockwise){ // Method for rotating the shape
    
    std::array<std::array<int, 2>, 2> rotMatrix;

    if(clockwise){ // Position number & rotation matrix set based on rotation direction
        rotMatrix = {{
            {0, 1},
            {-1, 0}
        }};
        
        if(position < 3){
            position++;
        }
        else{
            position = 0;
        }
    }
    else{
        rotMatrix = {{
            {0, -1},
            {1, 0}
        }};

        if(position > 0){
            position--;
        }
        else{
            position = 3;
        }
    }

    
    switch(type){
        case I: // I shape is weiiiiird so we just brute force the rotation :)
            DoIRotation(); 
            return;
        case O: return; // O shape does not change position so we just return
        default: break;
    }
    
    for(int i = 0; i < 4; i++){ // Performs 90' rotation on the coordinates with the power of matrices
        int x = coords[i][0] - origin[0];
        int y = coords[i][1] - origin[1];

        coords[i][0] = rotMatrix[0][0] * x + rotMatrix[1][0] * y + origin[0];
        coords[i][1] = rotMatrix[0][1] * x + rotMatrix[1][1] * y + origin[1];
    }
}

void Tetris::Shapes::Shape::DoIRotation(){ // Method for handing rotation of I shape
    
    /* Changing to:
    - - X -
    - - X -
    - - X -
    - - X -
    */
    if(position == 1)
    {
        coords[0] = {origin[0] + 1, origin[1] - 1};
        coords[1] = {origin[0] + 1, origin[1]    };
        coords[2] = {origin[0] + 1, origin[1] + 1};
        coords[3] = {origin[0] + 1, origin[1] + 2};
    }

    /* Changing to:
    - - - -
    - - - -
    X X X X
    - - - -
    */
    else if(position == 2)
    {
        coords[0] = {origin[0] - 1, origin[1] + 1};
        coords[1] = {origin[0],     origin[1] + 1};
        coords[2] = {origin[0] + 1, origin[1] + 1};
        coords[3] = {origin[0] + 2, origin[1] + 1};
    }

    /* Changing to:
    - X - -
    - X - -
    - X - -
    - X -
    */
    else if(position == 3)
    {
        coords[0] = {origin[0], origin[1] - 1};
        coords[1] = {origin[0], origin[1]    };
        coords[2] = {origin[0], origin[1] + 1};
        coords[3] = {origin[0], origin[1] + 2};
    }

    /* Changing to:
    - - - -
    X X X X
    - - - -
    - - - -
    */
    else
    {
        coords[0] = {origin[0] - 1, origin[1]};
        coords[1] = {origin[0],     origin[1]};
        coords[2] = {origin[0] + 1, origin[1]};
        coords[3] = {origin[0] + 2, origin[1]}; 
    }
}

void Tetris::Shapes::Shape::Lower(){ // Move shape one tile lower
    for(int i = 0; i < 4; i++){
        coords[i][1]++;
    }

    origin[1]++; // Origin also lowered by one to preserve rotation
}

std::array<std::array<int, 2>, 4> Tetris::Shapes::Shape::GetCoords(){ // Get coords of shape
    return coords;
}

sf::Color Tetris::Shapes::Shape::ShapeColor(){ // Get colour of shape based on type
    switch(type){
        case I: return sf::Color::Cyan;
        case O: return sf::Color::Yellow;
        case T: return sf::Color::Magenta;
        case S: return sf::Color::Green;
        case Z: return sf::Color::Red;
        case J: return sf::Color::Blue;
        case L: return Tetris::Orange;
        default: return sf::Color::Transparent;
    }
}

