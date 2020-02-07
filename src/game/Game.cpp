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
#include <unordered_map>
#include <unordered_set>

static int abso(int x) {
    return x < 0 ? -x : x;
}

Game::Game(const int _w, const int _h) {
    this->w = _w;
    this->h = _h;

    //ajouter toutes les formes
    (this->shapes).push_back(new STriangle({50.0, 50.0}, 0.0));
    (this->shapes).push_back(new Parallelogram({50.0, 50.0}, 0.0));
  /*  (this->shapes).push_back(new GTriangle({50.0, 50.0}, 0.0));
    (this->shapes).push_back(new MTriangle({50.0, 50.0}, 0.0));
    (this->shapes).push_back(new Square({50.0, 50.0}, 0.0));*/

    for (auto &any_shape : objective.get_Objective()) {
        this->objective_shape.push_back(any_shape);
    }

    for (auto &any_shape : this->objective_shape) {
        for (auto &point : any_shape->get_Points()) {
            this->set_objective.insert(point);
        }
    }

}

void Game::draw() {
    MLV_clear_window(MLV_COLOR_BLACK);

    for (auto &shape : objective_shape) {
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

        if (Objective::boardCompleted(objective_shape, shapes)) {
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

void Game::set_Objective(const std::vector<Shape*> &vec_objective){
    objective_shape.clear();
    set_objective.clear();
    Objective::set_Objective(&objective, vec_objective);

    objective_shape.insert(objective_shape.end(), vec_objective.begin(), vec_objective.end());

    for (auto &any_shape : this->objective_shape) {
        for (auto &point : any_shape->get_Points()) {
            this->set_objective.insert(point);
        }
    }
}

MLV_Color Game::get_Objective_Color(){
    return objective.get_Color();
}

void Game::clear() {
    shapes.clear();
    objective_shape.clear();
    set_objective.clear();
}

/*struct hash_pair {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};*/

void Game::stick(Shape *shape) {
    auto set_shape = new std::unordered_set<Point<double>, Point<double>::hash_point, std::equal_to<>>();
    std::unordered_map<Point<double>, std::pair<Point<double>, double>, Point<double>::hash_point, std::equal_to<>> map_distance;

    for (auto &it: shape->get_Points()) {
        set_shape->insert(it);
    }

    for (auto &p_game : *set_shape) {
        for (auto &p_objective : set_objective) {
            double distance = Shape::computeDistance(p_game, p_objective);
            if (12.0 > distance) {
                if (map_distance.count(p_objective) > 0) {
                    if (map_distance.at(p_objective).second > distance) {
                        map_distance[p_objective] = std::make_pair(p_game, distance);
                    }
                } else {
                    map_distance[p_objective] = std::make_pair(p_game, distance);
                }
            }
        }
    }

    if (map_distance.size() >= set_shape->size()) {
        for (auto &p_min : map_distance) {
            shape->set_Points(p_min.second.first, p_min.first);
            shape->move(Point<double>(0.0,0.0));
        }
    }
}
