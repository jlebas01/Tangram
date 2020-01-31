//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GAME_H
#define TANGRAM_GAME_H

#include <game/Objective.hpp>
#include <drawable/Shape.hpp>

class Game {
private:
    std::vector<Shape*> shapes;
    //std::vector <std::tr1::shared_ptr<Shape> >
    int w;
    int h;

    void draw();

public:
    void main_loop();

    Game(int w, int h);

};


#endif //TANGRAM_GAME_H
