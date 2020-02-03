//
// Created by jlebas01 on 15/01/2020.
//

#include <tuple>
#include <string>

#include <shape/Parallelogram.hpp>

Parallelogram::~Parallelogram() {
    triangle.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<STriangle>().swap(triangle);
}

Parallelogram::Parallelogram(const std::vector<STriangle> &triangles) {
    for (auto &it : triangles) {
        this->triangle.push_back(it);
    }
}

Parallelogram::Parallelogram() {
    this->triangle.emplace_back(STriangle(Point<double>(100.0, 0.0), Point<double>(100.0, 100.0),
                                          Point<double>(0.0, 100.0)));
    this->triangle.emplace_back(STriangle(Point<double>(0.0, 200.0), Point<double>(100.0, 100.0),
                                          Point<double>(0.0, 100.0)));
}

Parallelogram::Parallelogram(const Point<double> origin, const double angular) : Parallelogram() {
    parameter(origin, angular);
}

void Parallelogram::parameter(const Point<double> origin, const double angular = 0.0) {
    rotate(angular);
    move({origin.x, origin.y});
}

Point<double> Parallelogram::center_shape() {
    std::vector<Point<double>> center_points;
    for (auto &it : triangle) {
        center_points.push_back(it.get_center_point());
    }
    Point<double> const point_rotate = STriangle::center_point(center_points);
    return point_rotate;
}

void Parallelogram::move(Point<double> translation) {
    for (auto &it : triangle) {
        it.move(translation);
    }
}

void Parallelogram::rotate(double angular) {
    Point<double> const point_rotate = center_shape();
    for (auto &it : triangle) {
        it.rotate(angular, point_rotate);
    }
}

void Parallelogram::flip() {
    for (auto &it : triangle) {
        it.flip();
    }
}

void Parallelogram::draw() {
    for (auto &it : triangle) {
        it.draw(MLV_COLOR_BLUE);
    }
}

bool Parallelogram::is_in_shape(const Point<double> click) {
    for (auto &it : triangle) {
        if (it.is_in_triangle(click)) {
            return true;
        }
    }
    return false;
}

std::string Parallelogram::toString() {
    std::string t;
    for (auto[it, i] = std::tuple{triangle.begin(), 1}; it != triangle.end(); i++, it++) {
        t += std::string("Triangle ") + std::to_string(i) + std::string(" :\n") + it->toString();
    }
    return t;
}
