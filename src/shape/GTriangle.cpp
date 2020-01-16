//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <utility>

#include <shape/GTriangle.hpp>

GTriangle::~GTriangle(){

}

GTriangle::GTriangle(const std::pair<int,int> point1, const std::pair<int,int> point2, const std::pair<int,int> point3){
    this->p1 = std::make_pair(point1.first, point1.second);
    this->p2 = std::make_pair(point2.first, point2.second);
    this->p3 = std::make_pair(point3.first, point3.second);
}
