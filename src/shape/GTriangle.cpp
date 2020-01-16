//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <utility>
#include <cmath>

#include <shape/GTriangle.hpp>


GTriangle::~GTriangle()= default;

GTriangle::GTriangle(const std::pair<double,double> point1, const std::pair<double,double> point2, const std::pair<double,double> point3){
    this->p1 = std::make_pair(point1.first, point1.second);
    this->p2 = std::make_pair(point2.first, point2.second);
    this->p3 = std::make_pair(point3.first, point3.second);
}

void GTriangle::move(std::pair<double,double> translation) {
    p1.operator=(std::pair<double,double>(p1.first+translation.first,p1.second+translation.second));
    p2.operator=(std::pair<double,double>(p2.first+translation.first,p2.second+translation.second));
    p3.operator=(std::pair<double,double>(p3.first+translation.first,p3.second+translation.second));
}

void GTriangle::rotate(double angular) {
    p1.operator=(std::pair<double,double>(p1.first * cos(angular) - p1.second * sin(angular),p1.second * cos(angular) + p1.first * sin(angular)));
    p2.operator=(std::pair<double,double>(p2.first * cos(angular) - p2.second * sin(angular),p2.second * cos(angular) + p2.first * sin(angular)));
    p3.operator=(std::pair<double,double>(p3.first * cos(angular) - p3.second * sin(angular),p3.second * cos(angular) + p3.first * sin(angular)));
}

void GTriangle::flip() {
    p1.operator=(std::pair<double,double>(p1.second,p1.first));
    p2.operator=(std::pair<double,double>(p2.second,p2.first));
    p3.operator=(std::pair<double,double>(p3.second,p3.first));

}

double GTriangle::getPerimeter() {
    return computeDistance(p1,p2) + computeDistance(p2,p3) + computeDistance(p3,p1);
}

std::vector<std::pair<double, double>> GTriangle::getPoints() {
    std::vector<std::pair<double, double>> points = {p1,p2,p3};
    return points;
}



