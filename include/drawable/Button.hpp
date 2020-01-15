//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_BUTTON_H
#define TANGRAM_BUTTON_H


typedef int (*button_callback) (int);

class Button {
private:
    int x;
    int y;
    int w;
    int h;
    char * text;

    button_callback callback;

public:
    ~Button();
    Button(int x, int y, int w, int h, char * text);
    Button(int x, int y, int w, int h, char * text, button_callback callback);
    void set_callback(button_callback);
    bool click_in_button(int, int);
    int click(int);
    void draw();
};


#endif //TANGRAM_BUTTON_H
