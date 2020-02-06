//
// Created by jlebas01 on 15/01/2020.
//

#ifndef TANGRAM_MTRIANGLE_H
#define TANGRAM_MTRIANGLE_H

/*!
 * @file MTriangle.hpp
 * @brief Shape of Medium Triangle
 * @author Jérémie LE BASTARD
 * @version 1.0
 */

#include <vector>

#include <shape/STriangle.hpp>
#include <drawable/Shape.hpp>
#include <MLV/MLV_shape.h>

/*!
 * @class MTriangle
 * @brief Class of the medium triangle
 *
 * This class manage everything about the medium triangle
 */

class MTriangle : public Shape {
    private:

        std::vector<STriangle> triangle; /*!< MTriangle is make by multiple triangles*/

        MLV_Color color; /*!< Color of the MTriangle */

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
         * @brief Destructor of MTriangle
         */

        ~MTriangle() override;

        /*!
         * @brief Constructor by default of MTriangle, make a MTriangle as default
         * @param color : Optional parameter, color of this shape
         */

        explicit MTriangle(MLV_Color color = MLV_COLOR_ORANGE);

        /*!
         * @brief Constructor of MTriangle, requires a vector of STriangles
         * @param triangle : The MTriangle will created with a vector of STriangle (4)
         * @param color : Optional parameter, color of this shape
         */

        explicit MTriangle(const std::vector<STriangle> &triangle, MLV_Color color = MLV_COLOR_ORANGE);

        /*!
         * @brief Constructor of MTriangle, calls the deleguate Default Constructor
         * @param origin : shifts the figure of a translation of the origin
         * @param angular : Optional parameter (angular=0.0 as default), rotate the figure with an angular
         * @param color : Optional parameter, color of this shape
         */

        explicit MTriangle(const Point<double> &origin, double angular = 0.0, MLV_Color color = MLV_COLOR_ORANGE);

        /*!
         * @brief Move the MTriangle by point translation
         * @param translation : Every points of this shape will be translate by this parameter
         */

        void move(const Point<double> &translation) override;

        /*!
         * @brief Rotate the MTriangle with specified angular
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
         * @brief Convert all data of MTriangle in a string
         * @return Return a string which contains every points of this shape
         */

        std::string toString() override;
};

#endif //TANGRAM_MTRIANGLE_H
