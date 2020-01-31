//
// Created by jlebas01 on 15/01/2020.
//

#include <utility>
#include <cmath>
#include <tuple>

#include <shape/STriangle.hpp>


STriangle::~STriangle() {
    points.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<Point<double>>().swap(points);
}

STriangle::STriangle(const Point<double> point1, const Point<double> point2, const Point<double> point3) {
    this->points.emplace_back(point1.x, point1.y);
    this->points.emplace_back(point2.x, point2.y);
    this->points.emplace_back(point3.x, point3.y);
    this->center = this->center_point();
}

STriangle::STriangle(const std::vector<Point<double>> &points) {
    for (auto &it : points) {
        this->points.push_back(it);
    }
    this->center = this->center_point();
}

STriangle::STriangle() {
    this->points.emplace_back(0.0, 0.0);
    this->points.emplace_back(100.0, 0.0);
    this->points.emplace_back(0.0, 100.0);
    this->center = this->center_point();
}

Point<double> STriangle::center_point() {
    double sumx = 0.0, sumy = 0.0;
    for (auto &it : points) {
        sumx += it.x;
        sumy += it.y;
    }
    return Point<double>(sumx / 3., sumy / 3);
}

void STriangle::move(Point<double> translation) {
    for (auto &it : points) {
        it.operator=(Point<double>(it.x + translation.x, it.y + translation.y));
    }
    center.operator=(this->center_point());
}

void STriangle::rotate(double angular) {
    for (auto &it : points) {
        it.operator=(Point<double>((it.x - center.x) * cos(angular) - (it.y - center.y) * sin(angular) + center.x,
                                   (it.y - center.y) * cos(angular) + (it.x - center.y) * sin(angular) + center.y));
    }
    center.operator=(this->center_point());
}

void STriangle::flip() {
    for (auto &it : points) {
        it.operator=(Point<double>(it.y, it.x));
    }
    center.operator=(this->center_point());
}

void STriangle::draw() {
    std::vector<Point<double>> list_points = this->getPoints();
    int * x_points = new int[list_points.size()];
    int * y_points = new int[list_points.size()];
    int i = 0;
    for(auto & it: list_points){
        x_points[i] = static_cast<int>(it.x);
        y_points[i] = static_cast<int>(it.y);
        i++;
    }

    MLV_draw_filled_polygon(x_points, y_points, static_cast<int>(list_points.size()),MLV_COLOR_GREEN);
}

std::vector<Point<double>> STriangle::getPoints() {
    std::vector<Point<double>> const points = {this->points};
    return points;
}

std::string STriangle::toString() {
    std::string points;
    for (auto[it, i] = std::tuple{this->points.begin(), 1}; it != this->points.end(); i++, it++) {
        points += std::string("Point ") + std::to_string(i) + std::string(" (x : ") + std::to_string(it->x) +
                  std::string(" y : ") + std::to_string(it->y) + std::string(")\n");
    }
    points += std::string("Center\nx : ") + std::to_string(center.x) + std::string(" y : ") +
              std::to_string(center.y) + std::string("\n");
    return points;
}

double STriangle::computeDistance(Point<double> point1, Point<double> point2) {
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}




