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
#include <memory>
#include <MLV/MLV_color.h>

/*!
 * @class Objective
 * @brief Class of the board Objective
 *
 * This class manage everything about the objective
 */

class Objective {
private:
    std::vector<std::shared_ptr<Shape>> shapes; /*!< Objective requires a vector of Shape to check when the game end*/
    MLV_Color color; /*!< Objective requires a color to draw these shapes */
public:

    /*!
     * @brief Constructor of an objective, default constructor
     * @param color : color of the objective shape
     */

    explicit Objective(MLV_Color color=MLV_COLOR_GRAY70);

    /*!
     * @brief Constructor of an objective
     * @param objective : Objective requires a vector of Shape
     * @param color : color of the objective shape
     */

    explicit Objective(const std::vector<std::shared_ptr<Shape>> &objective, MLV_Color color = MLV_COLOR_GRAY70);

    /*!
     * @brief Check if the board is completed
     * @param objective : Vector of objective's shape
     * @param game : Vector of current game's shape
     * @return True if the board is completed, false if not
     */

    static bool boardCompleted(const std::vector<std::shared_ptr<Shape>> &objective, const std::vector<std::shared_ptr<Shape>> &game);

    /*!
     * @brief Get all shape of the objective
     * @return Return a vector of shape of the objective
     */

    std::vector<std::shared_ptr<Shape>> get_Objective();

    /*!
     * @brief Set an Objective for a new game
     * @param objective : Objective to update
     * @param vec_objective :Vector of new Shape for the new Objective
     */

    static void set_Objective(Objective * objective, const std::vector<std::shared_ptr<Shape>> &vec_objective);

    /*!
     * @brief Get the color of an Objective
     * @return Return the color of an Objective
     */

    MLV_Color get_Color();
};


#endif //TANGRAM_OBJECTIVE_H
