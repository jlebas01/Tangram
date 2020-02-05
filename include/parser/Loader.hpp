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
#include <filesystem>

/*!
 * @class Loader
 * @brief Class of the main Loader
 *
 * This class manage everything about the loader
 */

class Loader {
private:

    /*!
     * @brief Refactor a relative path to absolute path to the file.
     * @param path : Requires just the filename
     * @return Return an absolute path to the file
     */

    static std::filesystem::path refactor_path(const std::filesystem::path &path);

    /*!
     * @brief Convert a string to an int in constexpr
     * @param str : string to convert to int
     * @param h : hash parameter
     * @return Return a constexpr unsigned int. This int is unique for every string
     */

    static constexpr unsigned int str2int(const char *str, int h = 0) {
        return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ static_cast<unsigned int>(str[h]);
    }

public:

    /*!
     * @brief Parse a file to make a board
     * @param filename : name of the file, this file should be located in this directory ./Tangram/extern/board/
     * @param game : The current game / board
     * @return True if the game has been created, false if not
     */

    static bool parse_file(const std::string &filename, Game &game);
};

#endif //TANGRAM_LOADER_H
