//
// Created by jlebas01 on 15/01/2020.
//

#include <game/C_Objective.hpp>
#include <shape/C_STriangle.hpp>
#include <shape/C_MTriangle.hpp>
#include <shape/C_GTriangle.hpp>
#include <shape/C_Parallelogram.hpp>
#include <shape/C_Square.hpp>
#include <algorithm>
#include <iostream>
#include <memory>
#include <bits/unordered_set.h>

C_Objective::~C_Objective() {
    mShapes.clear(); //delete all elements in vector mTriangles (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with mTriangles. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<std::shared_ptr<A_Shape>>().swap(mShapes);
}

C_Objective::C_Objective(const MLV_Color _color) {
    this->mColor = _color;
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(std::make_shared<C_STriangle>(T_Point<double>(250.0, 350.0), 0.0, _color)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(std::make_shared<C_Parallelogram>(T_Point<double>(350.0, 350.0), 0.0, _color)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(std::make_shared<C_GTriangle>(T_Point<double>(50.0, 50.0), 0.0, _color)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(std::make_shared<C_MTriangle>(T_Point<double>(100.0, 50.0), 0.0, _color)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(std::make_shared<C_Square>(T_Point<double>(100.0, 50.0), 0.0, _color)));
}

C_Objective::C_Objective(const std::vector<std::shared_ptr<A_Shape>> &objective, const MLV_Color _color) {
    this->mColor = _color;
    this->mShapes.insert(this->mShapes.end(), objective.begin(), objective.end());

}

/*bool C_Objective::BoardCompleted(const std::vector<std::shared_ptr<A_Shape>> &objective,
                                 const std::vector<std::shared_ptr<A_Shape>> &game) {

    auto set_game = new std::unordered_set<T_Point<int>, T_Point<int>::hash_point, std::equal_to<>>();
    auto set_objective = new std::unordered_set<T_Point<int>, T_Point<int>::hash_point, std::equal_to<>>();

    for (auto &it : objective) {
        for (auto &it2 : it->aGetPoints()) {
            set_objective->insert({static_cast<int>(it2.x), static_cast<int>(it2.y)});
        }
    }

    for (auto &it : game) {
        for (auto &it2 : it->aGetPoints()) {
            set_game->insert({static_cast<int>(it2.x), static_cast<int>(it2.y)});
        }
    }
    auto points_match = static_cast<double>(set_objective->size());

    double error_marge = 0.10 + (0.07) * (set_objective->size() / 60.0);

    for (auto &it : *set_objective) {
        points_match -= std::count(set_game->begin(), set_game->end(), it);
    }

    return points_match / static_cast<double>(set_objective->size()) <= 0.01;
    //return points_match < static_cast<double>(set_objective->size());
}*/

bool C_Objective::BoardCompleted(const std::vector<std::shared_ptr<A_Shape>> &objective,
                                 const std::vector<std::shared_ptr<A_Shape>> &game) {

    auto set_game = new std::unordered_set<T_Point<int>, T_Point<int>::hash_point, std::equal_to<>>();
    auto set_objective = new std::unordered_set<T_Point<int>, T_Point<int>::hash_point, std::equal_to<>>();

    for (auto &it : objective) {
        for (auto &it2 : it->aGetPoints()) {
            set_objective->insert({static_cast<int>(it2.x), static_cast<int>(it2.y)});
        }
    }

    for (auto &it : game) {
        for (auto &it2 : it->aGetPoints()) {
            set_game->insert({static_cast<int>(it2.x), static_cast<int>(it2.y)});
        }
    }


    for (auto &it : *set_game){
        if (std::count(set_objective->begin(), set_objective->end(), it) == 0 ){
            return false;
        }
    }

    delete set_game;
    delete set_objective;

    return true;
}

std::vector<std::shared_ptr<A_Shape>> C_Objective::GetObjective() {
    std::vector<std::shared_ptr<A_Shape>> const vec_shape = mShapes;
    return mShapes;
}

MLV_Color C_Objective::GetColor() {
    MLV_Color const _color = this->mColor;
    return _color;
}

double C_Objective::GetCompleted(const std::vector<std::shared_ptr<A_Shape>> &objective,
                                 const std::vector<std::shared_ptr<A_Shape>> &game) {

    auto set_game = new std::unordered_set<T_Point<int>, T_Point<int>::hash_point, std::equal_to<>>();
    auto set_objective = new std::unordered_set<T_Point<int>, T_Point<int>::hash_point, std::equal_to<>>();

    for (auto &it : objective) {
        for (auto &it2 : it->aGetPoints()) {
            set_objective->insert({static_cast<int>(it2.x), static_cast<int>(it2.y)});
        }
    }

    for (auto &it : game) {
        for (auto &it2 : it->aGetPoints()) {
            set_game->insert({static_cast<int>(it2.x), static_cast<int>(it2.y)});
        }
    }
    auto points_match = static_cast<double>(set_objective->size());

   // double error_marge = 0.10 + (0.05) * (set_objective->size() / 60.0);

    for (auto &it : *set_objective) {
        points_match -= std::count(set_game->begin(), set_game->end(), it);
    }

    delete set_game;
    delete set_objective;

    return (1- (points_match / static_cast<double>(set_objective->size())))*100;
}

void C_Objective::SetObjective(std::shared_ptr<C_Objective> objective,
                               const std::vector<std::shared_ptr<A_Shape>> &vec_objective) {
    objective = std::make_shared<C_Objective>(vec_objective);
}
