//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_STRIANGLE_H
#define TANGRAM_STRIANGLE_H

/*!
 * @file MTriangle.hpp
 * @brief Shape of Small Triangle
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>

#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

/*!
 * @class STriangle
 * @brief Class of the small triangle
 *
 * This class manage everything about the small triangle
 */

class STriangle : public Shape {
private:

    std::vector<Point<double>> points; /*!< STriangle is make by multiple points*/

    Point<double> center; /*!< STriangle has a center point*/

    /*!
     * @brief Parameter the constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : rotate the figure with an angular
     */

    void parameter(Point<double> origin, double angular);

    /*!
     * @brief Compute the center point only for the STriangle
     * @return Return the center point of a STriangle
     */

    Point<double> center_point();

    /*!
     * @brief Compute the sign about a two reference point and another point, used by is_in_triangle()
     * @param p1 : Another point
     * @param p2 : 1th point reference
     * @param p3 : 2nd point reference
     * @return Return a double signed (+ or -)
     */

    double sign(Point<double> p1, Point<double> p2, Point<double> p3);

    /*!
     * @brief Rotate the STriangle with specified angular
     * @param angular : This angular should be between (0, 2PI)
     */

    void rotate(double angular) override;

public:

    /*!
     * @brief Destructor of STriangle
     */

    ~STriangle() override;

    /*!
     * @brief Constructor by default of MTriangle, make a STriangle as default
     */

    STriangle();

    /*!
     * @brief Constructor of STriangle, requires 3 points
     * @param p1 : First point of the STriangle
     * @param p2 : Second point of the STriangle
     * @param p3 : Third point of the STriangle
     */

    STriangle(Point<double> p1, Point<double> p2, Point<double> p3);

    /*!
     * @brief Constructor of STriangle, requires a vector of 3 points
     * @param points : vector of 3 points
     */

    explicit STriangle(const std::vector<Point<double>> &points);

    /*!
     * @brief Constructor of STriangle, calls the deleguate Default Constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : Optional parameter (angular=0.0 as default), rotate the figure with an angular
     */

    explicit STriangle(Point<double> origin, double angular = 0.0);

    /*!
     * @brief Move the MTriangle by point translation
     * @param translation : Every points of this shape will be translate by this parameter
     */

    void move(Point<double> translation) override;

    /*!
     * @brief Rotate an STriangle with specified angular, used only for an other shape
     * @param angular : This angular should be between (0, 2PI)
     * @param center_point : Rotate an STriangle around this point
     */

    void rotate(double angular, Point<double> center_point);

    /*!
     * @brief Flip the figure as symmetry
     */

    void flip() override;

    /*!
     * @brief Draw this shape on IHM
     */

    void draw() override;

    /*!
     * @brief Draw this shape on IHM with specific color
     * @param Color : Color from the graphic library MLV like MLV_COLOR_XXX
     */

    void draw(MLV_Color Color);

    /*!
    * @brief Check if a point is in this shape
    * @param click : Point to check
    * @return true if click is in this shape, false if not
    */

    bool is_in_shape(Point<double> click) override;

    /*!
     * @brief Check if a point is in this STriangle
     * @param click : Point to check
     * @return true if click is in this shape, false if not
     */

    bool is_in_triangle(Point<double> click);

    /*!
     * @brief Convert all data of MTriangle in a string
     * @return Return a string which contains every points of this shape
     */

    std::string toString() override;

    /*!
     * @brief Compute distance between 2 points
     * @param point1 : First point
     * @param point2 : Second point
     * @return Return the distance between these two points
     */

    double computeDistance(Point<double> point1, Point<double> point2);

    /*!
     * @brief Get every points of this STriangle
     * @return Return a vector of these points
     */

    std::vector<Point<double>> get_Points() override;

    /*!
     * @brief Compute the center point of N points
     * @param list_points : vector of N points
     * @return Return the center point of these N points
     */

    static Point<double> center_point(const std::vector<Point<double>> &list_points);

    /*!
     * @brief Get the current center point of this STriangle
     * @return Return the current center point of this STriangle
     */

    Point<double> get_center_point();
};

#endif //TANGRAM_STRIANGLE_H
