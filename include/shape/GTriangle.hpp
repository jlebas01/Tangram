//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GTRIANGLE_H
#define TANGRAM_GTRIANGLE_H

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>

class GTriangle : public Shape {
private:

    std::vector<STriangle> triangle;

public:
    ~GTriangle() override;

    explicit GTriangle(const std::vector<STriangle> &triangle);

    GTriangle();

    void move(std::pair<double, double>) override;

    void rotate(double angular) override;

    void flip() override;

    std::vector<std::pair<double, double>> getPoints() override;

    std::string toString() override;

};

#endif //TANGRAM_GTRIANGLE_H
