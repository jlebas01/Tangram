//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include "../include/Square.h"

using namespace std;

void Square::init(pair <int,int> point1, pair <int,int> point2, pair <int,int> point3, pair <int,int> point4){
    this->p1 = make_pair(point1.first, point1.second);
    this->p2 = make_pair(point2.first, point2.second);
    this->p3 = make_pair(point3.first, point3.second);
    this->p4 = make_pair(point4.first, point4.second);

}

