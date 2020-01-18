//
// Created by jlebas01 on 15/01/2020.
//

#include <utility>
#include <cmath>
#include <tuple>

#include <shape/STriangle.hpp>


STriangle::~STriangle(){
    point.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<std::pair<double, double >>().swap(point);
}

STriangle::STriangle(const std::pair<double,double> point1, const std::pair<double,double> point2, const std::pair<double,double> point3){
    this->point.emplace_back(std::make_pair(point1.first, point1.second));
    this->point.emplace_back(std::make_pair(point2.first, point2.second));
    this->point.emplace_back(std::make_pair(point3.first, point3.second));
    this->center.operator=(this->center_point());
}

STriangle::STriangle(const std::vector<std::pair<double,double>>& points){
    for (auto & it : points){
        this->point.push_back(it);
    }
    this->center.operator=(this->center_point());
}

STriangle::STriangle(){
    this->point.emplace_back( std::make_pair(0.0, 0.0));
    this->point.emplace_back( std::make_pair(2.0,0.0));
    this->point.emplace_back( std::make_pair(0.0, 2.0));
    this->center.operator=(this->center_point());
}

std::pair<double,double> STriangle::center_point(){
    double sumx = 0.0, sumy = 0.0;
    for (auto & it : point){
        sumx += it.first;
        sumy += it.second;
    }
    return std::make_pair(sumx/3, sumy/3);
}
void STriangle::move(std::pair<double,double> translation) {
    for (auto & it : point){
        it.operator=(std::pair<double,double>(it.first + translation.first, it.second + translation.second));
    }
    center.operator=(this->center_point());
}

void STriangle::rotate(double angular) {
    for(auto & it : point){
        it.operator=( std::pair<double,double>((it.first-center.first) * cos(angular) - (it.second-center.second) * sin(angular) +center.first,(it.second-center.second) * cos(angular) + (it.first-center.second) * sin(angular) +center.second));
    }
    center.operator=(this->center_point());
}

void STriangle::flip() {
    for(auto & it : point){
        it.operator=( std::pair<double,double>(it.second,it.first));
    }
    center.operator=(this->center_point());
}

std::vector<std::pair<double, double>> STriangle::getPoints() {
    std::vector<std::pair<double,double>> const points = { point };
    return points;
}

std::string STriangle::toString(){
    std::string points;
    for (auto[it, i] = std::tuple{point.begin(), 1}; it != point.end(); i++, it++) {
        points+= std::string("Point ") + std::to_string(i) + std::string("\nx : ") + std::to_string(it->first) + std::string(" y : ") + std::to_string(it->second) + std::string("\n");
    }
    points += std::string("Center\nx : ") + std::to_string(center.first) + std::string(" y : ") + std::to_string(center.second) + std::string("\n");
    return points;
}


