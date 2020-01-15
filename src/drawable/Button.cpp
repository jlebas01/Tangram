//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include "../../include/drawable/Button.h"

class Button {
    Button(const int x, const int y, const int w, const int h) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    Button(const int x, const int y, const int w, const int h, button_callback callback) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->callback = callback;
    }

    void Button::set_callback(button_callback) {
        this->callback = button_callback;
    }

    bool Button::click_in_button(int a, int b) {
        if (a >= x && a <= x + w && b >= y && b <= y + h) {
            return true;
        }
        return false;
    }

    int Button::click(int val) {
        return callback(val);
    }
};