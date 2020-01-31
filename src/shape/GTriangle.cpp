//
// Created by jlebas01 on 15/01/2020.
//

#include <tuple>
#include <string>
#include <utility>

#include <shape/GTriangle.hpp>


GTriangle::~GTriangle() {
    triangle.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<STriangle>().swap(triangle);
}

GTriangle::GTriangle(const std::vector<STriangle> &triangles) {
    for (auto &it : triangles) {
        this->triangle.push_back(it);
    }
}

GTriangle::GTriangle() {
    this->triangle.emplace_back(STriangle(Point<double>(0.0, 0.0), Point<double>(2.0, 0.0),
                                          Point<double>(2.0, 2.0)));
    this->triangle.emplace_back(STriangle(Point<double>(2.0, 0.0), Point<double>(2.0, 2.0),
                                          Point<double>(4.0, 0.0)));

    this->triangle.emplace_back(STriangle(Point<double>(4.0, 0.0), Point<double>(4.0, 2.0),
                                          Point<double>(2.0, 2.0)));
    this->triangle.emplace_back(STriangle(Point<double>(2.0, 2.0), Point<double>(4.0, 2.0),
                                          Point<double>(4.0, 4.0)));
}


void GTriangle::move(Point<double> translation) {
    for (auto &it : triangle) {
        it.move(translation);
    }
}

void GTriangle::rotate(double angular) {
    for (auto &it : triangle) {
        it.rotate(angular);
    }
}

void GTriangle::flip() {
    for (auto &it : triangle) {
        it.flip();
    }
}

void GTriangle::draw() {
    std::vector<Point<double>> list_points = this->getPoints();
    int * x_points = new int[list_points.size()];
    int * y_points = new int[list_points.size()];
    int i = 0;
    for(auto & it: list_points){
        x_points[i] = static_cast<int>(it.x);
        y_points[i] = static_cast<int>(it.y);
        i++;
    }


    MLV_draw_filled_polygon(x_points, y_points, static_cast<int>(list_points.size()),MLV_COLOR_RED);
}


std::vector<Point<double>> GTriangle::getPoints() {
    std::vector<Point<double>> points;
    for (auto &it : triangle) {
        //add all points of vector triangle n in vector points
        points.insert(points.end(), it.getPoints().begin(), it.getPoints().end());
    }
    return points;
}

std::string GTriangle::toString() {
    std::string t;
    for (auto[it, i] = std::tuple{triangle.begin(), 1}; it != triangle.end(); i++, it++) {
        t += std::string("Triangle ") + std::to_string(i) + std::string(" :\n") + it->toString();
    }
    return t;
}

