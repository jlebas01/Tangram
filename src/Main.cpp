//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <cmath>
#include <shape/STriangle.hpp>
#include <shape/Square.hpp>
#include <shape/GTriangle.hpp>
#include <drawable/Shape.hpp>
#include <shape/Parallelogram.hpp>


int main(int argc, char *argv[]) {


    Parallelogram triangle;
    Shape &piece = triangle;
    std::cout << "square : \n" << std::endl;
    Square square;

    std::cout << piece.toString() << std::endl;
    triangle.rotate(2 * M_PI);
    std::cout << "\n----------------------\n" << std::endl;
    std::cout << triangle.toString() << std::endl;

    std::exit(EXIT_SUCCESS);
}
