//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include <game/Game.hpp>
#include <shape/STriangle.hpp>
#include <shape/MTriangle.hpp>
#include <shape/GTriangle.hpp>
#include <shape/Parallelogram.hpp>
#include <shape/Square.hpp>
#include <MLV/MLV_all.h>

static int max(int a, int b) {
    return (a > b) ? a : b;
}

Game::Game(const int w, const int h) {
    this->w = w;
    this->h = h;

    //ajouter toutes les formes
    (this->shapes).push_back(new Parallelogram({50.0, 50.0}, 0.0));

}

void Game::draw() {
    MLV_clear_window(MLV_COLOR_BLACK);

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

    MLV_get_event(&cur_button, &cur_modifier, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
                  &cur_mouse_button, &cur_state);

    while (!exit) {
        prev_click = cur_click;
        prev_state = cur_state;
        prev_mouse_button = cur_mouse_button;
        prev_modifier = cur_modifier;
        prev_button = cur_button;
        MLV_wait_event(&cur_button, &cur_modifier, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
                       &cur_mouse_button, &cur_state);

        if (prev_click != cur_click || prev_state != cur_state || prev_mouse_button != cur_mouse_button ||
            prev_modifier != cur_modifier || prev_button != cur_button) {
            draw();
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
            }
            if (selected && prev_mouse_button == cur_mouse_button && cur_mouse_button == MLV_BUTTON_RIGHT) {
                int dx = cur_click.x - prev_click.x;
                int dy = cur_click.y - prev_click.y;
                selected->rotate(static_cast<double> (max(dx, dy)) / 1000);
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
