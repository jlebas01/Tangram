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

Objective::Objective(){
    (this->shapes).push_back(new Parallelogram({50.0, 50.0}, 0.0, MLV_COLOR_GRAY70));
    (this->shapes).push_back(new STriangle({50.0, 50.0}, 0.0, MLV_COLOR_GRAY70));
    (this->shapes).push_back(new GTriangle({50.0, 50.0}, 0.0, MLV_COLOR_GRAY70));
    (this->shapes).push_back(new MTriangle({100.0, 50.0}, 0.0, MLV_COLOR_GRAY70));
    (this->shapes).push_back(new Square({100.0, 50.0}, 0.0, MLV_COLOR_GRAY70));
}

bool Objective::boardCompleted(const std::vector<Shape*> &objective, const std::vector<Shape*> &game) {
    std::vector<Point<double>> points_objective;
    std::vector<Point<double>> points_game;

    for (auto &it : objective){
        for (auto &it2 : it->get_Points()){
            points_objective.push_back(it2);
        }
    }

    for (auto &it : game){
        for (auto &it2 : it->get_Points()){
            points_game.push_back(it2);
        }
    }

    return std::is_permutation( points_objective.begin(), points_objective.end(), points_game.begin(), points_game.end());
}

std::vector<Shape *> Objective::get_Objective(){
    std::vector<Shape *> const vec_shape = shapes;
    return shapes;
}
