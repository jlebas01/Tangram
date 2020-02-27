//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GAME_H
#define TANGRAM_GAME_H

/*!
 * @file C_Game.hpp
 * @brief Main C_Game of the Tangram
 * @author Jérémie LE BASTARD
 * @version 1.0
 */


#include <drawable/A_Shape.hpp>
#include <utils/T_Point.hpp>
#include <game/C_Objective.hpp>
#include <shape/C_STriangle.hpp>
#include <shape/C_MTriangle.hpp>
#include <shape/C_GTriangle.hpp>
#include <shape/C_Parallelogram.hpp>
#include <shape/C_Square.hpp>
#include <MLV/MLV_all.h>

#include <functional>
#include <unordered_set>
#include <memory>
#include <iostream>
#include <unordered_map>


/*!
 * @class C_Game
 * @brief Class of the main C_Game
 *
 * This class manage everything about the main game
 */

class C_Game {

private:

    /*!
     * @brief Class members
     */

    C_Objective mObjective; /*!< C_Objective of the game */
    std::unordered_set<T_Point<double>, T_Point<double>::hash_point, std::equal_to<>> mSetObjective; /*!< Set of mObjective of the game */
    std::vector<std::shared_ptr<A_Shape>> mObjectiveShape; /*!< Vector of mObjective shape */
    std::vector<std::shared_ptr<A_Shape>> mShapes; /*!< C_Game main loop requires a vector of A_Shape - Abstract Class*/
    int w; /*!< Width of the window*/
    int h; /*!< Height of the window*/
    std::shared_ptr<A_Shape> mMouseOvered = nullptr;

private:

    /*!
     * @brief Class methods
     */

    /*!
     * @brief Draw the current board
     */

    void __Draw();

    /*!
     * @brief __Stick the shape to nearest mObjective mPoints
     * @param shape : Last shape rotated or moved
     */

    void __Stick(const std::shared_ptr<A_Shape> &shape);

    /*!
     * @brief Detect if the Select A_Shape will be in collision with another one
     * @param shape : Selected Shape
     * @param next_translate : Next translate applied
     * @param angular : Next angular applied
     * @return true if a collision will happens, false if not
     */

    bool __Collision(const std::shared_ptr<A_Shape> &shape, T_Point<double> next_translate, double angular = 0);

public:

    /*!
     * @brief Main loop of the game
     */

    void MainLoop();

    /*!
     * @brief Destructor of the game
     */

    ~C_Game();

    /*!
     * @brief Constructor of the game, initialize a game with an sizing
     * @param w : Width of the window
     * @param h : Height of the window
     */

    C_Game(int w, int h);

    /*!
     * @brief Add a shape in the game
     * @param s : A_Shape to add
     */

    void addShape(std::shared_ptr<A_Shape> s);

    /*!
     * @brief Clear the game / the board and the mObjective
     */

    void Clear();

    /*!
     * @brief Set the mObjective of the game
     * @param vec_objective : Vector of C_Objective for new game;
     */

    void SetObjective(const std::vector<std::shared_ptr<A_Shape>> &vec_objective);

    /*!
     * @brief Get the mColor of the mObjective of the game
     * @return Return the mColor of the mObjective of the game
     */

    MLV_Color GetObjectiveColor();

};


#endif //TANGRAM_GAME_H
