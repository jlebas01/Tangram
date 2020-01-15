//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_BUTTON_H
#define TANGRAM_BUTTON_H


typedef int (button_callback*) (int);

class Button {
private:
    int x;
    int y;
    int w;
    int h;

    button_callback callback;

public:
    Button(int x, int y, int w, int h);
    void Button::set_callback(button_callback);
    bool Button::click_in_button(int, int);
    int Button::click();
    void Button::draw();
};


#endif //TANGRAM_BUTTON_H
