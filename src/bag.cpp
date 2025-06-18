#include <stdlib.h> 
#include "grid.hpp"
#include <array>
#include "shapes.hpp"
#include <random>
#include <list>
#include <vector>

using namespace Tetris::Shapes;

SevenBag::SevenBag(){
    RefreshBag();
};

void SevenBag::RefreshBag(){
    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<int> newBag = {};

    for(int i = 0; i < 7; i++){
        newBag.push_back(i);
    };

    std::shuffle(newBag.begin(), newBag.end(), g);

    bag = newBag;
}

enum ShapeType SevenBag::GetShape(){
    if(bag.empty()){
        RefreshBag();
        return GetShape();
    }
    else{
        enum ShapeType t = static_cast<ShapeType>(bag.back());
        bag.pop_back();
        return t;
    }
}
