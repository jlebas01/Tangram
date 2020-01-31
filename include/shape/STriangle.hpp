//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_STRIANGLE_H
#define TANGRAM_STRIANGLE_H

#include <vector>

#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

class STriangle : public Shape {
private:
    std::vector<Point<double>> points;
    Point<double> center = center_point();

    Point<double> center_point();

public:
    ~STriangle() override;

    explicit STriangle(const std::vector<Point<double>> &points);

    STriangle();

    STriangle(Point<double>, Point<double>, Point<double>);

    void move(Point<double>) override;

    void rotate(double angular) override;

    void flip() override;

    void draw() override;

    std::vector<Point<double>> getPoints() override;

    std::string toString() override;

    double computeDistance(Point<double> point1, Point<double> point2);
};

#endif //TANGRAM_STRIANGLE_H
