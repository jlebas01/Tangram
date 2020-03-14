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

    /*!
     * @brief Check which pages the file will be save
     * @return Return an unsigned int corresponding at the page to save the file
     */

    unsigned int __WhereSaveIt();

    /*!
     * @brief Delete a puzzle file
     * @param file : File to delete
     * @param page : Page where the file to delete is
     * @return Return true if the file is deleted, false otherwise
     */

    bool __DeleteFile(std::filesystem::path file, unsigned int page);

    /*!
     * @brief Generates a random string
     * @param s : the random string will be store here
     * @param len : len of the random string
     */

    void __GenRandom(const std::shared_ptr<char[]> &s, int len);

    /*!
     * @brief Execute a shell command
     * @param cmd : shell command to execute
     * @return Return the output of the shell command
     */

    static std::string __ExecCommand(const char* cmd);

public:

    /*!
     * Construct an instance of a saver
     */

    C_Save();

    /*!
     * @brief Save the current board as puzzle file in a page which contains less than 12 files
     * @param Game : Current game
     * @return Return true if the board has been saved, false otherwise
     */

    bool Save(const std::vector<std::shared_ptr<A_Shape>>& Game);


};


#endif //TANGRAM_SAVE_H
