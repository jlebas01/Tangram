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

    Point<double> center;

    void parameter(Point<double> origin, double angular);

    Point<double> center_point();

public:
    ~STriangle() override;

    explicit STriangle(const std::vector<Point<double>> &points);

    STriangle();

    explicit STriangle(Point<double> origin, double angular = 0.0);

    STriangle(Point<double>, Point<double>, Point<double>);

    void move(Point<double>) override;

    void rotate(double angular) override;

    void rotate(double angular, Point<double> center_point);

    void flip() override;

    void draw() override;

    bool is_in_shape(Point<double> click) override;

    std::string toString() override;

    double computeDistance(Point<double> point1, Point<double> point2);

    double sign(Point<double> p1, Point<double> p2, Point<double> p3);

    bool is_in_triangle(Point<double> click);

    void draw(MLV_Color Color);

    std::vector<Point<double>> get_Points();

    static Point<double> center_point(const std::vector<Point<double>> &list_points);

    Point<double> get_center_point();
};

#endif //TANGRAM_STRIANGLE_H
