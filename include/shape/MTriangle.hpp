//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MTRIANGLE_H
#define TANGRAM_MTRIANGLE_H

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>

class MTriangle : public Shape {
private:

    std::vector<STriangle> triangle;

public:
    ~MTriangle() override;

    explicit MTriangle(const std::vector<STriangle> &triangle);

    MTriangle();

    void move(std::pair<double, double>) override;

    void rotate(double angular) override;

    void flip() override;

    std::vector<std::pair<double, double>> getPoints() override;

    std::string toString() override;

};

#endif //TANGRAM_MTRIANGLE_H
