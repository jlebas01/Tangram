//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SQUARE_H
#define TANGRAM_SQUARE_H

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

class Square : public Shape {
private:

    std::vector<STriangle> triangle;

public:
    ~Square() override;

    explicit Square(const std::vector<STriangle> &triangle);

    Square();

    void move(Point<double>) override;

    void rotate(double angular) override;

    void flip() override;

    void draw() override;

    bool is_in_shape(Point<double> click) override;

    std::vector<Point<double>> getPoints() override;

    std::string toString() override;

};

#endif //TANGRAM_SQUARE_H
