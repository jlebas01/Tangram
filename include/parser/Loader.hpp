//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_LOADER_H
#define TANGRAM_LOADER_H


#include <game/Game.hpp>

class Loader {

public:
    static bool parse_file(const std::string &filename, Game &game);
};


#endif //TANGRAM_LOADER_H
