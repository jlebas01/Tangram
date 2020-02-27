//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_SQUARE_H
#define TANGRAM_SQUARE_H

/*!
 * @file C_Square.hpp
 * @brief A_Shape of C_Square
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>

#include <shape/C_STriangle.hpp>
#include <drawable/A_Shape.hpp>
#include <MLV/MLV_shape.h>

/*!
 * @class C_Square
 * @brief Class of the square
 *
 * This class manage everything about the C_Square
 */

class C_Square : public A_Shape {

    /*!
     * @brief Class members
     */
private:

    std::vector<C_STriangle> mTriangles; /*!< C_Square is make by multiple triangles*/

    std::vector<T_Point<double>> mPoints; /*!< C_Square has multiple C_STriangle with multiple T_Point */

    bool mUpdate; /*!< Boolean if vector mPoints needs to be mUpdate */

    MLV_Color mColor; /*!< Color of the C_Square */

    /*!
     * @brief Class methods
     */

private:

    /*!
     * @brief __Parameter the constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : aRotate the figure with an angular
     */

    void __Parameter(const T_Point<double> &origin, double angular = 0.0);

    /*!
     * @brief Compute the center of this shape
     * @return Return a point which is the center of this shape
     */

    T_Point<double> __CenterShape();

public:

    /*!
     * @brief Destructor of C_Square
     */

    ~C_Square() override;

    /*!
     * @brief Constructor by default of C_Square, make a C_Square as default
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_Square(MLV_Color color = MLV_COLOR_PURPLE);

    /*!
     * @brief Constructor of C_Square, requires a vector of STriangles
     * @param triangle : The C_Square will created with a vector of C_STriangle (4)
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_Square(const std::vector<C_STriangle> &triangle, MLV_Color color = MLV_COLOR_PURPLE);

    /*!
     * @brief Constructor of C_Square, calls the deleguate Default Constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : Optional __Parameter (angular=0.0 as default), aRotate the figure with an angular
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_Square(const T_Point<double> &origin, double angular = 0.0, MLV_Color color = MLV_COLOR_PURPLE);

    /*!
     * @brief Move the C_Square by point translation
     * @param translation : Every mPoints of this shape will be translate by this __Parameter
     */

    void aMove(const T_Point<double> &translation) override;

    /*!
     * @brief Rotate the C_Square with specified angular
     * @param angular : This angular should be between (0, 2PI)
     */

    void aRotate(double angular) override;

    /*!
     * @brief Flip the figure as symmetry
     */

    void aFlip() override;

    /*!
     * @brief Draw this shape on IHM
     */

    void iDraw() override;

    void iDraw(MLV_Color color) override;

    /*!
     * @brief Check if a point is in this shape
     * @param click : T_Point to check
     * @return true if Click is in this shape, false if not
     */

    bool aIsInShape(const T_Point<double> &click) override;

    /*!
     * @brief Get mPoints of this shape
     * @return Return a vector of mPoints of this shape
     */

    std::vector<T_Point<double>> aGetPoints() override;

    bool aSetPoints(const T_Point<double> &ref, const T_Point<double> &changed) override;

    /*!
     * @brief Convert all data of C_Square in a string
     * @return Return a string which contains every mPoints of this shape
     */

    std::string aToString() override;

    double aCurrentAngular() override;

    T_Point<double> aLeftCorner() override;

    std::string aGetShape() override;

    MLV_Color aGetColor() override;

    double aGetArea() override;
};

#endif //TANGRAM_SQUARE_H
