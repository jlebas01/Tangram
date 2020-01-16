//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_PARALELLOGRAM_H
#define TANGRAM_PARALELLOGRAM_H


class Paralellogram {
private:

    std::pair <int,int> p1;
    std::pair <int,int> p2;
    std::pair <int,int> p3;
    std::pair <int,int> p4;

public:
    ~Paralellogram();
    Paralellogram(std::pair <int,int>, std::pair<int,int>, std::pair<int,int>, std::pair<int,int>);

};


#endif //TANGRAM_PARALELLOGRAM_H
