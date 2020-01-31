//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GAME_H
#define TANGRAM_GAME_H

#include <game/Objective.hpp>
#include <shape/STriangle.hpp>

class Game {
private:
    std::vector<Shape> shapes;

    void draw();

public:
    void main_loop();

    Game();

};


#endif //TANGRAM_GAME_H
