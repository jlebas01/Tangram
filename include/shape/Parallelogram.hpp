//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_PARALELLOGRAM_H
#define TANGRAM_PARALELLOGRAM_H

/*!
 * @file Parallelogram.hpp
 * @brief Shape of Parallelogram
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

/*!
 * @class Parallelogram
 * @brief Class of the parallelogram
 *
 * This class manage everything about the Parallelogram
 */

class Parallelogram : public Shape {
private:

    std::vector<STriangle> triangle; /*!< Parallelogram is make by multiple triangles*/

    std::vector<Point<double>> points; /*!< Parallelogram has multiple STriangle with multiple Point */

    bool update; /*!< Boolean if vector points needs to be update */

    MLV_Color color; /*!< Color of the Parallelogram */

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
     * @brief Destructor of Parallelogram
     */

    ~Parallelogram() override;

    /*!
     * @brief Constructor by default of Parallelogram, make a Parallelogram as default
     * @param color : Optional parameter, color of this shape
     */

    explicit Parallelogram(MLV_Color color = MLV_COLOR_BLUE);

    /*!
     * @brief Constructor of Parallelogram, requires a vector of STriangles
     * @param triangle : The Parallelogram will created with a vector of STriangle (4)
     * @param color : Optional parameter, color of this shape
     */

    explicit Parallelogram(const std::vector<STriangle> &triangle, MLV_Color color = MLV_COLOR_BLUE);

    /*!
     * @brief Constructor of Parallelogram, calls the deleguate Default Constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : Optional parameter (angular=0.0 as default), rotate the figure with an angular
     * @param color : Optional parameter, color of this shape
     */

    explicit Parallelogram(const Point<double> &origin, double angular = 0.0, MLV_Color color = MLV_COLOR_BLUE);

    /*!
     * @brief Move the Parallelogram by point translation
     * @param translation : Every points of this shape will be translate by this parameter
     */

    void move(const Point<double> &translation) override;

    /*!
     * @brief Rotate the Parallelogram with specified angular
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

    bool set_Points(const Point<double> &ref, const Point<double> &changed) override;

    /*!
     * @brief Convert all data of Parallelogram in a string
     * @return Return a string which contains every points of this shape
     */

    std::string toString() override;
};

#endif //TANGRAM_PARALELLOGRAM_H
