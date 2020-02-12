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


#include <drawable/Shape.hpp>
#include <utils/Point.hpp>
#include <game/Objective.hpp>
#include <shape/STriangle.hpp>
#include <shape/MTriangle.hpp>
#include <shape/GTriangle.hpp>
#include <shape/Parallelogram.hpp>
#include <shape/Square.hpp>
#include <MLV/MLV_all.h>

#include <functional>
#include <unordered_set>
#include <memory>
#include <iostream>
#include <unordered_map>


/*!
 * @class Game
 * @brief Class of the main Game
 *
 * This class manage everything about the main game
 */

class Game {
private:
    Objective objective; /*!< Objective of the game */
    std::unordered_set<Point<double>, Point<double>::hash_point, std::equal_to<>> set_objective; /*!< Set of objective of the game */
    std::vector<std::shared_ptr<Shape>> objective_shape; /*!< Vector of objective shape */
    std::vector <std::shared_ptr<Shape>> shapes; /*!< Game main loop requires a vector of Shape - Abstract Class*/
    int w; /*!< Width of the window*/
    int h; /*!< Height of the window*/
    std::shared_ptr<Shape> mouseovered = nullptr;

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
     * @brief Destructor of the game
     */

    ~Game();

    /*!
     * @brief Constructor of the game, initialize a game with an sizing
     * @param w : Width of the window
     * @param h : Height of the window
     */

    Game(int w, int h);

    /*!
     * @brief Add a shape in the game
     * @param s : Shape to add
     */

    void add_shape(std::shared_ptr<Shape> s);

    /*!
     * @brief Clear the game / the board and the objective
     */

    void clear();

    /*!
     * @brief Stick the shape to nearest objective points
     * @param shape : Last shape rotated or moved
     */

    void stick(const std::shared_ptr<Shape>& shape);

    /*!
     * @brief Set the objective of the game
     * @param vec_objective : Vector of Objective for new game;
     */

    void set_Objective(const std::vector<std::shared_ptr<Shape>> &vec_objective);

    /*!
     * @brief Get the color of the objective of the game
     * @return Return the color of the objective of the game
     */

    MLV_Color get_Objective_Color();
};


#endif //TANGRAM_GAME_H
