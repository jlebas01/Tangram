//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MENU_H
#define TANGRAM_MENU_H

/*!
 * @file Menu.hpp
 * @brief Menu of the Tangram's Game
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <drawable/Button.hpp>
#include <vector>

/*!
 * @class Menu
 * @brief Menu of the game
 *
 * This class manage everything about Tangram's menu
 */

class Menu {
private:
    std::vector<Button> buttons; /*!< Menu requires a vector of buttons to draw */

    /*!
     * @brief Draw the menu
     */

    void draw();

public:

    /*!
     * @brief Add a button in the Menu
     * @param button : Button to add
     */

    void add_button(Button button);

    /*!
     * @brief Main loop of the Menu
     */

    void main_loop();
};


#endif //TANGRAM_MENU_H
