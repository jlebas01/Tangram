//
// Created by jlebas01 on 15/01/2020.
//

#include <string>

#include <drawable/Button.hpp>
#include <utility>
#include <MLV/MLV_color.h>
#include <MLV/MLV_text.h>

Button::~Button() = default;

Button::Button(const Point<int> &point, const Point<int> &sizing, std::string text) : b_point(point), b_sizing(sizing),
                                                                        b_text(std::move(text)), b_callback(
                nullptr) {}

Button::Button(const Point<int> &point, const Point<int> &sizing, std::string text, std::function<int(int)> callback)
        : b_point(point), b_sizing(sizing), b_text(std::move(text)), b_callback(std::move(
        callback)) {}

void Button::set_callback(std::function<int(int)> callback) {
    this->b_callback = std::move(callback);
}

bool Button::click_in_button(const Point<int> &click) {
    return click.x >= b_point.x && click.x <= b_point.x + b_sizing.x && click.y >= b_point.y &&
           click.y <= b_point.y + b_sizing.y;
}

int Button::click(int val) {
    return b_callback(val);
}

void Button::draw() {
    MLV_draw_text_box(b_point.x, b_point.y, b_sizing.x, b_sizing.y, b_text.c_str(), 0,
                      MLV_COLOR_RED, MLV_COLOR_BLUE, MLV_COLOR_RED,
                      MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}
