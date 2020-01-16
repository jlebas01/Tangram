//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GTRIANGLE_H
#define TANGRAM_GTRIANGLE_H


class GTriangle {
private:
    std::pair<int,int> p1;
    std::pair<int,int> p2;
    std::pair<int,int> p3;

public:
    ~GTriangle();
    GTriangle(std::pair<int,int>, std::pair<int,int>, std::pair<int,int>);

};


#endif //TANGRAM_GTRIANGLE_H
