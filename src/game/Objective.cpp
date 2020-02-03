//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include <game/Objective.hpp>
#include <algorithm>

bool Objective::boardCompleted( std::vector<Shape*> objective, std::vector<Shape*> game) {
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
