//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_PARALELLOGRAM_H
#define TANGRAM_PARALELLOGRAM_H

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Piece.hpp>

class Parallelogram : Piece {
private:

    std::vector<STriangle> triangle;

public:
    ~Parallelogram() override;

    explicit Parallelogram(const std::vector<STriangle> &triangle);

    Parallelogram();

    void move(std::pair<double, double>) override;

    void rotate(double angular) override;

    void flip() override;

    std::vector<std::pair<double, double>> getPoints() override;

    std::string toString() override;

};

#endif //TANGRAM_PARALELLOGRAM_H
