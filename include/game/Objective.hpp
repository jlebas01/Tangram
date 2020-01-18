//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_OBJECTIVE_H
#define TANGRAM_OBJECTIVE_H


#include <drawable/Piece.hpp>

class Objective {
private:
    std::vector<Piece> piece;
public:
    bool boardCompleted(std::vector<Piece> objective, std::vector<Piece> game);
    double computePerimeterAllShape(std::vector<Piece> pieces);
};


#endif //TANGRAM_OBJECTIVE_H
