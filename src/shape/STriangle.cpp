//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <utility>
#include <cmath>

#include <shape/STriangle.hpp>

STriangle::~STriangle()= default;

STriangle::STriangle(const std::pair<double,double> point1, const std::pair<double,double> point2, const std::pair<double,double> point3){
    this->p1 = std::make_pair(point1.first, point1.second);
    this->p2 = std::make_pair(point2.first, point2.second);
    this->p3 = std::make_pair(point3.first, point3.second);
    this->center.operator=(this->center_point());
}

STriangle::STriangle(){
    this->p1 = std::make_pair( 0.0, 0.0);
    this->p2 = std::make_pair( 2.0, 0.0);
    this->p3 = std::make_pair( 0.0, 2.0);
    this->center.operator=(this->center_point());
}

std::pair<double,double> STriangle::center_point(){
    return std::make_pair((p1.first+p2.first+p3.first)/3, (p1.second+p2.second+p3.second)/3);
}
void STriangle::move(std::pair<double,double> translation) {
    p1.operator=(std::pair<double,double>(p1.first+translation.first,p1.second+translation.second));
    p2.operator=(std::pair<double,double>(p2.first+translation.first,p2.second+translation.second));
    p3.operator=(std::pair<double,double>(p3.first+translation.first,p3.second+translation.second));
    center.operator=(this->center_point());
}

void STriangle::rotate(double angular) {
    p1.operator=(std::pair<double,double>((p1.first-center.first) * cos(angular) - (p1.second-center.second) * sin(angular) +center.first,(p1.second-center.second) * cos(angular) + (p1.first-center.second) * sin(angular) +center.second));
    p2.operator=(std::pair<double,double>((p2.first-center.first) * cos(angular) - (p2.second-center.second) * sin(angular) +center.first,(p2.second-center.second) * cos(angular) + (p2.first-center.second) * sin(angular) +center.second));
    p3.operator=(std::pair<double,double>((p3.first-center.first) * cos(angular) - (p3.second-center.second) * sin(angular) +center.first,(p3.second-center.second) * cos(angular) + (p3.first-center.second) * sin(angular) +center.second));
    center.operator=(this->center_point());
}

void STriangle::flip() {
    p1.operator=(std::pair<double,double>(p1.second,p1.first));
    p2.operator=(std::pair<double,double>(p2.second,p2.first));
    p3.operator=(std::pair<double,double>(p3.second,p3.first));
    center.operator=(this->center_point());

}



std::vector<std::pair<double, double>> STriangle::getPoints() {
    std::vector<std::pair<double, double>> points = {p1,p2,p3};
    return points;
}

std::string STriangle::toString(){
    std::string point1 = std::string("Point 1\nx : ") + std::to_string(p1.first) + std::string(" y : ") + std::to_string(p1.second) + std::string("\n");
    std::string point2 = std::string("Point 2\nx : ") + std::to_string(p2.first) + std::string(" y : ") + std::to_string(p2.second) + std::string("\n");
    std::string point3 = std::string("Point 3\nx : ") + std::to_string(p3.first) + std::string(" y : ") + std::to_string(p3.second) + std::string("\n");
    std::string centerPoint = std::string("Center\nx : ") + std::to_string(center.first) + std::string(" y : ") + std::to_string(center.second) + std::string("\n");
    return point1 + point2 + point3 + centerPoint;
}


