#ifndef TANGRAM_POINT_H
#define TANGRAM_POINT_H

#include <functional>
/*!
 * @file Point.hpp
 * @brief Point for every shape and menu
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

/*!
 * @class Point
 * @tparam T : Template parameter
 * @brief Class of a Point
 *
 * This class manage everything about a point
 */

template<typename T>
class Point {
public:
    T x; /*!< Template x for a point */
    T y; /*!< Template y for a point */

    /*!
     * @brief Constructor for a point with initialisation list
     */

    Point() : x(0), y(0) {}


    /*!
     * @brief Constructor for a point. Requires a X and a Y coordinate
     * @param _x : Template X coordinate
     * @param _y : Template Y coordinate
     */

    Point(const T _x, const T _y) {
        this->x = _x;
        this->y = _y;
    }

    /*!
     * @brief Operator = of a point
     * @param p : Point to "copy"
     * @return Return a reference to a point
     */

    Point &operator=(const Point<T> p) {
        this->x = p.x;
        this->y = p.y;
        return *this;
    }

    /*!
     * @brief Operator == of a point
     * @param p : Point to compare
     * @return Return True if the point is the same, false if not
     */

    bool operator==(const Point<T> p) const {
        return this->x == p.x && this->y == p.y;
    }

    /*!
     * @brief Operator != of a point
     * @param p : Point to compare
     * @return Return True if the point is different, false if not
     */

    bool operator!=(const Point<T> p) const {
        return this->x != p.x || this->y != p.y;
    }

    /*!
     * @brief Operator < of a point
     * @param p : Point to compare
     * @return Return True if the point is strictly weaker, false if not
     */

    bool operator<(const Point<T> p) const {
        return this->x < p.x && this->y < p.y;
    }

    /*!
     * @brief Operator > of a point
     * @param p : Point to comapre
     * @return Return True if the point is strictly greater, false if not
     */

    bool operator>(const Point<T> p) const {
        return this->x > p.x && this->y > p.y;
    }


    struct hash_point {
        std::size_t operator()(const Point<double> &p) const {
            return std::hash<double>()(p.x) ^ std::hash<double>()(p.y);
        }

        bool operator()(const Point<double> &p1, const Point<double> &p2) const {
            return p1.x == p2.x && p1.y == p2.y;
        }
    };
};


#endif
