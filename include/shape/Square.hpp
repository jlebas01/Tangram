//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SQUARE_H
#define TANGRAM_SQUARE_H

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>

class Square : public Shape {
private:

    std::vector<STriangle> triangle;

public:
    ~Square() override;

    explicit Square(const std::vector<STriangle> &triangle);

    Square();

    void move(std::pair<double, double>) override;

    void rotate(double angular) override;

    void flip() override;

    std::vector<std::pair<double, double>> getPoints() override;

    std::string toString() override;

};

#endif //TANGRAM_SQUARE_H
