//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <cmath>
#include <shape/STriangle.hpp>
#include <shape/Square.hpp>

using namespace std;

int main (int argc, char *argv[]) {
    STriangle triangle;
    Square square;
    std::cout << square.toString() << std::endl;
    square.rotate(2*M_PI);
    std::cout << "\n----------------------\n" << std::endl;
    std::cout << square.toString() << std::endl;

    std::exit(EXIT_SUCCESS);
}
