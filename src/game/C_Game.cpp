//
// Created by jlebas01 on 15/01/2020.
//

#include <game/C_Game.hpp>
#include <parser/C_Save.hpp>


C_Game::~C_Game() {
    mShapes.clear(); //delete all elements in vector mTriangles (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with mTriangles. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<std::shared_ptr<A_Shape>>().swap(mShapes);
    mObjectiveShape.clear();
    std::vector<std::shared_ptr<A_Shape>>().swap(mObjectiveShape);
    mSetObjective.clear();
    std::unordered_set<T_Point<double>, T_Point<double>::hash_point, std::equal_to<>>().swap(mSetObjective);
}

static int abso(int x) {
    return x < 0 ? -x : x;
}

C_Game::C_Game(const int _w, const int _h) {
    this->w = _w;
    this->h = _h;

    //ajouter toutes les formes
    (this->mShapes).push_back(std::shared_ptr<A_Shape>(std::make_shared<C_STriangle>(T_Point<double>(0.0, 0.0), 0.0)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(
                    std::make_shared<C_STriangle>(T_Point<double>(150.0, 50.0), 0.0, MLV_COLOR_AQUAMARINE3)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(std::make_shared<C_MTriangle>(T_Point<double>(0.0, 150.0), 0.0)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(std::make_shared<C_GTriangle>(T_Point<double>(200.0, 150.0), 0.0)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(
                    std::make_shared<C_GTriangle>(T_Point<double>(400.0, 150.0), 0.0, MLV_COLOR_CORAL3)));
    (this->mShapes).push_back(std::shared_ptr<A_Shape>(std::make_shared<C_Square>(T_Point<double>(250.0, 50.0), 0.0)));
    (this->mShapes).push_back(
            std::shared_ptr<A_Shape>(std::make_shared<C_Parallelogram>(T_Point<double>(100.0, 150.0), 0.0)));

}

void C_Game::__Draw() {
    MLV_clear_window(MLV_COLOR_BLACK);

    for (auto &shape : mObjectiveShape) {
        shape->iDraw();
    }

    for (auto &shape : mShapes) {
        shape->iDraw();
    }
    if (mMouseOvered)
        mMouseOvered->iDraw(MLV_COLOR_ALICE_BLUE);

    MLV_actualise_window();
}

void C_Game::MainLoop() {
    bool exit = false;
    std::shared_ptr<A_Shape> selected;
    C_Save saver;
    T_Point<int> cur_click;
    T_Point<int> prev_click;
    MLV_Keyboard_button key;

    MLV_Button_state cur_state;
    MLV_Button_state prev_state;

    MLV_Mouse_button cur_mouse_button;
    MLV_Mouse_button prev_mouse_button;

    MLV_wait_event((&key), nullptr, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
                   &cur_mouse_button, &cur_state);

    while (!exit) {
        key = MLV_KEYBOARD_NONE;
        prev_click = cur_click;
        prev_state = cur_state;
        prev_mouse_button = cur_mouse_button;

        MLV_wait_event(&key, nullptr, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
                       &cur_mouse_button, &cur_state);


        __Draw();

        if (C_Objective::BoardCompleted(mObjectiveShape, mShapes)) {
            exit = true;
            MLV_wait_seconds(3);
            continue;
        }

        if (key == MLV_KEYBOARD_s) {
            const std::vector<std::shared_ptr<A_Shape>> current_game = this->mShapes;
            if (saver.Save(current_game)) {
                exit = true;
                continue;
            }
        }

        if (cur_state == MLV_RELEASED) {
            for (auto &shape: mShapes) {
                if (shape->aIsInShape({static_cast<double>(cur_click.x), static_cast<double>(cur_click.y)})) {
                    mMouseOvered = shape;
                    if (key == MLV_KEYBOARD_f && shape->aIsInShape({static_cast<double>(cur_click.x), static_cast<double>(cur_click.y)}) ){
                        mMouseOvered->aFlip();
                        __Draw();
                        key = MLV_KEYBOARD_NONE;
                    }

                    break;
                }
                mMouseOvered = nullptr;
            }
        }

        if (prev_state != cur_state) {
            if (cur_state == MLV_PRESSED) {
                for (auto &shape: mShapes) {
                    if (shape->aIsInShape({static_cast<double>(cur_click.x), static_cast<double>(cur_click.y)})) {
                        selected = shape;
                        break;
                    }
                }
            } else if (cur_state == MLV_RELEASED) {
                if (selected != nullptr) {
                    __Stick(selected);
                }
                selected = nullptr;
            }
        } else {
            if (selected && prev_mouse_button == cur_mouse_button && cur_mouse_button == MLV_BUTTON_LEFT) {
                if (!__Collision(selected, {static_cast<double>(cur_click.x - prev_click.x),
                                            static_cast<double>(cur_click.y - prev_click.y)})) {
                    selected->aMove({static_cast<double>(cur_click.x - prev_click.x),
                                     static_cast<double>(cur_click.y - prev_click.y)});
                }

            }
            if (selected && prev_mouse_button == cur_mouse_button && cur_mouse_button == MLV_BUTTON_RIGHT) {
                int dx = cur_click.x - prev_click.x;
                int dy = cur_click.y - prev_click.y;


                if (abso(dx) > abso(dy)) {
                    if (!__Collision(selected, {0, 0}, static_cast<double>(dx) / 250.)) {
                        selected->aRotate(static_cast<double>(dx) / 250.);
                    } else {
                        selected->aRotate(-static_cast<double>(dx) / 250.);
                    }
                } else {
                    if (!__Collision(selected, {0, 0}, static_cast<double>(dy) / 250.)) {
                        selected->aRotate(static_cast<double>(dy) / 250.);
                    } else {
                        selected->aRotate(-static_cast<double>(dy) / 250.);
                    }
                }
            }
        }
    }
}


void C_Game::addShape(std::shared_ptr<A_Shape> s) {
    mShapes.push_back(s);
}

void C_Game::SetObjective(const std::vector<std::shared_ptr<A_Shape>> &vec_objective) {
    mObjectiveShape.clear();
    mSetObjective.clear();
    C_Objective::SetObjective(std::make_shared<C_Objective>(mObjective), vec_objective);

    mObjectiveShape.insert(mObjectiveShape.end(), vec_objective.begin(), vec_objective.end());

    for (auto &any_shape : this->mObjectiveShape) {
        for (auto &point : any_shape->aGetPoints()) {
            this->mSetObjective.insert(point);
        }
    }
}

MLV_Color C_Game::GetObjectiveColor() {
    return mObjective.GetColor();
}

void C_Game::Clear() {
    mShapes.clear();
    mObjectiveShape.clear();
    mSetObjective.clear();
}

bool C_Game::__Collision(const std::shared_ptr<A_Shape> &shape, T_Point<double> next_translate, double angular) {
    auto set_shape = new std::unordered_set<T_Point<double>, T_Point<double>::hash_point, std::equal_to<>>();
    auto set_shape_game = new std::unordered_set<T_Point<double>, T_Point<double>::hash_point, std::equal_to<>>();
    const std::vector<std::shared_ptr<A_Shape>> vec_shapes = mShapes;
    shape->aRotate(angular);

    for (auto &it : shape->aGetPoints()) {
        set_shape->insert({it.x + next_translate.x, it.y + next_translate.y});
    }
    for (auto &p_selected : *set_shape) {
        for (auto &shape_game : vec_shapes) {
            if (shape_game != shape) {

                if (shape_game->aIsInShape(p_selected)) {
                    return true;
                }

            }
        }

    }


    delete set_shape;
    delete set_shape_game;
    return false;
}

void C_Game::__Stick(const std::shared_ptr<A_Shape> &shape) {
    auto set_shape = new std::unordered_set<T_Point<double>, T_Point<double>::hash_point, std::equal_to<>>();
    auto map_distance = std::unordered_map<T_Point<double>, std::pair<T_Point<double>, double>, T_Point<double>::hash_point, std::equal_to<>>();

    for (auto &it: shape->aGetPoints()) {
        set_shape->insert(it);
    }

    for (auto &p_game : *set_shape) {
        for (auto &p_objective : mSetObjective) {
            double distance = A_Shape::computeDistance(p_game, p_objective);
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
        std::vector<T_Point<double>> save;
        for (auto & it : shape->aGetPoints()){
            save.emplace_back(T_Point<double>{it.x, it.y});
        }



        for (auto &p_min : map_distance) {
            shape->aSetPoints(p_min.second.first, p_min.first);
        }
        shape->aMove(T_Point<double>(0.0, 0.0));
       for (auto & it : mObjectiveShape){
           const double area = shape->aGetArea();
           if ((area  + 0.05 * area >= it->aGetArea()) && (it->aGetArea() >= area - 0.05 * area )) {
               return;
           }
       }
        for (unsigned long  i = 0 ; i < save.size() ; i++){
            shape->aSetPoints(shape->aGetPoints().at(i), save.at(i));
        }
    }
    shape->aMove(T_Point<double>(0.0, 0.0));
    delete set_shape;
}
