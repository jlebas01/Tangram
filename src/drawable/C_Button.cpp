//
// Created by jlebas01 on 15/01/2020.
//

#include <string>

#include <drawable/C_Button.hpp>
#include <utility>
#include <MLV/MLV_color.h>
#include <MLV/MLV_text.h>

C_Button::~C_Button() = default;

C_Button::C_Button(const T_Point<int> &point, const T_Point<int> &sizing, std::string text) : mBPoint(point), mBSizing(sizing),
                                                                                              mBText(std::move(text)), mBCallBack(
                nullptr) {}

C_Button::C_Button(const T_Point<int> &point, const T_Point<int> &sizing, std::string text, std::function<int(int)> callback)
        : mBPoint(point), mBSizing(sizing), mBText(std::move(text)), mBCallBack(std::move(
        callback)) {}

void C_Button::SetCallBack(std::function<int(int)> callback) {
    this->mBCallBack = std::move(callback);
}

bool C_Button::ClickInButton(const T_Point<int> &click) {
    return click.x >= mBPoint.x && click.x <= mBPoint.x + mBSizing.x && click.y >= mBPoint.y &&
           click.y <= mBPoint.y + mBSizing.y;
}

int C_Button::Click(int val) {
    return mBCallBack(val);
}

void C_Button::Draw() {
    MLV_draw_text_box(mBPoint.x, mBPoint.y, mBSizing.x, mBSizing.y, mBText.c_str(), 0,
                      MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_GOLDENROD,
                      MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

void C_Button::Draw(MLV_Color color) {
    MLV_draw_text_box(mBPoint.x, mBPoint.y, mBSizing.x, mBSizing.y, mBText.c_str(), 0,
                      MLV_COLOR_BLACK, MLV_COLOR_BLACK, color,
                      MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}
