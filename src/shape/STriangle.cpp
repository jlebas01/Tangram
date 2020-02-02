//
// Created by jlebas01 on 15/01/2020.
//

#include <utility>
#include <cmath>
#include <tuple>

#include <shape/STriangle.hpp>


STriangle::~STriangle() {
    points.clear(); //delete all elements in vector triangle (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with triangle. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<Point<double>>().swap(points);
}

STriangle::STriangle(const Point<double> point1, const Point<double> point2, const Point<double> point3) {
    this->points.emplace_back(point1.x, point1.y);
    this->points.emplace_back(point2.x, point2.y);
    this->points.emplace_back(point3.x, point3.y);
    this->center = this->center_point();
}

STriangle::STriangle(const std::vector<Point<double>> &points) {
    for (auto &it : points) {
        this->points.push_back(it);
    }
    this->center = this->center_point();
}

STriangle::STriangle(const Point<double> origin, const double angular) : STriangle() {
    parameter(origin, angular);
}

void STriangle::parameter(const Point<double> origin, const double angular = 0.0) {
    rotate(angular);
    move({origin.x, origin.y});
}

STriangle::STriangle() {
    this->points.emplace_back(0.0, 0.0);
    this->points.emplace_back(100.0, 0.0);
    this->points.emplace_back(0.0, 100.0);
    this->center = this->center_point();
}

Point<double> STriangle::center_point(const std::vector<Point<double>> &list_points) {

    double sumx = 0.0, sumy = 0.0;

    if (!list_points.empty()) {
        for (auto &it : list_points) {
            sumx += it.x;
            sumy += it.y;
        }
        return Point<double>(sumx / list_points.size(), sumy / list_points.size());
    }

    return Point<double>(-1, -1); //error case
}

Point<double> STriangle::center_point() {
    double sumx = 0.0, sumy = 0.0;
    for (auto &it : points) {
        sumx += it.x;
        sumy += it.y;
    }
    return Point<double>(sumx / points.size(), sumy / points.size());
}

Point<double> STriangle::get_center_point() {
    center = this->center_point();
    Point<double> const center_point = center;
    return {center_point};
}

void STriangle::move(Point<double> translation) {
    center.operator=(this->center_point());
    for (auto &it : points) {
        it = Point<double>(it.x + translation.x, it.y + translation.y);
    }
    center = this->center_point();
}

void STriangle::rotate(double angular) {
    center.operator=(this->center_point());
    for (auto &it : points) {
        /*it = Point<double>((it.x - center.x) * cos(angular) - (it.y - center.y) * sin(angular) + center.x,
                           (it.y - center.y) * sin(angular) + (it.x - center.y) * cos(angular) + center.y);*/
        it = Point<double>((cos(angular) * (it.x - center.x)) - (sin(angular) * (it.y - center.y)) + center.x,
                           (sin(angular) * (it.x - center.x)) + (cos(angular) * (it.y - center.y)) + center.y);
        /*newx = (cos(angular) * (it.x - center.x)) - (sin(angular) * (it.y - center.y)) + center.x;
        newy = (sin(angular) * (it.x - center.x)) + (cos(angular) * (it.y - center.y)) + center.y;*/
    }
    center = this->center_point();
}

void STriangle::rotate(double angular, Point<double> center_point) {
    for (auto &it : points) {
        it = Point<double>((cos(angular) * (it.x - center_point.x)) - (sin(angular) * (it.y - center_point.y)) + center_point.x,
                           (sin(angular) * (it.x - center_point.x)) + (cos(angular) * (it.y - center_point.y)) + center_point.y);
    }
    center = this->center_point();
}

void STriangle::flip() {
    for (auto &it : points) {
        it = Point<double>(it.y, it.x);
    }
    center = this->center_point();
}

void STriangle::draw() {
    int *x_points = new int[this->points.size()];
    int *y_points = new int[this->points.size()];
    int i = 0;
    for (auto &it: this->points) {
        x_points[i] = static_cast<int>(it.x);
        y_points[i] = static_cast<int>(it.y);
        i++;
    }

    MLV_draw_filled_polygon(x_points, y_points, static_cast<int>(points.size()), MLV_COLOR_GREEN);
}

void STriangle::draw(MLV_Color Color) {
    int *x_points = new int[this->points.size()];
    int *y_points = new int[this->points.size()];
    int i = 0;
    for (auto &it: this->points) {
        x_points[i] = static_cast<int>(it.x);
        y_points[i] = static_cast<int>(it.y);
        i++;
    }
    MLV_draw_filled_polygon(x_points, y_points, static_cast<int>(this->points.size()), Color);
}

std::string STriangle::toString() {
    std::string points;
    for (auto[it, i] = std::tuple{this->points.begin(), 1}; it != this->points.end(); i++, it++) {
        points += std::string("Point ") + std::to_string(i) + std::string(" (x : ") + std::to_string(it->x) +
                  std::string(" y : ") + std::to_string(it->y) + std::string(")\n");
    }
    points += std::string("Center\nx : ") + std::to_string(center.x) + std::string(" y : ") +
              std::to_string(center.y) + std::string("\n");
    return points;
}

double STriangle::computeDistance(Point<double> point1, Point<double> point2) {
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

std::vector<Point<double>> STriangle::get_Points() {
    std::vector<Point<double>> const vec_points = {this->points};
    return vec_points;
}

bool STriangle::is_in_shape(const Point<double> click) {

    return this->is_in_triangle(click);
}

bool STriangle::is_in_triangle(const Point<double> click) {

    double d1, d2, d3;
    bool has_neg, has_pos;

    d1 = (this->sign)(click, points.at(0), points.at(1));
    d2 = (this->sign)(click, points.at(1), points.at(2));
    d3 = (this->sign)(click, points.at(2), points.at(0));

    //    d1 = sign(pt, v1, v2);
    //    d2 = sign(pt, v2, v3);
    //    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

double STriangle::sign(Point<double> p1, Point<double> p2, Point<double> p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}




