//
// Created by jlebas01 on 15/01/2020.
//

#include <tuple>
#include <string>

#include <shape/Square.hpp>


Square::~Square() {
    triangle.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<STriangle>().swap(triangle);
}

Square::Square(const std::vector<STriangle> &_triangle, MLV_Color _color) {
    for (auto &it : _triangle) {
        this->triangle.push_back(it);
    }
    this->color = _color;
}

Square::Square(MLV_Color _color) {
    this->triangle.emplace_back(STriangle(Point<double>(0.0, 0.0), Point<double>(0.0, 100.0),
                                          Point<double>(100.0, 0.0), _color));
    this->triangle.emplace_back(STriangle(Point<double>(100.0, 100.0), Point<double>(0.0, 100.0),
                                          Point<double>(100.0, 0.0), _color));
    this->color = _color;
}

Square::Square(const Point<double> &origin, const double angular, MLV_Color _color) : Square() {
    parameter(origin, angular);
    this->color = _color;
}

void Square::parameter(const Point<double> &origin, const double angular) {
    rotate(angular);
    move({origin.x, origin.y});
}

Point<double> Square::center_shape() {
    std::vector<Point<double>> center_points;
    for (auto &it : triangle) {
        center_points.push_back(it.get_center_point());
    }
    Point<double> const point_rotate = STriangle::center_point(center_points);
    return point_rotate;
}

void Square::move(const Point<double> &translation) {
    for (auto &it : triangle) {
        it.move(translation);
    }
}

void Square::rotate(double angular) {
    Point<double> const point_rotate = center_shape();
    for (auto &it : triangle) {
        it.rotate(angular, point_rotate);
    }
}

void Square::flip() {
    for (auto &it : triangle) {
        it.flip();
    }
}

void Square::draw() {
    for (auto &it : triangle) {
        it.draw(this->color);
    }
}

bool Square::is_in_shape(const Point<double> &click) {
    for (auto &it : triangle) {
        if (it.is_in_triangle(click)) {
            return true;
        }
    }
    return false;
}

std::vector<Point<double>> Square::get_Points() {
    std::vector<Point<double>> list_points;
    for (auto &it: triangle){
        for (auto &it2 : it.get_Points()){
            list_points.push_back(it2);
        }
    }
    return list_points;
}

std::string Square::toString() {
    std::string t;
    for (auto[it, i] = std::tuple{triangle.begin(), 1}; it != triangle.end(); i++, it++) {
        t += std::string("Triangle ") + std::to_string(i) + std::string(" :\n") + it->toString();
    }
    return t;
}

