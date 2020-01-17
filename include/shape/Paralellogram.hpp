//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_PARALELLOGRAM_H
#define TANGRAM_PARALELLOGRAM_H


#include <drawable/Piece.hpp>

class Paralellogram : public Piece{
private:

    std::pair <double,double> p1;
    std::pair <double,double> p2;
    std::pair <double,double> p3;
    std::pair <double,double> p4;

public:
    ~Paralellogram();
    Paralellogram(std::pair <double,double>, std::pair<double,double>, std::pair<double,double>, std::pair<double,double>);
    void move(std::pair<double,double>) override;
    void rotate(double angular) override;
    void flip() override;
    double getPerimeter() override;
    std::vector<std::pair<double,double>> getPoints() override;
    std::string toString() override;

};


#endif //TANGRAM_PARALELLOGRAM_H
