//
// Created by jlebas01 on 15/01/2020.
//

#include <drawable/Menu.hpp>
#include <utils/Point.hpp>
#include <MLV/MLV_all.h>
#include <iostream>


void Menu::add_button(Button b) {
    buttons.push_back(b);
}

void Menu::main_loop() {
    int x, y;
    bool exit = false;

    while (!exit) {
        draw();
        MLV_wait_mouse(&x, &y);

        for (auto b: buttons) {
            if (b.click_in_button(Point<int>(x, y))) {
                if (!b.click(0)) {
                    exit = true;
                }
            }
        }
    }
}

void Menu::draw() {
    MLV_clear_window(MLV_COLOR_GRAY3);
    for (auto b: buttons) {
        b.draw();
    }
    MLV_actualise_window();
}
