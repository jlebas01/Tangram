//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_BUTTON_H
#define TANGRAM_BUTTON_H

/*!
 * @file Button.hpp
 * @brief Every buttons of menu
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <utility>
#include <utils/Point.hpp>
#include <functional>
#include <MLV/MLV_color.h>

/*!
 * @class Button
 * @brief Button of the Menu
 *
 * This class manage all buttons of the menu
 */

class Button {
private:
    Point<int> b_point; /*!< Top left position of the button */
    Point<int> b_sizing; /*!< Sizing of the button */
    std::string b_text; /*!< Text of the button */
    std::function<int(int)> b_callback; /*!< function pointer of button callback */

public:

    /*!
     * @brief Destructor of the Button
     */

    ~Button();

    /*!
     * @brief Constructor of a Button
     * @param point : Top left point position of the button
     * @param sizing : Sizing of the button, (width , height)
     * @param text : Text of the button
     */

    Button(const Point<int> &point, const Point<int> &sizing, std::string text);

    /*!
     * @brief Constructor of a Button
     * @param point : Top left point position of the button
     * @param sizing : Sizing of the button, (width , height)
     * @param text : Text of the button
     * @param callback : Pointer of function for callback
     */

    Button(const Point<int> &point, const Point<int> &sizing, std::string text, std::function<int(int)> callback);

    /*!
     * @brief Check if a click is in the button
     * @param click : Point to check
     * @return True if the click is in this button, false if not
     */

    bool click_in_button(const Point<int> &click);

    /*!
     * @brief Define a value about a click
     * @return Return a value about a click
     */

    int click(int);

    /*!
     * @brief Draw the button
     */

    void draw();

    void draw(MLV_Color color);

    /*!
     * @brief Set a callback for a button
     * @param callback : Requires a pointer of function for set the callback
     */

    void set_callback(std::function<int(int)> callback);
};


#endif //TANGRAM_BUTTON_H
