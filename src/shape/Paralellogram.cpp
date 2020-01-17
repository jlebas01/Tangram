//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <utility>
#include <cmath>

#include <shape/Paralellogram.hpp>

Paralellogram::~Paralellogram()= default;

Paralellogram::Paralellogram(const std::pair <double,double> point1, const std::pair <double,double> point2, const std::pair <double,double> point3, const std::pair <double,double> point4){
    this->p1 = std::make_pair(point1.first, point1.second);
    this->p2 = std::make_pair(point2.first, point2.second);
    this->p3 = std::make_pair(point3.first, point3.second);
    this->p4 = std::make_pair(point4.first, point4.second);
}
void Paralellogram::move(std::pair<double,double> translation) {
    p1.operator=(std::pair<double,double>(p1.first+translation.first,p1.second+translation.second));
    p2.operator=(std::pair<double,double>(p2.first+translation.first,p2.second+translation.second));
    p3.operator=(std::pair<double,double>(p3.first+translation.first,p3.second+translation.second));
    p4.operator=(std::pair<double,double>(p4.first+translation.first,p4.second+translation.second));
}

void Paralellogram::rotate(double angular) {
    p1.operator=(std::pair<double,double>(p1.first * cos(angular) - p1.second * sin(angular),p1.second * cos(angular) + p1.first * sin(angular)));
    p2.operator=(std::pair<double,double>(p2.first * cos(angular) - p2.second * sin(angular),p2.second * cos(angular) + p2.first * sin(angular)));
    p3.operator=(std::pair<double,double>(p3.first * cos(angular) - p3.second * sin(angular),p3.second * cos(angular) + p3.first * sin(angular)));
    p4.operator=(std::pair<double,double>(p4.first * cos(angular) - p4.second * sin(angular),p4.second * cos(angular) + p4.first * sin(angular)));
}

void Paralellogram::flip() {
    p1.operator=(std::pair<double,double>(p1.second,p1.first));
    p2.operator=(std::pair<double,double>(p2.second,p2.first));
    p3.operator=(std::pair<double,double>(p3.second,p3.first));
    p4.operator=(std::pair<double,double>(p4.second,p4.first));

}

double Paralellogram::getPerimeter() {
    return computeDistance(p1,p2) + computeDistance(p2,p3) + computeDistance(p3,p4) + computeDistance(p4,p1);
}

std::vector<std::pair<double, double>> Paralellogram::getPoints() {
    std::vector<std::pair<double, double>> points = {p1,p2,p3,p4};
    return points;
}

std::string Paralellogram::toString(){
    std::string point1 = std::string("Point 1\nx : ") + std::to_string(p1.first) + std::string(" y : ") + std::to_string(p1.second) + std::string("\n");
    std::string point2 = std::string("Point 2\nx : ") + std::to_string(p2.first) + std::string(" y : ") + std::to_string(p2.second) + std::string("\n");
    std::string point3 = std::string("Point 3\nx : ") + std::to_string(p3.first) + std::string(" y : ") + std::to_string(p3.second) + std::string("\n");
    std::string point4 = std::string("Point 4\nx : ") + std::to_string(p4.first) + std::string(" y : ") + std::to_string(p4.second) + std::string("\n");
    return point1 + point2 + point3 + point4;
}
