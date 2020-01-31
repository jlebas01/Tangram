//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_BUTTON_H
#define TANGRAM_BUTTON_H

#include <utility>
#include <utils/Point.hpp>
#include <functional>


class Button {
private:
    Point<int> b_point; // <x,y>
    Point<int> b_sizing; // <width, height>
    std::string b_text;
    std::function<int(int)> b_callback;

public:
    ~Button();

    Button(Point<int> point, Point<int> sizing, std::string text);

    Button(Point<int> point, Point<int> sizing, std::string text, std::function<int(int)> callback);

    bool click_in_button(const Point<int> &click);

    int click(int);

    void draw();

    void set_callback(std::function<int(int)> callback);
};


#endif //TANGRAM_BUTTON_H
