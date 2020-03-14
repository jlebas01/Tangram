//
// Created by jlebas01 on 15/01/2020.
//

#include <drawable/C_Menu.hpp>
#include <utils/T_Point.hpp>
#include <MLV/MLV_all.h>

C_Menu::~C_Menu(){
    mButtons.clear();
    std::vector<C_Button>().swap(mButtons);
}

void C_Menu::AddButton(const C_Button &button) {
    mButtons.push_back(button);
}

void C_Menu::MainLoop() {
    int x, y;
    bool exit = false;

    while (!exit) {
        __Draw();
        MLV_wait_mouse(&x, &y);

        for (auto b: mButtons) {
            if (b.ClickInButton(T_Point<int>(x, y))) {
                if (!b.Click(0)) {
                    exit = true;
                }
            }
        }
    }
}

void C_Menu::__Draw() {
    MLV_clear_window(MLV_COLOR_LIGHT_GOLDENROD);
    for (auto b: mButtons) {
        b.Draw();
    }

    MLV_actualise_window();
}
