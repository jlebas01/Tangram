// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SAVE_H
#define TANGRAM_SAVE_H

/*!
 * @file Save.hpp
 * @brief Save a board of Tangram
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <drawable/Shape.hpp>

/*!
 * @class Save
 * @brief Class of the main Saver
 *
 * This class manage everything about the save
 */

class Save {
private:
    unsigned int current_pages;

    unsigned int whereSaveIt();

    bool delete_file(std::filesystem::path file, unsigned int page);

    void gen_random(char *s, int len);

    std::string exec(const char* cmd);
public:
    Save();
    bool saveGame(const std::vector<std::shared_ptr<Shape>>& Game);
};


#endif //TANGRAM_SAVE_H
