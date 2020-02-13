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
#include <memory>

Objective::~Objective(){
    shapes.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<std::shared_ptr<Shape>>().swap(shapes);
}

Objective::Objective(const MLV_Color _color){
    this->color = _color;
    (this->shapes).push_back(std::shared_ptr<Shape>(std::make_shared<STriangle>(Point<double>(250.0, 350.0), 0.0, _color)));
    (this->shapes).push_back(std::shared_ptr<Shape>(std::make_shared<Parallelogram>(Point<double>(350.0, 350.0), 0.0, _color)));
    (this->shapes).push_back(std::shared_ptr<Shape>(std::make_shared<GTriangle>(Point<double>(50.0, 50.0), 0.0, _color)));
    (this->shapes).push_back(std::shared_ptr<Shape>(std::make_shared<MTriangle>(Point<double>(100.0, 50.0), 0.0, _color)));
    (this->shapes).push_back(std::shared_ptr<Shape>(std::make_shared<Square>(Point<double>(100.0, 50.0), 0.0, _color)));
}

Objective::Objective(const std::vector<std::shared_ptr<Shape>> &objective, const MLV_Color _color){
    this->color = _color;
    this->shapes.insert(this->shapes.end(), objective.begin(), objective.end());

}

bool Objective::boardCompleted(const std::vector<std::shared_ptr<Shape>> &objective, const std::vector<std::shared_ptr<Shape>> &game) {
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

std::vector<std::shared_ptr<Shape>> Objective::get_Objective(){
    std::vector<std::shared_ptr<Shape>> const vec_shape = shapes;
    return shapes;
}

MLV_Color Objective::get_Color(){
    MLV_Color const _color = this->color;
    return _color;
}

void Objective::set_Objective(std::shared_ptr<Objective> objective, const std::vector<std::shared_ptr<Shape>> &vec_objective) {
    objective = std::make_shared<Objective>(vec_objective);
}
