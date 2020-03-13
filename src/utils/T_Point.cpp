//
// Created by jlebas01 on 13/03/2020.
//

#include <utils/T_Point.hpp>


template<>
bool T_Point<double>::operator==(const T_Point<double> &p) const {
    double alpha = 5.0;
    return sqrt(pow(p.x - this->x, 2) + pow(p.y - this->y, 2)) < alpha;
}
