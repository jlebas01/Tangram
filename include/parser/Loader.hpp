//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_LOADER_H
#define TANGRAM_LOADER_H

/*!
 * @file Loader.hpp
 * @brief Load a board of Tangram
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <game/Game.hpp>

/*!
 * @class Loader
 * @brief Class of the main Loader
 *
 * This class manage everything about the loader
 */

class Loader {

public:

    /*!
     * @brief Parse a file to make a board
     * @param filename : name of the file
     * @param game : The current game / board
     * @return True if the game has been created, false if not
     */

    static bool parse_file(const std::string &filename, Game &game);
};


#endif //TANGRAM_LOADER_H
