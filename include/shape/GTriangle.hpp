//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GTRIANGLE_H
#define TANGRAM_GTRIANGLE_H

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

class GTriangle : public Shape {
private:

    std::vector<STriangle> triangle;

    void parameter(Point<double> origin, double angular);

    Point<double> center_shape();

public:
    ~GTriangle() override;

    GTriangle();

    explicit GTriangle(const std::vector<STriangle> &triangle);

    explicit GTriangle(Point<double> origin, double angular = 0.0);

    void move(Point<double>) override;

    void rotate(double angular) override;

    void flip() override;

    void draw() override;

    bool is_in_shape(Point<double> click) override;

    std::string toString() override;
};

#endif //TANGRAM_GTRIANGLE_H
