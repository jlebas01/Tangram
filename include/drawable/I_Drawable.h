//
// Created by jlebas01 on 31/01/2020.
//

#ifndef TANGRAM_I_DRAWABLE_H
#define TANGRAM_I_DRAWABLE_H

/*!
 * @file I_Drawable.hpp
 * @brief Interface of drawable in the game
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <MLV/MLV_color.h>

/*!
 * @class I_Drawable
 * @brief I_Drawable is everything to iDraw
 *
 * This class manage everything drawing
 */

class I_Drawable {
public :

    /*!
     * @brief Pure virtual function. Draw everything which needs to be iDraw
     */
    ~I_Drawable() = default;
    virtual void iDraw() = 0;
    virtual void iDraw(MLV_Color color) = 0;
};


#endif //TANGRAM_I_DRAWABLE_H
