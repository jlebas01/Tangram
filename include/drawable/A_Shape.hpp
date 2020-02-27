//
// Created by jlebas01 on 15/01/2020.
//
#ifndef TANGRAM_SHAPE_H
#define TANGRAM_SHAPE_H

/*!
 * @file A_Shape.hpp
 * @brief Abstract Class A_Shape of every shape in Tangram
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>
#include <string>
#include <cmath>
#include <utils/T_Point.hpp>
#include <drawable/I_Drawable.h>

/*!
 * @class A_Shape
 * @brief Abstract Class of every A_Shape
 *
 * This class manage everything other shape (C_STriangle, C_MTriangle, C_GTriangle, C_Square, C_Parallelogram)
 */

class A_Shape : public I_Drawable {
public :

    /*!
     * @brief Destructor of Abstract A_Shape
     */

    virtual ~A_Shape() = 0;

    /*!
     * @brief Compute distance between 2 mPoints
     * @param point1 : First point
     * @param point2 : Second point
     * @return Return the distance between these two mPoints
     */

    static double computeDistance(const T_Point<double> &point1, const T_Point<double> &point2) {
        return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
    }

    /*!
     * @brief Pure virtual function. Move the A_Shape by point translation
     * @param translation : Every mPoints of this shape will be translate by this __Parameter
     */

    virtual void aMove(const T_Point<double> &translation) = 0;

    /*!
     * @brief Pure virtual function. Rotate the C_GTriangle with specified angular
     * @param angular : This angular should be between (0, 2PI)
     */

    virtual void aRotate(double angular) = 0;

    /*!
     * @brief Pure virtual function. Flip the figure as symmetry
     */

    virtual void aFlip() = 0;

    /*!
     * @brief Pure virtual function. Check if a point is in this shape
     * @param point : T_Point to check
     * @return true if Click is in this shape, false if not
     */

    virtual bool aIsInShape(const T_Point<double> &point) = 0;

    /*!
     * @brief Pure virtual function. Get all mPoints of this shape
     * @return Return a vector of mPoints of this shape
     */

    virtual std::vector<T_Point<double>> aGetPoints() = 0;

    /*!
     * @brief Pure virtual function. Get all mPoints of this shape
     * @return Return a vector of mPoints of this shape
     */

    virtual bool aSetPoints(const T_Point<double> &ref, const T_Point<double> &changed) = 0;

    /*!
     * @brief Pure virtual function. Convert all data of C_GTriangle in a string
     * @return Return a string which contains every mPoints of this shape
     */

    virtual std::string aToString() = 0;

    virtual double aCurrentAngular() = 0;

    virtual T_Point<double> aLeftCorner() = 0;

    virtual std::string aGetShape() = 0;

    virtual MLV_Color aGetColor() = 0;

    virtual double aGetArea() = 0;
};

#endif //TANGRAM_SHAPE_H
