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

C_Objective::~C_Objective(){
    mShapes.clear(); //delete all elements in vector mTriangles (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with mTriangles. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<std::shared_ptr<A_Shape>>().swap(mShapes);
}

C_Objective::C_Objective(const MLV_Color _color){
    this->mColor = _color;
    (this->mShapes).push_back(std::shared_ptr<A_Shape>(std::make_shared<C_STriangle>(T_Point<double>(250.0, 350.0), 0.0, _color)));
    (this->mShapes).push_back(std::shared_ptr<A_Shape>(std::make_shared<C_Parallelogram>(T_Point<double>(350.0, 350.0), 0.0, _color)));
    (this->mShapes).push_back(std::shared_ptr<A_Shape>(std::make_shared<C_GTriangle>(T_Point<double>(50.0, 50.0), 0.0, _color)));
    (this->mShapes).push_back(std::shared_ptr<A_Shape>(std::make_shared<C_MTriangle>(T_Point<double>(100.0, 50.0), 0.0, _color)));
    (this->mShapes).push_back(std::shared_ptr<A_Shape>(std::make_shared<C_Square>(T_Point<double>(100.0, 50.0), 0.0, _color)));
}

C_Objective::C_Objective(const std::vector<std::shared_ptr<A_Shape>> &objective, const MLV_Color _color){
    this->mColor = _color;
    this->mShapes.insert(this->mShapes.end(), objective.begin(), objective.end());

}

bool C_Objective::BoardCompleted(const std::vector<std::shared_ptr<A_Shape>> &objective, const std::vector<std::shared_ptr<A_Shape>> &game) {
    std::vector<T_Point<int>> points_objective;
    std::vector<T_Point<int>> points_game;

    auto map_objective = std::unordered_map<T_Point<int>, int,  T_Point<int>::hash_point, std::equal_to<>>();
    auto map_game = std::unordered_map<T_Point<int>, int,  T_Point<int>::hash_point, std::equal_to<>>();
    int size = 0;
    for (auto &it : objective){
        const auto points = it->aGetPoints();
        for (auto &it2 : points){
            T_Point<int> p = {static_cast<int>(it2.x), static_cast<int>(it2.y)};
            if (map_objective.count(p) > 0){
                map_objective[p] += 1;
                size++;
            }
            else {
                map_objective[p] = 1;
                size++;
            }
        }
    }

    for (auto &it : game){
        const auto points = it->aGetPoints();
        for (auto &it2 : points){
            const T_Point<int> p(static_cast<int>(it2.x), static_cast<int>(it2.y));
            if (map_objective.count(p) > 0){
                map_objective[p] += 1;
                size++;
            }
            else {
                map_objective[p] = 1;
                size++;
            }
        }
    }
    for (auto & it : map_objective){
        if (map_game.count((it.first)) > 0){
            if (map_game[it.first] == map_objective[it.first]){
                map_game.erase(it.first);
                map_objective.erase(it.first);
                std::cout << "lol" << std::endl;
            }
            else if (map_game[it.first] < map_objective[it.first]){
                map_objective[it.first] -= map_game.at(it.first);
                map_game.erase(it.first);
                std::cout << "lol" << std::endl;
            }
            else {
                map_game[it.first] -= map_objective.at(it.first);
                map_objective.erase(it.first);
                std::cout << "lol" << std::endl;
            }
        }
    }
    int i = 0;
    for (auto & it: map_objective){
        if (map_objective[it.first] != 0)
            i+= map_objective[it.first];
    }
    for (auto & it: map_game){
        if (map_game[it.first] != 0)
        i+= map_game[it.first];
    }




  /*  for (auto &it : objective){
        for (auto &it2 : it->aGetPoints()){
            points_objective.emplace_back(static_cast<int>(it2.x), static_cast<int>(it2.y));
            std::cout << static_cast<int>(it2.x) << " " <<  static_cast<int>(it2.y) << std::endl;
        }
    }
    std::cout << "---" << std::endl;
    for (auto &it : game){
        for (auto &it2 : it->aGetPoints()){
            points_game.emplace_back(static_cast<int>(it2.x), static_cast<int>(it2.y));
            std::cout << static_cast<int>(it2.x) << " " <<  static_cast<int>(it2.y) << std::endl;
        }
    }


*/
    std::cout << i << " " << size << " " << i / size << std::endl;

    return (static_cast<double>(i / size) <= 0.1);

    return std::is_permutation( points_objective.begin(), points_objective.end(), points_game.begin(), points_game.end());
}

std::vector<std::shared_ptr<A_Shape>> C_Objective::GetObjective(){
    std::vector<std::shared_ptr<A_Shape>> const vec_shape = mShapes;
    return mShapes;
}

MLV_Color C_Objective::GetColor(){
    MLV_Color const _color = this->mColor;
    return _color;
}

void C_Objective::SetObjective(std::shared_ptr<C_Objective> objective, const std::vector<std::shared_ptr<A_Shape>> &vec_objective) {
    objective = std::make_shared<C_Objective>(vec_objective);
}
