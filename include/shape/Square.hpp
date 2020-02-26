//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SQUARE_H
#define TANGRAM_SQUARE_H

/*!
 * @file Square.hpp
 * @brief Shape of Square
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

/*!
 * @class Square
 * @brief Class of the square
 *
 * This class manage everything about the Square
 */

class Square : public Shape {
private:

    std::vector<STriangle> triangle; /*!< Square is make by multiple triangles*/

    std::vector<Point<double>> points; /*!< Square has multiple STriangle with multiple Point */

    bool update; /*!< Boolean if vector points needs to be update */

    MLV_Color color; /*!< Color of the Square */

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
     * @brief Destructor of Square
     */

    ~Square() override;

    /*!
     * @brief Constructor by default of Square, make a Square as default
     * @param color : Optional parameter, color of this shape
     */

    explicit Square(MLV_Color color = MLV_COLOR_PURPLE);

    /*!
     * @brief Constructor of Square, requires a vector of STriangles
     * @param triangle : The Square will created with a vector of STriangle (4)
     * @param color : Optional parameter, color of this shape
     */

    explicit Square(const std::vector<STriangle> &triangle, MLV_Color color = MLV_COLOR_PURPLE);

    /*!
     * @brief Constructor of Square, calls the deleguate Default Constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : Optional parameter (angular=0.0 as default), rotate the figure with an angular
     * @param color : Optional parameter, color of this shape
     */

    explicit Square(const Point<double> &origin, double angular = 0.0, MLV_Color color = MLV_COLOR_PURPLE);

    /*!
     * @brief Move the Square by point translation
     * @param translation : Every points of this shape will be translate by this parameter
     */

    void move(const Point<double> &translation) override;

    /*!
     * @brief Rotate the Square with specified angular
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

    void draw(MLV_Color color) override;

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

    bool set_Points(const Point<double> &ref, const Point<double> &changed) override;

    /*!
     * @brief Convert all data of Square in a string
     * @return Return a string which contains every points of this shape
     */

    std::string toString() override;

    double current_angular() override;

    Point<double> leftCorner() override;

    std::string shape() override;
};

#endif //TANGRAM_SQUARE_H
