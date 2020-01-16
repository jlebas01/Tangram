//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_STRIANGLE_H
#define TANGRAM_STRIANGLE_H


class STriangle {
private:
    std::pair<int,int> p1;
    std::pair<int,int> p2;
    std::pair<int,int> p3;

public:
    ~STriangle();
    STriangle(std::pair<int,int>, std::pair<int,int>, std::pair<int,int>);

};


#endif //TANGRAM_STRIANGLE_H
