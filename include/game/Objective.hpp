//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_OBJECTIVE_H
#define TANGRAM_OBJECTIVE_H


#include <drawable/Shape.hpp>

class Objective {
private:
    std::vector<Shape> piece;
public:
    bool boardCompleted(std::vector<Shape> objective, std::vector<Shape> game);
};


#endif //TANGRAM_OBJECTIVE_H
