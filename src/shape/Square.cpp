//
// Created by jlebas01 on 15/01/2020.
//

#include <tuple>
#include <string>
#include <utility>

#include <shape/Square.hpp>


Square::~Square() {
    triangle.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<STriangle>().swap(triangle);
}

Square::Square(const std::vector<STriangle> &triangles) {
    for (auto &it : triangles) {
        this->triangle.push_back(it);
    }
}

Square::Square() {
    this->triangle.emplace_back(STriangle(Point<double>(0.0, 0.0), Point<double>(0.0, 2.0),
                                          Point<double>(2.0, 0.0)));
    this->triangle.emplace_back(STriangle(Point<double>(2.0, 0.0), Point<double>(2.0, 2.0),
                                          Point<double>(0.0, 2.0)));
}


void Square::move(Point<double> translation) {
    for (auto &it : triangle) {
        it.move(translation);
    }
}

void Square::rotate(double angular) {
    for (auto &it : triangle) {
        it.rotate(angular);
    }
}

void Square::flip() {
    for (auto &it : triangle) {
        it.flip();
    }
}


std::vector<Point<double>> Square::getPoints() {
    std::vector<Point<double>> points;
    for (auto &it : triangle) {
        //add all points of vector triangle n in vector points
        points.insert(points.end(), it.getPoints().begin(), it.getPoints().end());
    }
    return points;
}

std::string Square::toString() {
    std::string t;
    for (auto[it, i] = std::tuple{triangle.begin(), 1}; it != triangle.end(); i++, it++) {
        t += std::string("Triangle ") + std::to_string(i) + std::string(" :\n") + it->toString();
    }
    return t;
}

