//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include <game/Game.hpp>
#include <MLV/MLV_all.h>

Game::Game(const int w, const int h) {
    this->w = w;
    this->h = h;
}

void Game::draw() {
    MLV_clear_window(MLV_COLOR_BLACK);

    // shapes

    MLV_actualise_window();
}

void Game::main_loop() {
    bool exit = false;
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
        MLV_get_event(&cur_button, &cur_modifier, nullptr, nullptr, nullptr, &(cur_click.x), &(cur_click.y),
                      &cur_mouse_button, &cur_state);

        if (prev_click != cur_click || prev_state != cur_state || prev_mouse_button != cur_mouse_button ||
            prev_modifier != cur_modifier || prev_button != cur_button) {
            draw();
        }

        if (prev_state != cur_state) {
            if (cur_state == MLV_PRESSED) {
                // SELECT
            }
            else if (cur_state == MLV_RELEASED) {
                // RELEASE
            }
        }
        printf("(%d %d) state : %d, button : %d, mouse : %d\n", cur_click.x, cur_click.y, cur_state, cur_button, cur_mouse_button);


    }
}
