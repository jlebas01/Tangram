//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include <drawable/Menu.hpp>
#include <MLV/MLV_all.h>


void Menu::main_loop() {
    int x = 0, y = 0;

    // get_click()

    for (auto b: buttons) {
        if (b.click_in_button(x, y)) {
            b.click(0);
        }
    }
}

void Menu::draw() {

}
