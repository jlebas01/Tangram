//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SQUARE_H
#define TANGRAM_SQUARE_H

#include <utility>
#include <drawable/Piece.hpp>

class Square : public Piece {
private:

    std::pair <double,double> p1; //left-top side
    std::pair <double,double> p2; //right-bot side

public:
    ~Square();
    Square(std::pair <double,double>,std::pair<double,double>);
    void move(std::pair<double,double>) override;
    void rotate(double angular) override;
    void flip() override;
    double getPerimeter() override;
    std::vector<std::pair<double,double>> getPoints() override;

};


#endif //TANGRAM_SQUARE_H
