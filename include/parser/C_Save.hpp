// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SAVE_H
#define TANGRAM_SAVE_H

/*!
 * @file C_Save.hpp
 * @brief C_Save a board of Tangram
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <drawable/A_Shape.hpp>

/*!
 * @class C_Save
 * @brief Class of the main Saver
 *
 * This class manage everything about the save
 */

class C_Save {


private:

    /*!
     * @brief Class members
     */

    unsigned int mCurrentPages; /*!< Number of pages currently */

private:

    /*!
     * @brief Class methods
     */

    unsigned int __WhereSaveIt();

    bool __DeleteFile(std::filesystem::path file, unsigned int page);

    static void __GenRandom(char *s, int len);

    static std::string __ExecCommand(const char* cmd);

public:

    C_Save();

    bool Save(const std::vector<std::shared_ptr<A_Shape>>& Game);
};


#endif //TANGRAM_SAVE_H
