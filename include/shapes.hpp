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

    enum Direction{ // Enum for direction of move.
        Up,
        Down,
        Left,
        Right
    };

    class Shape{ // Class for a tetris piece.
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
            std::array<std::array<int, 2>, 4> TryRotate(bool clockwise = true);
            std::array<std::array<int, 2>, 4> TryMove(enum Direction direction);
            void Lower();
            void Move(enum Direction direction);
            
    };
    
    class SevenBag
    {
        std::vector<int> bag;
        void RefreshBag();

        public:
            SevenBag();
            enum ShapeType GetShape();
            
    };

};