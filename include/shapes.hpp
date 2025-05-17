#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define Y_OFFSET 2


namespace Tetris::Shapes{

    enum ShapeType{ // Enum for every type of shape.
        I,
        O,
        T,
        S,
        Z,
        J,
        L
    };

    class Shape{
        enum ShapeType type;
        std::array<std::array<int, 2>, 4> coords;
        std::array<int, 2> origin;
        void DoIRotation();
        int position;
        
        public:
            Shape(enum ShapeType type);
            sf::Color ShapeColor();
            void SetCoords();
            std::array<std::array<int, 2>, 4> GetCoords();
            void Rotate(bool clockwise = true);
            void Lower();
            
            
    };

}