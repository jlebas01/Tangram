//
// Created by jlebas01 on 15/01/2020.
//

#include <tuple>
#include <string>
#include <utility>

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
    this->triangle.emplace_back(STriangle(std::pair<double, double>(2.0, 0.0), std::pair<double, double>(2.0, 2.0),
                                          std::pair<double, double>(0.0, 2.0)));
    this->triangle.emplace_back(STriangle(std::pair<double, double>(0.0, 2.0), std::pair<double, double>(2.0, 2.0),
                                          std::pair<double, double>(0.0, 4.0)));
}


void Parallelogram::move(std::pair<double, double> translation) {
    for (auto &it : triangle) {
        it.move(translation);
    }
}

void Parallelogram::rotate(double angular) {
    for (auto &it : triangle) {
        it.rotate(angular);
    }
}

void Parallelogram::flip() {
    for (auto &it : triangle) {
        it.flip();
    }
}

std::vector<std::pair<double, double>> Parallelogram::getPoints() {
    std::vector<std::pair<double, double>> points;
    for (auto &it : triangle) {
        //add all points of vector triangle n in vector points
        points.insert(points.end(), it.getPoints().begin(), it.getPoints().end());
    }
    return points;
}

std::string Parallelogram::toString() {
    std::string t;
    for (auto[it, i] = std::tuple{triangle.begin(), 1}; it != triangle.end(); i++, it++) {
        t += std::string("Triangle ") + std::to_string(i) + std::string(" :\n") + it->toString();
    }
    return t;
}
