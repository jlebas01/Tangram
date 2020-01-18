//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_STRIANGLE_H
#define TANGRAM_STRIANGLE_H


#include <drawable/Piece.hpp>

class STriangle{
private:
    std::pair<double,double> p1;
    std::pair<double,double> p2;
    std::pair<double,double> p3;
    std::pair<double,double> center;

public:
    ~STriangle();
    STriangle();
    STriangle(std::pair<double,double>, std::pair<double,double>, std::pair<double,double>);
    std::pair<double,double> center_point();
    void move(std::pair<double,double>);
    void rotate(double angular);
    void flip();
    std::vector<std::pair<double,double>> getPoints();
    std::string toString();
};


#endif //TANGRAM_STRIANGLE_H
