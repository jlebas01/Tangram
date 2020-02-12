//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_STRIANGLE_H
#define TANGRAM_STRIANGLE_H

/*!
 * @file STriangle.hpp
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

    MLV_Color color; /*!< Color of the STriangle */

    /*!
     * @brief Parameter the constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : rotate the figure with an angular
     */

    void parameter(const Point<double> &origin, double angular = 0.0);

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

    double sign(const Point<double> &p1, const Point<double> &p2, const Point<double> &p3);

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
     * @param color : Optional parameter, color of this shape
     */

    explicit STriangle(MLV_Color color = MLV_COLOR_GREEN);

    /*!
     * @brief Constructor of STriangle, requires 3 points
     * @param p1 : First point of the STriangle
     * @param p2 : Second point of the STriangle
     * @param p3 : Third point of the STriangle
     * @param color : Optional parameter, color of this shape
     */

    STriangle(const Point<double> &p1, const Point<double> &p2, const Point<double> &p3,
              MLV_Color color = MLV_COLOR_GREEN);

    /*!
     * @brief Constructor of STriangle, requires a vector of 3 points
     * @param points : vector of 3 points
     * @param color : Optional parameter, color of this shape
     */

    explicit STriangle(const std::vector<Point<double>> &points, MLV_Color color = MLV_COLOR_GREEN);

    /*!
     * @brief Constructor of STriangle, calls the deleguate Default Constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : Optional parameter (angular=0.0 as default), rotate the figure with an angular
     * @param color : Optional parameter, color of this shape
     */

    explicit STriangle(const Point<double> &origin, double angular = 0.0, MLV_Color color = MLV_COLOR_GREEN);

    /*!
     * @brief Move the MTriangle by point translation
     * @param translation : Every points of this shape will be translate by this parameter
     */

    void move(const Point<double> &translation) override;

    /*!
     * @brief Rotate an STriangle with specified angular, used only for an other shape
     * @param angular : This angular should be between (0, 2PI)
     * @param center_point : Rotate an STriangle around this point
     */

    void rotate(double angular, const Point<double> &center_point);

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

    void draw(MLV_Color color) override;

    /*!
    * @brief Check if a point is in this shape
    * @param click : Point to check
    * @return true if click is in this shape, false if not
    */

    bool is_in_shape(const Point<double> &click) override;

    /*!
     * @brief Check if a point is in this STriangle
     * @param click : Point to check
     * @return true if click is in this shape, false if not
     */

    bool is_in_triangle(const Point<double> &click);

    /*!
     * @brief Convert all data of MTriangle in a string
     * @return Return a string which contains every points of this shape
     */

    std::string toString() override;

    /*!
     * @brief Get every points of this STriangle
     * @return Return a vector of these points
     */

    std::vector<Point<double>> get_Points() override;

    bool set_Points(const Point<double> &ref, const Point<double> &changed) override;

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
