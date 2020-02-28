//
// Created by jlebas01 on 15/01/2020.
//

#include <cmath>
#include <tuple>

#include <shape/C_STriangle.hpp>
#include <bits/unique_ptr.h>
#include <iostream>

C_STriangle::~C_STriangle() {
    mPoints.clear(); //delete all elements in vector mTriangles (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with mTriangles. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<T_Point<double>>().swap(mPoints);
    mFlip.clear();
    std::vector<T_Point<double>>().swap(mFlip);
}

C_STriangle::C_STriangle(const T_Point<double> &point1, const T_Point<double> &point2, const T_Point<double> &point3,
                         const MLV_Color _color) {
    this->mPoints.emplace_back(point1.x, point1.y);
    this->mPoints.emplace_back(point2.x, point2.y);
    this->mPoints.emplace_back(point3.x, point3.y);
    this->mFlip.insert(mFlip.end(), mPoints.begin(), mPoints.end());
    this->mCenter = this->__CenterPoint();
    this->mColor = _color;
    this->mAngularShape = 0.0;
    this->mFlipAngular = 0.0;
    this->mTranslateShape = {0.0, 0.0};
    this->mFlipTranslate = mTranslateShape;
}

C_STriangle::C_STriangle(const std::vector<T_Point<double>> &_points, const MLV_Color _color) {
    for (auto &it : _points) {
        this->mPoints.push_back(it);
    }
    this->mFlip.insert(mFlip.end(), mPoints.begin(), mPoints.end());
    this->mCenter = this->__CenterPoint();
    this->mColor = _color;
    this->mAngularShape = 0.0;
    this->mFlipAngular = 0.0;
    this->mTranslateShape = {0.0, 0.0};
    this->mFlipTranslate = mTranslateShape;
}

C_STriangle::C_STriangle(const T_Point<double> &origin, const double angular, const MLV_Color _color) : C_STriangle() {
    this->mAngularShape = 0.0;
    this->mFlipAngular = 0.0;
    this->mTranslateShape = {0.0, 0.0};
    this->mFlipTranslate = mTranslateShape;
    this->mFlip.insert(mFlip.end(), mPoints.begin(), mPoints.end());
    __Parameter(origin, angular);
    this->mColor = _color;

}

void C_STriangle::__Parameter(const T_Point<double> &origin, double angular) {
    aRotate(angular);
    aMove({origin.x, origin.y});
}

C_STriangle::C_STriangle(const MLV_Color _color) {
    this->mPoints.emplace_back(0.0, 0.0);
    this->mPoints.emplace_back(100.0, 0.0);
    this->mPoints.emplace_back(0.0, 100.0);
    this->mCenter = this->__CenterPoint();
    this->mColor = _color;
    this->mAngularShape = 0.0;
    this->mFlipAngular = 0.0;
    this->mTranslateShape = {0.0, 0.0};
    this->mFlipTranslate = mTranslateShape;
    this->mFlip.insert(mFlip.end(), mPoints.begin(), mPoints.end());
}

void C_STriangle::aMove(const T_Point<double> &translation) {
    mCenter.operator=(this->__CenterPoint());
    for (auto &it : mPoints) {
        it = T_Point<double>(it.x + translation.x, it.y + translation.y);
    }
    mCenter = this->__CenterPoint();
    mTranslateShape.x+=translation.x;
    mTranslateShape.y+=translation.y;
}

void C_STriangle::aRotate(const double angular) {
    mCenter.operator=(this->__CenterPoint());
    for (auto &it : mPoints) {
        it = T_Point<double>((cos(angular) * (it.x - mCenter.x)) - (sin(angular) * (it.y - mCenter.y)) + mCenter.x,
                           (sin(angular) * (it.x - mCenter.x)) + (cos(angular) * (it.y - mCenter.y)) + mCenter.y);
    }
    mCenter = this->__CenterPoint();
    mAngularShape += angular;
}

void C_STriangle::Rotate(double angular, const T_Point<double> &center_point) {
    for (auto &it : mPoints) {
        it = T_Point<double>(
                (cos(angular) * (it.x - center_point.x)) - (sin(angular) * (it.y - center_point.y)) + center_point.x,
                (sin(angular) * (it.x - center_point.x)) + (cos(angular) * (it.y - center_point.y)) + center_point.y);
    }
    mCenter = this->__CenterPoint();
    mAngularShape += angular;
}

void C_STriangle::aFlip() {
    aSetPoints(mPoints.at(0), mFlip.at(0));
    aSetPoints(mPoints.at(1), mFlip.at(1));
    aSetPoints(mPoints.at(2), mFlip.at(2));
    mAngularShape = mFlipAngular;
    aRotate(3.14159265358979323846/4.0);
    mFlipAngular = mAngularShape;

    if (mFlipTranslate != mTranslateShape){
        aMove({mTranslateShape.x - mFlipTranslate.x, mTranslateShape.y - mFlipTranslate.y});
        mFlipTranslate = mTranslateShape;
    }
    mFlip.clear();
    mFlip.insert(mFlip.end(), mPoints.begin(), mPoints.end());
}

