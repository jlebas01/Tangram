//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MENU_H
#define TANGRAM_MENU_H

#include <tangram/drawable/Button>
#include <vector>


class Menu {
    private:
        vector<Button> buttons;
    public:
        Menu::main_loop();
        Menu::draw();
};


#endif //TANGRAM_MENU_H
