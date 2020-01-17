//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <cmath>
#include <shape/Square.hpp>

using namespace std;

int main (int argc, char *argv[]) {
    Square square(std::pair(1,2),std::pair(2,1));
    std::cout << square.toString() << std::endl;
    square.rotate(M_PI/4);
    std::cout << square.toString() << std::endl;
    square.flip();
    std::cout << square.toString() << std::endl;
    std::cout << "end of the game" << std::endl;
    std::exit(EXIT_SUCCESS);
}
