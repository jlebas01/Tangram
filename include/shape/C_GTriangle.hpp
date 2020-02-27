//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_GTRIANGLE_H
#define TANGRAM_GTRIANGLE_H

/*!
 * @file C_GTriangle.hpp
 * @brief A_Shape of Great Triangle
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>

#include <shape/C_STriangle.hpp>
#include <drawable/A_Shape.hpp>
#include <MLV/MLV_shape.h>

/*!
 * @class C_GTriangle
 * @brief Class of the greatest mTriangles
 *
 * This class manage everything about the greatest mTriangles
 */

class C_GTriangle : public A_Shape {
    /*!
     * @brief Class members
     */
private:

    std::vector<C_STriangle> mTriangles; /*!< C_GTriangle is make by multiple triangles*/

    std::vector<T_Point<double>> mPoints; /*!< C_GTriangle has multiple C_STriangle with multiple T_Point */

    bool mUpdate; /*!< Boolean if vector mPoints needs to be mUpdate */

    MLV_Color mColor; /*!< Color of the C_GTriangle */

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
     * @brief Destructor of C_GTriangle
     */

    ~C_GTriangle() override;

    /*!
     * @brief Constructor by default of C_GTriangle, make a C_GTriangle as default
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_GTriangle(MLV_Color color = MLV_COLOR_RED);

    /*!
     * @brief Constructor of C_GTriangle, requires a vector of triangles
     * @param triangle : The C_GTriangle will created with a vector of C_STriangle (4)
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_GTriangle(const std::vector<C_STriangle> &triangle, MLV_Color color = MLV_COLOR_RED);

    /*!
     * @brief Constructor of C_GTriangle, calls the deleguate Default Constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : Optional __Parameter (angular=0.0 as default), aRotate the figure with an angular
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_GTriangle(const T_Point<double> &origin, double angular = 0.0, MLV_Color color = MLV_COLOR_RED);

    /*!
     * @brief Move the C_GTriangle by point translation
     * @param translation : Every mPoints of this shape will be translate by this __Parameter
     */

    void aMove(const T_Point<double> &translation) override;

    /*!
     * @brief Rotate the C_GTriangle with specified angular
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

    /*!
     * @brief Draw this shape on IHM with a specific mColor
     * @param color: Color used to __Draw the shape
     */


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

    /*!
     * @brief Set mPoints of this shape
     * @return Return a true if something has been changed, false either
     */

    bool aSetPoints(const T_Point<double> &ref, const T_Point<double> &changed) override;

    /*!
     * @brief Convert all data of C_GTriangle in a string
     * @return Return a string which contains every mPoints of this shape
     */

    std::string aToString() override;

    double aCurrentAngular() override;

    T_Point<double> aLeftCorner() override;

    std::string aGetShape() override;

    MLV_Color aGetColor() override;

    double aGetArea() override;
};

#endif //TANGRAM_GTRIANGLE_H
