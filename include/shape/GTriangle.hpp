//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GTRIANGLE_H
#define TANGRAM_GTRIANGLE_H

/*!
 * @file GTriangle.hpp
 * @brief Shape of Great Triangle
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

/*!
 * @class GTriangle
 * @brief Class of the greatest triangle
 *
 * This class manage everything about the greatest triangle
 */

class GTriangle : public Shape {
private:

    std::vector<STriangle> triangle; /*!< GTriangle is make by multiple triangles*/

    MLV_Color color; /*!< Color of the GTriangle */

    /*!
     * @brief Parameter the constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : rotate the figure with an angular
     */

    void parameter(const Point<double> &origin, double angular = 0.0);

    /*!
     * @brief Compute the center of this shape
     * @return Return a point which is the center of this shape
     */

    Point<double> center_shape();

public:

    /*!
     * @brief Destructor of GTriangle
     */

    ~GTriangle() override;

    /*!
     * @brief Constructor by default of GTriangle, make a triangle as default
     */

    explicit GTriangle(MLV_Color color = MLV_COLOR_RED);

    /*!
     * @brief Constructor of GTriangle, requires a vector of triangles
     * @param triangle : The GTriangle will created with a vector of STriangle (4)
     */

    explicit GTriangle(const std::vector<STriangle> &triangle, MLV_Color color = MLV_COLOR_RED);

    /*!
     * @brief Constructor of GTriangle, calls the deleguate Default Constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : Optional parameter (angular=0.0 as default), rotate the figure with an angular
     */

    explicit GTriangle(const Point<double> &origin, double angular = 0.0, MLV_Color color = MLV_COLOR_RED);

    /*!
     * @brief Move the GTriangle by point translation
     * @param translation : Every points of this shape will be translate by this parameter
     */

    void move(const Point<double> &translation) override;

    /*!
     * @brief Rotate the GTriangle with specified angular
     * @param angular : This angular should be between (0, 2PI)
     */

    void rotate(double angular) override;

    /*!
     * @brief Flip the figure as symmetry
     */

    void flip() override;

    /*!
     * @brief Draw this shape on IHM
     */

    void draw() override;

    /*!
     * @brief Check if a point is in this shape
     * @param click : Point to check
     * @return true if click is in this shape, false if not
     */

    bool is_in_shape(const Point<double> &click) override;

    /*!
     * @brief Get points of this shape
     * @return Return a vector of points of this shape
     */

    std::vector<Point<double>> get_Points() override;

    /*!
     * @brief Convert all data of GTriangle in a string
     * @return Return a string which contains every points of this shape
     */

    std::string toString() override;
};

#endif //TANGRAM_GTRIANGLE_H
