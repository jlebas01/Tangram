//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MENU_H
#define TANGRAM_MENU_H

#include <drawable/Button.hpp>
#include <vector>

class Menu {
    private:
        std::vector<Button> buttons;
        void draw();
    public:
        void add_button(Button);
        void main_loop();
};


#endif //TANGRAM_MENU_H
