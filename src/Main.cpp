//
// Created by jlebas01 on 15/01/2020.
//

#include <parser/Loader.hpp>
#include <drawable/Menu.hpp>
#include <drawable/Button.hpp>
#include <MLV/MLV_all.h>
#include <game/Game.hpp>
#include <filesystem>

#define W_WIDTH 1000
#define W_HEIGHT 800

int page = 1;

static int load_callback(int v) {
    Menu menu;
    std::string path("../extern/board/page" + std::to_string(page));

    double i = 0.25, j = 1;

    for (auto &entry : std::filesystem::directory_iterator(path)) {
        Game game(W_WIDTH, W_HEIGHT);
        Loader::parse_file(entry.path(), game);
        menu.add_button({{i * (static_cast<double>(W_WIDTH) / 6), j * (static_cast<double>(W_HEIGHT) / 6)},
                         {W_WIDTH / 6, W_HEIGHT / 6}, entry.path().filename(),
                         [&game](int a) -> int {
                             game.main_loop();
                             return 0;
                         }});
        i += 1.5;

        if (i > 5) {
            i = 0.25;
            j += 1.5;
        }

        if (std::filesystem::is_directory("../extern/board/page" + std::to_string(page + 1)))
            menu.add_button({{W_WIDTH - W_WIDTH / 3, W_HEIGHT - W_HEIGHT / 8}, {W_WIDTH / 6, W_HEIGHT / 9}, "next ->",
                             [](int a) -> int {
                                 page++;
                                 load_callback(0);
                             }});

        if (std::filesystem::is_directory("../extern/board/page" + std::to_string(page - 1)))
            menu.add_button({{W_WIDTH / 6, W_HEIGHT - W_HEIGHT / 8}, {W_WIDTH / 6, W_HEIGHT / 9}, "<- prev",
                             [](int a) -> int {
                                 page--;
                                 load_callback(0);
                             }});
    }

    menu.main_loop();
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
            Button({W_WIDTH / 3, static_cast<int>(W_HEIGHT / 2.5)}, {W_WIDTH / 3, W_HEIGHT / 6}, "Load",
                   load_callback));
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
