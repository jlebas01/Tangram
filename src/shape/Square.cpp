//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <utility>
#include <cmath>

#include <shape/Square.hpp>


Square::~Square()= default;

Square::Square(const std::pair <double,double> point1, const std::pair <double,double> point2){
    this->p1 = std::make_pair(point1.first, point1.second);
    this->p2 = std::make_pair(point2.first, point2.second);
}

void Square::move(std::pair<double,double> translation) {
    p1.operator=(std::pair<double,double>(p1.first+translation.first,p1.second+translation.second));
    p2.operator=(std::pair<double,double>(p2.first+translation.first,p2.second+translation.second));
}

void Square::rotate(double angular) {
    p1.operator=(std::pair<double,double>(p1.first * cos(angular) - p1.second * sin(angular),p1.second * cos(angular) + p1.first * sin(angular)));
    p2.operator=(std::pair<double,double>(p2.first * cos(angular) - p2.second * sin(angular),p2.second * cos(angular) + p2.first * sin(angular)));
}

void Square::flip() {
    p1.operator=(std::pair<double,double>(p1.second,p1.first));
    p2.operator=(std::pair<double,double>(p2.second,p2.first));

}

double Square::getPerimeter() {
    std::pair<double,double> p3, p4;
    p3 = std::make_pair(p1.first,p2.second);
    p4 = std::make_pair( p2.first, p1.second);
    return computeDistance(p1,p3) + computeDistance(p3,p2) + computeDistance(p2,p4) + computeDistance(p4,p1);
}

std::vector<std::pair<double, double>> Square::getPoints() {
    std::pair<double,double> p3, p4;
    p3 = std::make_pair(p1.first,p2.second);
    p4 = std::make_pair( p2.first, p1.second);
    std::vector<std::pair<double, double>> points = {p1,p3,p2,p4};
    return points;
}
