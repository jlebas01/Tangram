//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_PIECE_H
#define TANGRAM_PIECE_H

#include <vector>

class Piece {
public :

    virtual ~Piece() = 0;

    virtual void move(std::pair<double, double> translation) = 0;

    virtual void rotate(double angular) = 0;

    virtual void flip() = 0;

    virtual std::vector<std::pair<double, double>> getPoints() = 0;

    virtual std::string toString() = 0;

    static double computeDistance(std::pair<double, double> point1, std::pair<double, double> point2);
};

#endif //TANGRAM_PIECE_H
