//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GAME_H
#define TANGRAM_GAME_H

/*!
 * @file Game.hpp
 * @brief Main Game of the Tangram
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <game/Objective.hpp>
#include <drawable/Shape.hpp>

/*!
 * @class Game
 * @brief Class of the main Game
 *
 * This class manage everything about the main game
 */

class Game {
private:
    std::vector<Shape *> shapes; /*!< Game main loop requires a vector of Shape - Abstract Class*/
    //std::vector <std::tr1::shared_ptr<Shape> >
    int w; /*!< Width of the window*/
    int h; /*!< Height of the window*/

    /*!
     * @brief Draw the current board
     */

    void draw();

public:

    /*!
     * @brief Main loop of the game
     */

    void main_loop();

    /*!
     * @brief Initialize the game
     * @param w : Width of the window
     * @param h : Height of the window
     */

    Game(int w, int h);

};


#endif //TANGRAM_GAME_H
