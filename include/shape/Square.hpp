//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SQUARE_H
#define TANGRAM_SQUARE_H

#include <utility>
#include <drawable/Piece.hpp>
#include <shape/STriangle.hpp>

class Square : public STriangle {
private:

    std::pair <double,double> p1; //left-top side
    std::pair <double,double> p2; //right-bot side
    std::vector<STriangle> triangle;

public:
    ~Square();
    Square(std::vector<STriangle> triangle);
    Square();
    std::string toString();
    void move(std::pair<double,double>);
    void rotate(double angular);
    void flip();
    double getPerimeter();
    std::vector<std::pair<double,double>> getPoints();

};


#endif //TANGRAM_SQUARE_H
