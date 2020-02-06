//
// Created by jlebas01 on 15/01/2020.
//
#ifndef TANGRAM_SHAPE_H
#define TANGRAM_SHAPE_H

/*!
 * @file Shape.hpp
 * @brief Abstract Class Shape of every shape in Tangram
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>
#include <string>
#include <cmath>
#include <utils/Point.hpp>
#include <drawable/Drawable.h>

/*!
 * @class Shape
 * @brief Abstract Class of every Shape
 *
 * This class manage everything other shape (STriangle, MTriangle, GTriangle, Square, Parallelogram)
 */

class Shape : public Drawable {
public :

    /*!
     * @brief Destructor of Abstract Shape
     */

    virtual ~Shape() = 0;

    /*!
     * @brief Compute distance between 2 points
     * @param point1 : First point
     * @param point2 : Second point
     * @return Return the distance between these two points
     */

    static double computeDistance(const Point<double> &point1, const Point<double> &point2) {
        return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
    }

    /*!
     * @brief Pure virtual function. Move the Shape by point translation
     * @param translation : Every points of this shape will be translate by this parameter
     */

    virtual void move(const Point<double> &translation) = 0;

    /*!
     * @brief Pure virtual function. Rotate the GTriangle with specified angular
     * @param angular : This angular should be between (0, 2PI)
     */

    virtual void rotate(double angular) = 0;

    /*!
     * @brief Pure virtual function. Flip the figure as symmetry
     */

    virtual void flip() = 0;

    /*!
     * @brief Pure virtual function. Check if a point is in this shape
     * @param point : Point to check
     * @return true if click is in this shape, false if not
     */

    virtual bool is_in_shape(const Point<double> &point) = 0;

    /*!
     * @brief Pure virtual function. Get all points of this shape
     * @return Return a vector of points of this shape
     */

    virtual std::vector<Point<double>> get_Points() = 0;

    /*!
     * @brief Pure virtual function. Get all points of this shape
     * @return Return a vector of points of this shape
     */

    virtual bool set_Points(const Point<double> &ref, const Point<double> &changed) = 0;

    /*!
     * @brief Pure virtual function. Convert all data of GTriangle in a string
     * @return Return a string which contains every points of this shape
     */

    virtual std::string toString() = 0;
};

#endif //TANGRAM_SHAPE_H
