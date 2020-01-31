//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include <game/Objective.hpp>
#include <algorithm>

bool Objective::boardCompleted( std::vector<Shape> objective, std::vector<Shape> game) {
    std::vector<Point<double>> points_objective;
    std::vector<Point<double>> points_game;
    for (auto &it : objective){
        points_objective.insert(points_objective.end(), it.getPoints().begin(), it.getPoints().end());
    }
    for (auto &it : objective){
        points_game.insert(points_game.end(), it.getPoints().begin(), it.getPoints().end());
    }
    return std::is_permutation( points_objective.begin(), points_objective.end(), points_game.begin(), points_game.end());
}
