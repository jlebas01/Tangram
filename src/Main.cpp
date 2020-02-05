//
// Created by jlebas01 on 15/01/2020.
//

#include <parser/Loader.hpp>
#include <drawable/Menu.hpp>
#include <drawable/Button.hpp>
#include <MLV/MLV_all.h>
#include <game/Game.hpp>
#include <parser/Loader.hpp>

#define W_WIDTH 1000
#define W_HEIGHT 800

static int load_callback(int v) {
    Game g(W_WIDTH, W_HEIGHT);

    Loader::parse_file("test.txt", g);
    g.main_loop();
    return 1;
}

static int exit_button_callback(int val) {
    return 0;
}

static int launch_game_button_callback(int val) {
    Game game(W_WIDTH, W_HEIGHT);

    game.main_loop();

    return 1;
}

static int settings_button_callback(int val) {

    return 2;
}

static Menu create_main_menu() {
    Menu menu;

    menu.add_button(
            Button({W_WIDTH / 3, W_HEIGHT / 6}, {W_WIDTH / 3, W_HEIGHT / 6}, "Launch", launch_game_button_callback));
    menu.add_button(
            Button({W_WIDTH / 3, static_cast<int>(W_HEIGHT / 2.5)}, {W_WIDTH / 3, W_HEIGHT / 6}, "Load", load_callback));
    menu.add_button(
            Button({W_WIDTH / 6, 4 * W_HEIGHT / 6}, {W_WIDTH / 6, W_HEIGHT / 6}, "Settings", settings_button_callback));
    menu.add_button(
            Button({4 * W_WIDTH / 6, 4 * W_HEIGHT / 6}, {W_WIDTH / 6, W_HEIGHT / 6}, "Exit", exit_button_callback));

    return menu;
}

int main(int argc, char *argv[]) {
    Menu m = create_main_menu();

    MLV_create_window("Tangram", nullptr, W_WIDTH, W_HEIGHT);
    m.main_loop();

    MLV_free_window();
    std::exit(EXIT_SUCCESS);
}
