//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include "../../include/drawable/Menu.h"
#include <MLV/MLV_all.h>


class Menu {
private:
    vector<Button> buttons;
public:
    Menu::main_loop() {
        int x, y;

        // get_click()

        for (auto b: buttons) {
            if (b.click_in_button(x, y)) {
                b.click(0);
            }
        }
    }

    Menu::draw() {

    }
};