//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <cmath>

#include <drawable/Piece.hpp>

Piece::~Piece()= default;

double Piece::computeDistance(std::pair<double, double> point1, std::pair<double, double> point2) {
    return sqrt(pow(point2.first - point1.first, 2) + pow(point2.second - point1.second, 2));
}
