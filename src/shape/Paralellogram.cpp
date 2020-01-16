//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <utility>

#include <shape/Paralellogram.hpp>

Paralellogram::~Paralellogram(){

}

Paralellogram::Paralellogram(const std::pair <int,int> point1, const std::pair <int,int> point2, const std::pair <int,int> point3, const std::pair <int,int> point4){
    this->p1 = std::make_pair(point1.first, point1.second);
    this->p2 = std::make_pair(point2.first, point2.second);
    this->p3 = std::make_pair(point3.first, point3.second);
    this->p4 = std::make_pair(point4.first, point4.second);

}
