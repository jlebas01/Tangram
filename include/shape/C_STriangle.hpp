//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_STRIANGLE_H
#define TANGRAM_STRIANGLE_H

/*!
 * @file C_STriangle.hpp
 * @brief A_Shape of Small Triangle
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>

#include <drawable/A_Shape.hpp>
#include <MLV/MLV_shape.h>

/*!
 * @class C_STriangle
 * @brief Class of the small mTriangles
 *
 * This class manage everything about the small mTriangles
 */

class C_STriangle : public A_Shape {
/*!
 * @brief Class members
 */

private:

    std::vector<T_Point<double>> mPoints; /*!< C_STriangle is make by multiple mPoints*/

    std::vector<T_Point<double>> mFlip; /*! C_STriangle needs a vector of initial mPoints to flip*/

    T_Point<double> mCenter; /*!< C_STriangle has a center point*/

    MLV_Color mColor; /*!< Color of the C_STriangle */

    double mAngularShape; /*!< Current angular of the C_STriangle */

    T_Point<double> mTranslateShape; /*!< Current translation of the C_STriangle about origin*/

    double mFlipAngular; /*! Stores the last angular value flip */

    T_Point<double> mFlipTranslate; /*! Stores the last translate value flip */

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
     * @brief Compute the center point only for the C_STriangle
     * @return Return the center point of a C_STriangle
     */

    T_Point<double> __CenterPoint();

    /*!
     * @brief Compute the __Sign about a two reference point and another point, used by IsInSTriangle()
     * @param p1 : Another point
     * @param p2 : 1th point reference
     * @param p3 : 2nd point reference
     * @return Return a double signed (+ or -)
     */

    double __Sign(const T_Point<double> &p1, const T_Point<double> &p2, const T_Point<double> &p3);

public:
    /*!
     * @brief Destructor of C_STriangle
     */

    ~C_STriangle() override;

    /*!
     * @brief Constructor by default of C_MTriangle, make a C_STriangle as default
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_STriangle(MLV_Color color = MLV_COLOR_GREEN);

    /*!
     * @brief Constructor of C_STriangle, requires 3 mPoints
     * @param p1 : First point of the C_STriangle
     * @param p2 : Second point of the C_STriangle
     * @param p3 : Third point of the C_STriangle
     * @param color : Optional __Parameter, mColor of this shape
     */

    C_STriangle(const T_Point<double> &p1, const T_Point<double> &p2, const T_Point<double> &p3,
                MLV_Color color = MLV_COLOR_GREEN);

    /*!
     * @brief Constructor of C_STriangle, requires a vector of 3 mPoints
     * @param points : vector of 3 mPoints
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_STriangle(const std::vector<T_Point<double>> &points, MLV_Color color = MLV_COLOR_GREEN);

    /*!
     * @brief Constructor of C_STriangle, calls the deleguate Default Constructor
     * @param origin : shifts the figure of a translation of the origin
     * @param angular : Optional __Parameter (angular=0.0 as default), aRotate the figure with an angular
     * @param color : Optional __Parameter, mColor of this shape
     */

    explicit C_STriangle(const T_Point<double> &origin, double angular = 0.0, MLV_Color color = MLV_COLOR_GREEN);

    /*!
     * @brief Move the C_MTriangle by point translation
     * @param translation : Every mPoints of this shape will be translate by this __Parameter
     */

    void aMove(const T_Point<double> &translation) override;

    /*!
     * @brief Rotate the C_STriangle with specified angular
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
     * @brief Draw this shape on IHM with specific mColor
     * @param Color : Color from the graphic library MLV like MLV_COLOR_XXX
     */

    void iDraw(MLV_Color color) override;

    /*!
    * @brief Check if a point is in this shape
    * @param click : T_Point to check
    * @return true if Click is in this shape, false if not
    */

    bool aIsInShape(const T_Point<double> &click) override;

    /*!
     * @brief Check if a point is in this C_STriangle
     * @param click : T_Point to check
     * @return true if Click is in this shape, false if not
     */

    bool IsInSTriangle(const T_Point<double> &click);

    /*!
     * @brief Convert all data of C_MTriangle in a string
     * @return Return a string which contains every mPoints of this shape
     */

    std::string aToString() override;

    /*!
     * @brief Get every mPoints of this C_STriangle
     * @return Return a vector of these mPoints
     */

    std::vector<T_Point<double>> aGetPoints() override;

    bool aSetPoints(const T_Point<double> &ref, const T_Point<double> &changed) override;

    /*!
     * @brief Get the current center point of this C_STriangle
     * @return Return the current center point of this C_STriangle
     */

    T_Point<double> GetCenterPoint();

    double aCurrentAngular() override;

    T_Point<double> aLeftCorner() override;

    std::string aGetShape() override;

    MLV_Color aGetColor() override;

    /*!
     * @brief Compute the center point of N mPoints
     * @param list_points : vector of N mPoints
     * @return Return the center point of these N mPoints
     */

    static T_Point<double> CenterPoint(const std::vector<T_Point<double>> &list_points);

    /*!
     * @brief Rotate an C_STriangle with specified angular, used only for an other shape
     * @param angular : This angular should be between (0, 2PI)
     * @param center_point : Rotate an C_STriangle around this point
     */

    void Rotate(double angular, const T_Point<double> &center_point);

    void Flip(const T_Point<double> &centerPoint);

    double aGetArea() override;

    std::vector<T_Point<double>> GetFlip();
};

#endif //TANGRAM_STRIANGLE_H
