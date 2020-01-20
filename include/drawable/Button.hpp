//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_BUTTON_H
#define TANGRAM_BUTTON_H

#include <utility>

typedef int (*button_callback) (int);

class Button {
private:
    std::pair<int,int> b_point; // <x,y>
    std::pair<int,int> b_sizing; // <width, height>
    char * b_text;
    button_callback b_callback;

public:
    ~Button();
    Button(std::pair<int,int> point, std::pair<int,int> sizing, const char * text);
    Button(std::pair<int,int> point, std::pair<int,int> sizing, const char * text, button_callback callback);
    void set_callback(button_callback);
    bool click_in_button(std::pair<int,int> click);
    int click(int);
    void draw();
};


#endif //TANGRAM_BUTTON_H
