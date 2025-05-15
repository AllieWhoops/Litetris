#include "gridspace.hpp"

using namespace Tetris;

GridSpace::GridSpace(){
    col = None;
}

char GridSpace::GetChar(){
    switch(this->col){
        case Blue:
            return 'B';
        case Indigo:
            return 'I';
        case Orange:
            return 'O';
        case Yellow:
            return 'Y';
        case Green:
            return 'G';
        case Purple:
            return 'P';
        case Red:
            return 'R';
        default:
            return '-';
    }
}
