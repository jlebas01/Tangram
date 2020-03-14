//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MENU_H
#define TANGRAM_MENU_H

/*!
 * @file C_Menu.hpp
 * @brief C_Menu of the Tangram's C_Game
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <drawable/C_Button.hpp>
#include <vector>

/*!
 * @class C_Menu
 * @brief C_Menu of the game
 *
 * This class manage everything about Tangram's menu
 */

class C_Menu {
private:

    /*!
     * @brief Class members
     */

    std::vector<C_Button> mButtons; /*!< C_Menu requires a vector of mButtons to iDraw */

private:

    /*!
     * @brief Class methods
     */

    /*!
     * @brief Draw the menu
     */

    void __Draw();

public:

    ~C_Menu();

    /*!
     * @brief Add a button in the C_Menu
     * @param button : C_Button to add
     */

    void AddButton(const C_Button &button);

    /*!
     * @brief Main loop of the C_Menu
     */

    void MainLoop();
};


#endif //TANGRAM_MENU_H
