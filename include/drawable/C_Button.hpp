//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_BUTTON_H
#define TANGRAM_BUTTON_H

/*!
 * @file C_Button.hpp
 * @brief Every mButtons of menu
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <utility>
#include <utils/T_Point.hpp>
#include <functional>
#include <MLV/MLV_color.h>

/*!
 * @class C_Button
 * @brief C_Button of the C_Menu
 *
 * This class manage all mButtons of the menu
 */

class C_Button {
private:

    /*!
     * @brief Class members
     */
    T_Point<int> mBPoint; /*!< Top left position of the button */
    T_Point<int> mBSizing; /*!< Sizing of the button */
    std::string mBText; /*!< Text of the button */
    std::function<int(int)> mBCallBack; /*!< function pointer of button callback */

public:

    /*!
     * @brief Class methods
     */

    /*!
     * @brief Destructor of the C_Button
     */

    ~C_Button();

    /*!
     * @brief Constructor of a C_Button
     * @param point : Top left point position of the button
     * @param sizing : Sizing of the button, (width , height)
     * @param text : Text of the button
     */

    C_Button(const T_Point<int> &point, const T_Point<int> &sizing, std::string text);

    /*!
     * @brief Constructor of a C_Button
     * @param point : Top left point position of the button
     * @param sizing : Sizing of the button, (width , height)
     * @param text : Text of the button
     * @param callback : Pointer of function for callback
     */

    C_Button(const T_Point<int> &point, const T_Point<int> &sizing, std::string text, std::function<int(int)> callback);

    /*!
     * @brief Check if a Click is in the button
     * @param click : T_Point to check
     * @return True if the Click is in this button, false if not
     */

    bool ClickInButton(const T_Point<int> &click);

    /*!
     * @brief Define a value about a Click
     * @return Return a value about a Click
     */

    int Click(int);

    /*!
     * @brief Draw the button
     */

    void Draw();

    /*!
     * @brief Draw the button with specific color
     * @param color : MLV_Color needed to draw the button
     */

    void Draw(MLV_Color color);

    /*!
     * @brief Set a callback for a button
     * @param callback : Requires a pointer of function for set the callback
     */

    void SetCallBack(std::function<int(int)> callback);
};


#endif //TANGRAM_BUTTON_H
