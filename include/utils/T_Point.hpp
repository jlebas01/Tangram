#ifndef TANGRAM_POINT_H
#define TANGRAM_POINT_H

#include <functional>
#include <utility>
#include <cmath>
/*!
 * @file T_Point.hpp
 * @brief T_Point for every shape and menu
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

/*!
 * @class T_Point
 * @tparam T : Template parameter
 * @brief Class of a T_Point
 *
 * This class manage everything about a point
 */

template<typename T>
class T_Point {
public:
    T x; /*!< Template x for a point */
    T y; /*!< Template y for a point */

    constexpr T_Point(const T_Point<T> &p) = default;

    /*!
     * @brief Constructor for a point with initialisation list
     */

    T_Point() : x(0), y(0) {}

    /*!
     * @brief Constructor of a point with move semantic
     * @param p : Point to move
     */

    T_Point(const T_Point<T> &&p) noexcept {
        this->x = std::move(p.x);
        this->y = std::move(p.y);
    }


    /*!
     * @brief Constructor for a point. Requires a X and a Y coordinate
     * @param _x : Template X coordinate
     * @param _y : Template Y coordinate
     */

    T_Point(const T &_x, const T &_y) {
        this->x = _x;
        this->y = _y;
    }

    /*!
     * @brief Operator = of a point
     * @param p : T_Point to "copy"
     * @return Return a reference to an atomic point
     */

    T_Point &operator=(const T_Point<T> &p) {
        this->x = p.x;
        this->y = p.y;
        return *this;
    }

    /*!
     * @brief Operator +=
     * @param p : Point
     * @return Return the behavior when a point is affected and add by another one
     */

    T_Point &operator+=(const T_Point<T> &p) {
        this->x += p.x;
        this->y += p.y;
        return *this;
    }

    /*!
     * @brief Operator +
     * @param p : Point
     * @return Return the behavior when a point is add by another one
     */

    T_Point operator+(const T_Point<T> &p) {
        const T_Point<T> res({this->x + p.x, this->y + p.y});
        return res;
    }

    /*!
     * @brief Operator -=
     * @param p : Point
     * @return Return the behavior when a point is affected and subtract by another one
     */

    T_Point &operator-=(const T_Point<T> &p) {
        this->x -= p.x;
        this->y -= p.y;
        return *this;
    }

    /*!
     * @brief Operator -
     * @param p : Point
     * @return Return the behavior when a point is subtract by another one
     */

    T_Point operator-(const T_Point<T> &p) {
        const T_Point<T> res({this->x - p.x, this->y - p.y});
        return res;
    }


    /*!
     * @brief Operator == of a point
     * @param p : T_Point to compare
     * @return Return True if the point is the same, false if not
     */



    bool operator==(const T_Point<T> &p) const {
        return this->x == p.x && this->y == p.y;
    }


    /*!
     * @brief Operator != of a point
     * @param p : T_Point to compare
     * @return Return True if the point is different, false if not
     */

    bool operator!=(const T_Point<T> &p) const {
        return this->x != p.x || this->y != p.y;
    }

    /*!
     * @brief Operator < of a point
     * @param p : T_Point to compare
     * @return Return True if the point is strictly weaker, false if not
     */

    bool operator<(const T_Point<T> &p) const {
        return this->x < p.x && this->y < p.y;
    }

    /*!
     * @brief Operator > of a point
     * @param p : T_Point to comapre
     * @return Return True if the point is strictly greater, false if not
     */

    bool operator>(const T_Point<T> &p) const {
        return this->x > p.x && this->y > p.y;
    }


    /*!
     * @brief Hash a T_Point<T>
     * @struct Struct which allows to hash a point with T_Point<T>
     */


    struct hash_point {

        /*!
         * @brief Operator to hash a point
         * @param p : point to hash
         * @return Return the hash of the point
         */

        std::size_t operator()(const T_Point<T> &p) const {
            return std::hash<T>()(p.x) ^ std::hash<T>()(p.y);
        }

        /*!
         * @brief Operator equal need to hash a point
         * @param p1 : Point 1
         * @param p2 : Point 2
         * @return Return true if p1 and p2 are equals, false otherwise
         */

        bool operator()(const T_Point<T> &p1, const T_Point<T> &p2) const {
            return p1.x == p2.x && p1.y == p2.y;
        }
    };

    ~T_Point() = default;
};

#endif
