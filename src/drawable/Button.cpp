//
// Created by jlebas01 on 15/01/2020.
//

#include <string>

#include <drawable/Button.hpp>
#include <MLV/MLV_color.h>
#include <MLV/MLV_text.h>

Button::~Button() {
}

Button::Button(std::pair<int,int> point, std::pair<int,int> sizing, const char * text) {
    this->b_point = std::make_pair(point.first, point.second);
    this->b_sizing = std::make_pair(sizing.first, sizing.second); // sizing.first = w, sizing.second = h
    this->b_text = strdup(text);
    this->b_callback = nullptr;
}

Button::Button(std::pair<int,int> point, std::pair<int,int> sizing, const char* text, button_callback callback) {
    this->b_point = std::make_pair(point.first, point.second);
    this->b_sizing = std::make_pair(sizing.first, sizing.second);
    this->b_text = strdup(text);
    this->b_callback = callback;
}

void Button::set_callback(button_callback callback) {
    this->b_callback = callback;
}

bool Button::click_in_button(std::pair<int,int> click) {
    return click.first >= b_point.first && click.first <= b_point.first + b_sizing.first && click.second >= b_point.second && click.second <= b_point.second + b_sizing.second;
}

int Button::click(int val) {
    return b_callback(val);
}

void Button::draw() {
    MLV_draw_text_box(b_point.first, b_point.second, b_sizing.first, b_sizing.second, b_text, 0,
            MLV_COLOR_RED, MLV_COLOR_BLUE, MLV_COLOR_RED,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}
