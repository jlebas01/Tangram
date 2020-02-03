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

/*!
 * @class Objective
 * @brief Class of the board Objective
 *
 * This class manage everything about the objective
 */

class Objective {
private:
    std::vector<Shape> piece; /*!< Objective requires a vector of Shape to check when the game end*/
public:

    /*!
     * @brief Check if the board is completed
     * @param objective : Vector of objective's shape
     * @param game : Vector of current game's shape
     * @return True if the board is completed, false if not
     */

    bool boardCompleted(std::vector<Shape*> objective, std::vector<Shape*> game);
};


#endif //TANGRAM_OBJECTIVE_H
