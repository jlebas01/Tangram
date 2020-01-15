//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <string>
#include <string.h>

#include <drawable/Button.hpp>

Button::~Button() {
    delete text;
}

Button::Button(int x, int y, int w, int h, char * text) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->text = strdup(text);
    this->callback = nullptr;
}

Button::Button(int x, int y, int w, int h, char* text, button_callback callback) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->text = strdup(text);
    this->callback = callback;
}

void Button::set_callback(button_callback callback) {
    this->callback = callback;
}

bool Button::click_in_button(int a, int b) {
    return a >= x && a <= x + w && b >= y && b <= y + h;
}

int Button::click(int val) {
    return callback(val);
}

void Button::draw() {
    return; // todo
}
