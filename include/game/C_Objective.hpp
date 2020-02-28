//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_OBJECTIVE_H
#define TANGRAM_OBJECTIVE_H

/*!
 * @file C_Objective.hpp
 * @brief C_Objective of the Tangram's board
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <drawable/A_Shape.hpp>
#include <string>
#include <memory>
#include <MLV/MLV_color.h>

/*!
 * @class C_Objective
 * @brief Class of the board C_Objective
 *
 * This class manage everything about the mObjective
 */

class C_Objective {

private:

    /*!
     * @brief Class members
     */

    std::vector<std::shared_ptr<A_Shape>> mShapes; /*!< C_Objective requires a vector of A_Shape to check when the game end*/
    MLV_Color mColor; /*!< C_Objective requires a mColor to iDraw these mShapes */

public:

    /*!
     * @brief Class methods
     */

     ~C_Objective();

    /*!
     * @brief Constructor of an mObjective, default constructor
     * @param color : mColor of the mObjective shape
     */

    explicit C_Objective(MLV_Color color=MLV_COLOR_GRAY70);

    /*!
     * @brief Constructor of an mObjective
     * @param objective : C_Objective requires a vector of A_Shape
     * @param color : mColor of the mObjective shape
     */

    explicit C_Objective(const std::vector<std::shared_ptr<A_Shape>> &objective, MLV_Color color = MLV_COLOR_GRAY70);

    /*!
     * @brief Check if the board is mCompleted
     * @param objective : Vector of mObjective's shape
     * @param game : Vector of current game's shape
     * @return True if the board is mCompleted, false if not
     */

    static bool BoardCompleted(const std::vector<std::shared_ptr<A_Shape>> &objective, const std::vector<std::shared_ptr<A_Shape>> &game);

    /*!
     * @brief Get all shape of the mObjective
     * @return Return a vector of shape of the mObjective
     */

    std::vector<std::shared_ptr<A_Shape>> GetObjective();

    /*!
     * @brief Set an C_Objective for a new game
     * @param objective : C_Objective to mUpdate
     * @param vec_objective :Vector of new A_Shape for the new C_Objective
     */

    static void SetObjective(std::shared_ptr<C_Objective> objective, const std::vector<std::shared_ptr<A_Shape>> &vec_objective);

    /*!
     * @brief Get the mColor of an C_Objective
     * @return Return the mColor of an C_Objective
     */

    MLV_Color GetColor();

    double GetCompleted(const std::vector<std::shared_ptr<A_Shape>> &objective, const std::vector<std::shared_ptr<A_Shape>> &game);
};


#endif //TANGRAM_OBJECTIVE_H