void C_STriangle::Flip(const T_Point<double> &centerPoint) {

    mAngularShape = mFlipAngular;
    Rotate(3.14159265358979323846/4.0, centerPoint);
    mFlipAngular = mAngularShape;
    std::cout  << mTranslateShape.x <<" "<< mFlipTranslate.x << " : "<< mTranslateShape.y <<" "<< mFlipTranslate.y <<std::endl;
    if (mFlipTranslate != mTranslateShape){
        aMove({mTranslateShape.x - mFlipTranslate.x, mTranslateShape.y - mFlipTranslate.y});
        mFlipTranslate = mTranslateShape;
    }
    mFlip.clear();
    mFlip.insert(mFlip.end(), mPoints.begin(), mPoints.end());

    std::cout << aToString() << std::endl;

}

void C_STriangle::iDraw() {
    std::unique_ptr<int[]> x_points(new int[this->mPoints.size()]);
    std::unique_ptr<int[]> y_points(new int[this->mPoints.size()]);
    int i = 0;
    for (auto &it: this->mPoints) {
        x_points[i] = static_cast<int>(it.x);
        y_points[i] = static_cast<int>(it.y);
        i++;
    }

    MLV_draw_filled_polygon(x_points.get(), y_points.get(), static_cast<int>(mPoints.size()), this->mColor);
}

void C_STriangle::iDraw(MLV_Color _color) {
    std::unique_ptr<int[]> x_points(new int[this->mPoints.size()]);
    std::unique_ptr<int[]> y_points(new int[this->mPoints.size()]);
    int i = 0;
    for (auto &it: this->mPoints) {
        x_points[i] = static_cast<int>(it.x);
        y_points[i] = static_cast<int>(it.y);
        i++;
    }
    MLV_draw_filled_polygon(x_points.get(), y_points.get(), static_cast<int>(this->mPoints.size()), _color);
}

T_Point<double> C_STriangle::CenterPoint(const std::vector<T_Point<double>> &list_points) {

    double sumx = 0.0, sumy = 0.0;

    if (!list_points.empty()) {
        for (auto &it : list_points) {
            sumx += it.x;
            sumy += it.y;
        }
        return T_Point<double>(sumx / list_points.size(), sumy / list_points.size());
    }
    std::cerr << "Error happens" <<  "file: " << __FILE__ << "/ : " << __func__ << "():" << __LINE__ << std::endl;
    return T_Point<double>(-1, -1); //error case
}

T_Point<double> C_STriangle::__CenterPoint() {
    double sumx = 0.0, sumy = 0.0;
    for (auto &it : mPoints) {
        sumx += it.x;
        sumy += it.y;
    }
    return T_Point<double>(sumx / mPoints.size(), sumy / mPoints.size());
}

T_Point<double> C_STriangle::GetCenterPoint() {
    mCenter = this->__CenterPoint();
    T_Point<double> const center_point = mCenter;
    return {center_point};
}

std::string C_STriangle::aToString() {
    std::string _points;
    for (auto[it, i] = std::tuple{this->mPoints.begin(), 1}; it != this->mPoints.end(); i++, it++) {
        _points += std::string("T_Point ") + std::to_string(i) + std::string(" (x : ") + std::to_string(it->x) +
                   std::string(" y : ") + std::to_string(it->y) + std::string(")\n");
    }
    _points += std::string("Center\nx : ") + std::to_string(mCenter.x) + std::string(" y : ") +
               std::to_string(mCenter.y) + std::string("\n");
    return _points;
}

std::vector<T_Point<double>> C_STriangle::aGetPoints() {
    std::vector<T_Point<double>> const vec_points = {this->mPoints};
   // return {this->mPoints = std::aMove(this->mPoints)};
    return vec_points;
}

bool C_STriangle::aSetPoints(const T_Point<double> &ref, const T_Point<double> &changed) {
    bool status = false;
    for (auto &it : mPoints) {
        if (it == ref) {
            it.x = changed.x;
            it.y = changed.y;
            status = true;
        }
    }
    return status;
}

bool C_STriangle::aIsInShape(const T_Point<double> &click) {

    return this->IsInSTriangle(click);
}

bool C_STriangle::IsInSTriangle(const T_Point<double> &click) {

    double d1, d2, d3;
    bool has_neg, has_pos;

    d1 = (this->__Sign)(click, mPoints.at(0), mPoints.at(1));
    d2 = (this->__Sign)(click, mPoints.at(1), mPoints.at(2));
    d3 = (this->__Sign)(click, mPoints.at(2), mPoints.at(0));

    //    d1 = __Sign(pt, v1, v2);
    //    d2 = __Sign(pt, v2, v3);
    //    d3 = __Sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

double C_STriangle::__Sign(const T_Point<double> &p1, const T_Point<double> &p2, const T_Point<double> &p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

double C_STriangle::aCurrentAngular() {
    const double angular = mAngularShape;
    return angular;
}


T_Point<double> C_STriangle::aLeftCorner() {
    const T_Point<double> leftcorner = mTranslateShape;
    return leftcorner;
}

std::string C_STriangle::aGetShape() {
    return std::string("C_STriangle");
}

MLV_Color C_STriangle::aGetColor() {
    const MLV_Color color = mColor;
    return color;
}

double C_STriangle::aGetArea(){
    double area = 0.0;
    area += abs(mPoints.at(0).x * ( mPoints.at(1).y -  mPoints.at(2).y));
    area += abs(mPoints.at(1).x * ( mPoints.at(2).y -  mPoints.at(0).y));
    area += abs(mPoints.at(2).x * ( mPoints.at(0).y -  mPoints.at(1).y));
    area /= 2.0;
    return area;
}

std::vector<T_Point<double>> C_STriangle::GetFlip(){
    const std::vector<T_Point<double>> getter = mFlip;
    return getter;
}
