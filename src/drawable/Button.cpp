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

Button::Button(std::pair<int,int> point, std::pair<int,int> sizing, const char * text) {
    this->point = std::make_pair(point.first, point.second);
    this->sizing = std::make_pair(sizing.first, sizing.second); // sizing.first = w, sizing.second = h
    this->text = strdup(text);
    this->callback = nullptr;
}

Button::Button(std::pair<int,int> point, std::pair<int,int> sizing, const char* text, button_callback callback) {
    this->point = std::make_pair(point.first, point.second);
    this->sizing = std::make_pair(sizing.first, sizing.second);
    this->text = strdup(text);
    this->callback = callback;
}

void Button::set_callback(button_callback callback) {
    this->callback = callback;
}

bool Button::click_in_button(std::pair<int,int> click) {
    return click.first >= point.first && click.first <= point.first + sizing.first && click.second >= point.second && click.second <= point.second + sizing.second;
}

int Button::click(int val) {
    return callback(val);
}

void Button::draw() {
    return; // todo
}
