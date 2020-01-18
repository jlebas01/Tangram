//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <utility>
#include <cmath>
#include <tuple>

#include <shape/Square.hpp>


Square::~Square()= default;

Square::Square(std::vector<STriangle> triangles){
    for(auto & it : triangles) {
        this->triangle.push_back(it);
    }
}

Square::Square() {
    this->triangle.emplace_back(STriangle(std::pair <double,double>(0.0,0.0), std::pair <double,double>(0.0,2.0), std::pair <double,double>(2.0,0.0)));
    this->triangle.emplace_back(STriangle(std::pair <double,double>(2.0,0.0), std::pair <double,double>(2.0,2.0), std::pair <double,double>(0.0,2.0)));
}


void Square::move(std::pair<double,double> translation) {
    for(auto & it : triangle) {
        it.move(translation);
    }
}

void Square::rotate(double angular) {
    for(auto & it : triangle) {
        it.rotate(angular);
    }
}

void Square::flip() {
    for(auto & it : triangle) {
        it.flip();
    }
}



std::vector<std::pair<double, double>> Square::getPoints() {
    std::vector<std::pair<double, double>> points;
    for(auto & it : triangle) {
        points.insert(points.end(), it.getPoints().begin(), it.getPoints().end()); //add all points of vector triangle n in vector points
    }
    return points;
}

std::string Square::toString(){

    std::string t = std::string("");

    for(auto [it,i] = std::tuple{triangle.begin(), 0} ; it != triangle.end() ; i++, it++){
        t+=std::string("Triangle ") + std::to_string(i) + std::string(" :\n")+it->toString();
    }
    return t;
}

