//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MTRIANGLE_H
#define TANGRAM_MTRIANGLE_H


class MTriangle {
private:
    std::pair<int,int> p1;
    std::pair<int,int> p2;
    std::pair<int,int> p3;

public:
    ~MTriangle();
    MTriangle(std::pair<int,int>, std::pair<int,int>, std::pair<int,int>);

};


#endif //TANGRAM_MTRIANGLE_H
