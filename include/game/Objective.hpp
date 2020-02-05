//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_OBJECTIVE_H
#define TANGRAM_OBJECTIVE_H

/*!
 * @file Objective.hpp
 * @brief Objective of the Tangram's board
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <drawable/Shape.hpp>
#include <string>

/*!
 * @class Objective
 * @brief Class of the board Objective
 *
 * This class manage everything about the objective
 */

class Objective {
private:
    std::vector<Shape *> shapes; /*!< Objective requires a vector of Shape to check when the game end*/
public:

    /*!
     * @brief Constructor of an objective
     */

    Objective();

    /*!
     * @brief Check if the board is completed
     * @param objective : Vector of objective's shape
     * @param game : Vector of current game's shape
     * @return True if the board is completed, false if not
     */

    static bool boardCompleted(const std::vector<Shape *> &objective, const std::vector<Shape *> &game);

    /*!
     * @brief Get all shape of the objective
     * @return Return a vector of shape of the objective
     */

    std::vector<Shape *> get_Objective();

};


#endif //TANGRAM_OBJECTIVE_H
