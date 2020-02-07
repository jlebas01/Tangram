//
// Created by jlebas01 on 15/01/2020.
//

#include <game/Objective.hpp>
#include <shape/STriangle.hpp>
#include <shape/MTriangle.hpp>
#include <shape/GTriangle.hpp>
#include <shape/Parallelogram.hpp>
#include <shape/Square.hpp>
#include <algorithm>
#include <iostream>

Objective::Objective(MLV_Color _color){
    this->color = _color;
    (this->shapes).push_back(new STriangle({250.0, 350.0}, 0.0, _color));
    (this->shapes).push_back(new Parallelogram({350.0, 350.0}, 0.0, _color));
 /*   (this->shapes).push_back(new GTriangle({50.0, 50.0}, 0.0, _color));
    (this->shapes).push_back(new MTriangle({100.0, 50.0}, 0.0, _color));
    (this->shapes).push_back(new Square({100.0, 50.0}, 0.0, _color));*/
}

Objective::Objective(std::vector<Shape*> objective, MLV_Color _color){
    this->color = _color;
    this->shapes.insert(this->shapes.end(), objective.begin(), objective.end());

}

bool Objective::boardCompleted(const std::vector<Shape*> &objective, const std::vector<Shape*> &game) {
    std::vector<Point<double>> points_objective;
    std::vector<Point<double>> points_game;

    for (auto &it : objective){
        for (auto &it2 : it->get_Points()){
            points_objective.push_back(it2);
            std::cout << "x : " << it2.x << " y : "<< it2.y << std::endl;
        }
    }

    std::cout << "-------------" << std::endl;

    for (auto &it : game){
        for (auto &it2 : it->get_Points()){
            points_game.push_back(it2);
            std::cout << "x : " << it2.x << " y : "<< it2.y << std::endl;
        }
    }
    std::cout << "_-_-_-_-_-" << std::endl;

    return std::is_permutation( points_objective.begin(), points_objective.end(), points_game.begin(), points_game.end());
}

std::vector<Shape *> Objective::get_Objective(){
    std::vector<Shape *> const vec_shape = shapes;
    return shapes;
}

MLV_Color Objective::get_Color(){
    MLV_Color const _color = this->color;
    return _color;
}

void Objective::set_Objective(Objective *objective, const std::vector<Shape *> &vec_objective) {
    objective = new Objective(vec_objective);
}
