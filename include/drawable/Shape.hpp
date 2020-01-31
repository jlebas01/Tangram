//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_PIECE_H
#define TANGRAM_PIECE_H

#include <vector>
#include <utils/Point.hpp>

class Shape {
public :

    virtual ~Shape() = 0;

    virtual void move(Point<double> translation) = 0;

    virtual void rotate(double angular) = 0;

    virtual void flip() = 0;

    virtual std::vector<Point<double>> getPoints() = 0;

    virtual std::string toString() = 0;

};

#endif //TANGRAM_PIECE_H
