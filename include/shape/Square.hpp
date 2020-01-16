//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SQUARE_H
#define TANGRAM_SQUARE_H

#include <utility>

class Square {
private:

    std::pair <int,int> p1;
    std::pair <int,int> p2;
    std::pair <int,int> p3;
    std::pair <int,int> p4;

public:
    ~Square();
    Square(std::pair <int,int>,std::pair<int,int>,std::pair<int,int>,std::pair<int,int>);

};


#endif //TANGRAM_SQUARE_H
