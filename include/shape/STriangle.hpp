//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_STRIANGLE_H
#define TANGRAM_STRIANGLE_H

#include <vector>

#include <drawable/Shape.hpp>

class STriangle : public Shape {
private:

    std::vector<std::pair<double, double>> point;
    std::pair<double, double> center;

    std::pair<double, double> center_point();

public:
    ~STriangle() override;

    explicit STriangle(const std::vector<std::pair<double, double>> &points);

    STriangle();

    STriangle(std::pair<double, double>, std::pair<double, double>, std::pair<double, double>);

    void move(std::pair<double, double>) override;

    void rotate(double angular) override;

    void flip() override;

    std::vector<std::pair<double, double>> getPoints() override;

    std::string toString() override;

    double computeDistance(std::pair<double, double> point1, std::pair<double, double> point2);
};

#endif //TANGRAM_STRIANGLE_H
