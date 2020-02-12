//
// Created by jlebas01 on 31/01/2020.
//

#ifndef TANGRAM_DRAWABLE_H
#define TANGRAM_DRAWABLE_H

/*!
 * @file Drawable.hpp
 * @brief Interface of drawable in the game
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <MLV/MLV_color.h>

/*!
 * @class Drawable
 * @brief Drawable is everything to draw
 *
 * This class manage everything drawing
 */

class Drawable {
public :

    /*!
     * @brief Pure virtual function. Draw everything which needs to be draw
     */
    ~Drawable() = default;
    virtual void draw() = 0;
    virtual void draw(MLV_Color color) = 0;
};


#endif //TANGRAM_DRAWABLE_H
