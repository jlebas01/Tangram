//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <utils/Point.hpp>
#include <game/Game.hpp>
#include <game/Objective.hpp>
#include <shape/STriangle.hpp>
#include <shape/MTriangle.hpp>
#include <shape/GTriangle.hpp>
#include <shape/Parallelogram.hpp>
#include <shape/Square.hpp>
#include <MLV/MLV_all.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

static int abso(int x) {
    return x < 0 ? -x : x;
}

Game::Game(const int _w, const int _h) {
    this->w = _w;
    this->h = _h;

    //ajouter toutes les formes
    (this->shapes).push_back(new STriangle({50.0, 50.0}, 0.0));
    (this->shapes).push_back(new Parallelogram({50.0, 50.0}, 0.0));
    //(this->shapes).push_back(new GTriangle({50.0, 50.0}, 0.0));
    //(this->shapes).push_back(new MTriangle({50.0, 50.0}, 0.0));
    //(this->shapes).push_back(new Square({50.0, 50.0}, 0.0));*/

}

void Game::draw() {
    std::vector<Shape *> const vec_objective = objective.get_Objective();
    MLV_clear_window(MLV_COLOR_BLACK);

    for (auto &shape : vec_objective) {
        shape->draw();
    }

    for (auto &shape : shapes) {
        shape->draw();
    }

    MLV_actualise_window();
}

void Game::main_loop() {
    bool exit = false;
    Shape *selected = nullptr;
    Point<int> cur_click;
    Point<int> prev_click;

    MLV_Button_state cur_state;
    MLV_Button_state prev_state;

    MLV_Mouse_button cur_mouse_button;
    MLV_Mouse_button prev_mouse_button;

    MLV_Keyboard_modifier cur_modifier;
    MLV_Keyboard_modifier prev_modifier;

    MLV_Keyboard_button cur_button;
    MLV_Keyboard_button prev_button;

    MLV_wait_event(&cur_button, &cur_modifier, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
                   &cur_mouse_button, &cur_state);

    while (!exit) {
        prev_click = cur_click;
        prev_state = cur_state;
        prev_mouse_button = cur_mouse_button;
        prev_modifier = cur_modifier;
        prev_button = cur_button;

        MLV_wait_event(&cur_button, &cur_modifier, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
                       &cur_mouse_button, &cur_state);


        draw();

        if (Objective::boardCompleted(objective.get_Objective(), shapes)) {
            exit = true;
            MLV_wait_seconds(3);
            continue;
        }

        if (prev_state != cur_state) {
            if (cur_state == MLV_PRESSED) {
                for (auto &shape: shapes) {
                    if (shape->is_in_shape({cur_click.x, cur_click.y})) {
                        selected = shape;
                    }
                }
            } else if (cur_state == MLV_RELEASED) {
                selected = nullptr;
            }
        } else {
            if (selected && prev_mouse_button == cur_mouse_button && cur_mouse_button == MLV_BUTTON_LEFT) {
                selected->move({cur_click.x - prev_click.x, cur_click.y - prev_click.y});
                stick(selected);
            }
            if (selected && prev_mouse_button == cur_mouse_button && cur_mouse_button == MLV_BUTTON_RIGHT) {
                int dx = cur_click.x - prev_click.x;
                int dy = cur_click.y - prev_click.y;
                if (abso(dx) > abso(dy)) {
                    selected->rotate(static_cast<double>(dx) / 250.);
                    stick(selected);
                } else {
                    selected->rotate(static_cast<double>(dy) / 250.);
                    stick(selected);
                }
            }
        }
    }
}


void Game::add_shape(Shape *s) {
    shapes.push_back(s);
}

void Game::clear() {
    shapes.clear();
}

/*void Game::stick(Shape *shape) {
    std::vector<Point<double>> const vec_game = shape->get_Points();
    std::vector<Point<double>> vec_objective;
    std::vector<Point<double>> selected;

    for (auto &it : objective.get_Objective()) {
        for (auto &it2 : it->get_Points()) {
            vec_objective.push_back(it2);
        }
    }

    for (auto &it : vec_game) {
        for (auto &it2 : vec_objective) {
            //std::cout << Shape::computeDistance(it, it2) << std::endl;
            if (12.0 > Shape::computeDistance(it, it2)) {
                selected.push_back(it2);
            }
        }
    }

    std::sort( selected.begin(), selected.end() );
    selected.erase( std::unique( selected.begin(), selected.end() ), selected.end() );

    if (selected.size() >= vec_game.size()) {
        for (auto &it3 : vec_game) {
            Point<double> min = selected.at(0);
            double distance = Shape::computeDistance(it3, selected.at(0));
            int count = 0;
            int pos = 0;

            for (auto &it4 : selected) {
                double temp = Shape::computeDistance(it3, it4);
                if (distance > temp) {
                    distance = temp;
                    min = it4;
                    pos = count;
                }
                count++;
            }
            if (shape->set_Points(it3, min)) {
                selected.erase(selected.begin() +pos);
            } else {
               // std::cout << "Error in set point" << std::endl;
            }
        }
    }
}*/


struct hash_pair {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};

void Game::stick(Shape *shape) {
    //std::vector<Point<double>> vec_objective;
   // std::set<Point<double>,  Point<double>::hash_point, std::equal_to< >> vec_objective;
    std::unordered_map<Point<double>, double, Point<double>::hash_point, std::equal_to<>> map_objective;
   // auto vec_objective = new std::set<Point<double>, Point<double>::hash_point>();
    std::unordered_map<Point<double>, double, Point<double>::hash_point, std::equal_to<>> map;
    std::unordered_map<Point<double>, std::pair<Point<double>, double>, Point<double>::hash_point, std::equal_to<>> map_distance;
   // auto map = new std::unordered_map<Point<double>, double, Point<double>::hash_point, std::equal_to<>>();

    for (auto &it: shape->get_Points()) {
        map.insert(std::make_pair(it, 0.0));
    }

    for (auto &it : objective.get_Objective()) {
        std::vector<Point<double>> const tmp = it->get_Points();
        for (auto &it2 : it->get_Points()){
            map_objective.insert(std::make_pair(it2,0.0));
        }

       // vec_objective.insert(vec_objective.end(),tmp.begin(), tmp.end());
    }

    for (auto &p_game : map) {
        for (auto &p_objective : map_objective) {
            double distance = Shape::computeDistance(p_game.first, p_objective.first);
            if (12.0 > distance) {
                if (map_distance.count(p_objective.first) > 0) {
                    if (map_distance.at(p_objective.first).second > distance) {
                        map_distance[p_objective.first] = std::make_pair(p_game.first, distance);
                    }
                } else {
                    map_distance[p_objective.first] = std::make_pair(p_game.first, distance);
                }
            }
        }
    }

    if (map_distance.size() >= map.size()) {
        for ( auto &p_min : map_distance) {
            shape->set_Points(p_min.second.first, p_min.first);
        }
    }

}
