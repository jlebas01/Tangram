//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MTRIANGLE_H
#define TANGRAM_MTRIANGLE_H


#include <drawable/Piece.hpp>

class MTriangle : public Piece {
private:
    std::pair<double,double> p1;
    std::pair<double,double> p2;
    std::pair<double,double> p3;

public:
    ~MTriangle();
    MTriangle(std::pair<double,double>, std::pair<double,double>, std::pair<double,double>);
    void move(std::pair<double,double>) override;
    void rotate(double angular) override;
    void flip() override;
    double getPerimeter() override;
    std::vector<std::pair<double,double>> getPoints() override;
    std::string toString() override;

};


#endif //TANGRAM_MTRIANGLE_H
