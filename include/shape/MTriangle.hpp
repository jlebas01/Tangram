//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MTRIANGLE_H
#define TANGRAM_MTRIANGLE_H

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

class MTriangle : public Shape {
private:

    std::vector<STriangle> triangle;

public:
    ~MTriangle() override;

    explicit MTriangle(const std::vector<STriangle> &triangle);

    MTriangle();

    void move(Point<double>) override;

    void rotate(double angular) override;

    void flip() override;

    void draw() override;

    bool is_in_shape(Point<double> click) override;

    std::vector<Point<double>> getPoints() override;

    std::string toString() override;

};

#endif //TANGRAM_MTRIANGLE_H
