//
// Created by jlebas01 on 15/01/2020.
//

#include <game/Game.hpp>


Game::~Game() {
    shapes.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<std::shared_ptr<Shape>>().swap(shapes);
    objective_shape.clear();
    std::vector<std::shared_ptr<Shape>>().swap(objective_shape);
    set_objective.clear();
    std::unordered_set<Point<double>, Point<double>::hash_point, std::equal_to<>>().swap(set_objective);
}

static int abso(int x) {
    return x < 0 ? -x : x;
}

Game::Game(const int _w, const int _h) {
    this->w = _w;
    this->h = _h;

    //ajouter toutes les formes
    (this->shapes).push_back(std::shared_ptr<Shape>(new STriangle({50.0, 50.0}, 0.0)));
    (this->shapes).push_back(std::shared_ptr<Shape>(new Parallelogram({50.0, 50.0}, 0.0)));
    (this->shapes).push_back(std::shared_ptr<Shape>(new GTriangle({50.0, 50.0}, 0.0)));
    (this->shapes).push_back(std::shared_ptr<Shape>(new MTriangle({50.0, 50.0}, 0.0)));
    (this->shapes).push_back(std::shared_ptr<Shape>(new Square({50.0, 50.0}, 0.0)));

    for (auto &any_shape : objective.get_Objective()) {
        this->objective_shape.push_back(std::shared_ptr<Shape>(any_shape));
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
    std::shared_ptr<Shape> selected;
    Point<int> cur_click;
    Point<int> prev_click;

    MLV_Button_state cur_state;
    MLV_Button_state prev_state;

    MLV_Mouse_button cur_mouse_button;
    MLV_Mouse_button prev_mouse_button;

    MLV_wait_event(nullptr, nullptr, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
                   &cur_mouse_button, &cur_state);

    while (!exit) {
        prev_click = cur_click;
        prev_state = cur_state;
        prev_mouse_button = cur_mouse_button;

        MLV_wait_event(nullptr, nullptr, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
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
                    if (shape->is_in_shape({static_cast<double>(cur_click.x), static_cast<double>(cur_click.y)})) {
                        selected = shape;
                    }
                }
            } else if (cur_state == MLV_RELEASED) {
                if (selected != nullptr) {
                    stick(selected);
                }
                selected = nullptr;
            }
        } else {
            if (selected && prev_mouse_button == cur_mouse_button && cur_mouse_button == MLV_BUTTON_LEFT) {
                selected->move({static_cast<double>(cur_click.x - prev_click.x),
                                static_cast<double>(cur_click.y - prev_click.y)});
            }
            if (selected && prev_mouse_button == cur_mouse_button && cur_mouse_button == MLV_BUTTON_RIGHT) {
                int dx = cur_click.x - prev_click.x;
                int dy = cur_click.y - prev_click.y;
                if (abso(dx) > abso(dy)) {
                    selected->rotate(static_cast<double>(dx) / 250.);
                } else {
                    selected->rotate(static_cast<double>(dy) / 250.);
                }
            }
        }
    }
}


void Game::add_shape(std::shared_ptr<Shape> s) {
    shapes.push_back(s);
}

void Game::set_Objective(const std::vector<std::shared_ptr<Shape>> &vec_objective) {
    objective_shape.clear();
    set_objective.clear();
    Objective::set_Objective(std::make_shared<Objective>(objective), vec_objective);

    objective_shape.insert(objective_shape.end(), vec_objective.begin(), vec_objective.end());

    for (auto &any_shape : this->objective_shape) {
        for (auto &point : any_shape->get_Points()) {
            this->set_objective.insert(point);
        }
    }
}

MLV_Color Game::get_Objective_Color() {
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

void Game::stick(const std::shared_ptr<Shape> &shape) {
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
            shape->move(Point<double>(0.0, 0.0));
        }
    }
}
