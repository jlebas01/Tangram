//
// Created by jlebas01 on 15/01/2020.
//

#include <parser/Loader.hpp>
#include <drawable/Menu.hpp>
#include <drawable/Button.hpp>
#include <MLV/MLV_all.h>
#include <game/Game.hpp>
#include <filesystem>


static const int W_WIDTH = static_cast<int>(MLV_get_desktop_width() * 0.8);
static const int W_HEIGHT = static_cast<int>(MLV_get_desktop_height() * 0.8);
int page = 1;

static int load_callback(int v) {
    Menu menu;
    std::string path("../extern/board/page" + std::to_string(page));

    if (!std::filesystem::is_directory(path)) {
        return 1;
    }

    double i = 0.25, j = 1.0;

    for (auto &entry : std::filesystem::directory_iterator(path)) {
        auto pos_x = static_cast<int>(i * static_cast<double>(W_WIDTH) / 6.0), pos_y = static_cast<int>(j * static_cast<double>(W_HEIGHT) / 6.0);
        menu.add_button({{pos_x, pos_y},
                         {W_WIDTH / 6, W_HEIGHT / 6}, entry.path().filename(),
                         [entry](int a) -> int {
                             Game game(W_WIDTH, W_HEIGHT);
                             Loader::parse_file(entry.path(), game);
                             game.main_loop();
                             page = 1;
                             return 0;
                         }});
        i += 1.5;

        if (i > 5) {
            i = 0.25;
            j += 1.5;
        }
    }

    if (std::filesystem::is_directory("../extern/board/page" + std::to_string(page + 1)))
        menu.add_button({{W_WIDTH - W_WIDTH / 3, W_HEIGHT - W_HEIGHT / 8}, {W_WIDTH / 6, W_HEIGHT / 9}, "next ->",
                         [](int a) -> int {
                             page++;
                             load_callback(0);
                             return 0;
                         }});

    if (std::filesystem::is_directory("../extern/board/page" + std::to_string(page - 1)))
        menu.add_button({{W_WIDTH / 6, W_HEIGHT - W_HEIGHT / 8}, {W_WIDTH / 6, W_HEIGHT / 9}, "<- prev",
                         [](int a) -> int {
                             page--;
                             load_callback(0);
                             return 0;
                         }});

    menu.add_button({{W_WIDTH / 2 - W_WIDTH / 12, W_HEIGHT - W_HEIGHT / 8}, {W_WIDTH / 6, W_HEIGHT / 9}, "back",
                     [](int) -> int {
                         return 0;
                     }});
    std::cout << std::filesystem::directory_entry(path).path().filename() << std::endl;
    menu.add_button({{W_WIDTH / 2 - W_WIDTH / 8, W_HEIGHT / 24}, {W_WIDTH / 4, W_HEIGHT / 9},
                     std::filesystem::directory_entry(path).path().filename(), [](int) -> int {
                return 1;
            }});


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
    unsigned int nb_file = 0;

    MLV_create_window("Tangram", nullptr, W_WIDTH, W_HEIGHT);
    m.main_loop();

    MLV_free_window();
    std::exit(EXIT_SUCCESS);
}
