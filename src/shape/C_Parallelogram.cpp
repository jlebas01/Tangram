//
// Created by jlebas01 on 15/01/2020.
//

#include <tuple>
#include <string>

#include <shape/C_Parallelogram.hpp>

C_Parallelogram::~C_Parallelogram() {
    //delete all elements in vector mTriangles (calling destructor of any elements in this vector)
    mTriangles.clear();
    mPoints.clear();
    mTrianglesReverse.clear();
    // create a new (temporary) vector and swap its contents with mTriangles. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<C_STriangle>().swap(mTriangles);
    std::vector<T_Point<double>>().swap(mPoints);
    std::vector<C_STriangle>().swap(mTrianglesReverse);
}

C_Parallelogram::C_Parallelogram(const MLV_Color _color) {
    this->mTriangles.emplace_back(C_STriangle(T_Point<double>(100.0, 0.0), T_Point<double>(100.0, 100.0),
                                              T_Point<double>(0.0, 100.0), _color));
    this->mTriangles.emplace_back(C_STriangle(T_Point<double>(0.0, 200.0), T_Point<double>(100.0, 100.0),
                                              T_Point<double>(0.0, 100.0), _color));

    this->mTrianglesReverse.emplace_back(C_STriangle(T_Point<double>(0.0, 0.0), T_Point<double>(100.0, 100.0),
                                              T_Point<double>(0.0, 100.0), _color));
    this->mTrianglesReverse.emplace_back(C_STriangle(T_Point<double>(100.0, 200.0), T_Point<double>(100.0, 100.0),
                                              T_Point<double>(0.0, 100.0), _color));

    this->mColor = _color;
    this->mUpdate = true;
    this->mReverse = false;
}

C_Parallelogram::C_Parallelogram(const std::vector<C_STriangle> &_triangle, const MLV_Color _color) {
    for (auto &it : _triangle) {
        this->mTriangles.push_back(it);
    }
    this->mColor = _color;
    this->mUpdate = true;
    this->mReverse = false;
}

C_Parallelogram::C_Parallelogram(const T_Point<double> &origin, const double angular, const MLV_Color _color, bool reverse) : C_Parallelogram() {
    __Parameter(origin, angular);
    this->mReverse = false;
    this->mColor = _color;
    this->mUpdate = true;
    if (reverse){
        aReverse();
    }

}

void C_Parallelogram::__Parameter(const T_Point<double> &origin, double angular) {
    aRotate(angular);
    aMove({origin.x, origin.y});
}

T_Point<double> C_Parallelogram::__CenterShape(const std::vector<C_STriangle>& vec) {
    std::vector<T_Point<double>> center_points;
    if (vec.empty()){
        for (auto &it : mTriangles) {
            center_points.push_back(it.GetCenterPoint());
        }
    }
    else {
        for (auto &it : mTrianglesReverse) {
            center_points.push_back(it.GetCenterPoint());
        }
    }
    T_Point<double> const point_rotate = C_STriangle::CenterPoint(center_points);
    center_points.clear();
    std::vector<T_Point<double>>().swap(center_points);
    return point_rotate;

}

void C_Parallelogram::aMove(const T_Point<double> &translation) {
    for (auto &it : mTriangles) {
        it.aMove(translation);
    }
    for (auto &it : mTrianglesReverse) {
        it.aMove(translation);
    }
    mUpdate = true;
}

void C_Parallelogram::aRotate(const double angular) {
    T_Point<double> const point_rotate = __CenterShape();
    for (auto &it : mTriangles) {
        it.Rotate(angular, point_rotate);
    }
    T_Point<double> const point_rotate2 = __CenterShape(mTrianglesReverse);
    for (auto &it : mTrianglesReverse) {
        it.Rotate(angular, point_rotate2);
    }
    mUpdate = true;
}

void C_Parallelogram::aRightFlip() {
    for (auto &it : mTriangles){
        it.aSetPoints(it.aGetPoints().at(0), it.GetFlip().at(0));
        it.aSetPoints(it.aGetPoints().at(1), it.GetFlip().at(1));
        it.aSetPoints(it.aGetPoints().at(2), it.GetFlip().at(2));
    }

    for (auto &it : mTrianglesReverse) {
        it.aSetPoints(it.aGetPoints().at(0), it.GetFlip().at(0));
        it.aSetPoints(it.aGetPoints().at(1), it.GetFlip().at(1));
        it.aSetPoints(it.aGetPoints().at(2), it.GetFlip().at(2));
    }


    T_Point<double> const point_rotate = __CenterShape();
    for (auto &it : mTriangles) {
        it.RightFlip(point_rotate);
    }

    T_Point<double> const point_rotate2 = __CenterShape(mTrianglesReverse);
    for (auto &it : mTrianglesReverse) {
        it.LeftFlip(point_rotate2);
    }


    mUpdate = true;
}

void C_Parallelogram::aLeftFlip() {
    for (auto &it : mTriangles){
        it.aSetPoints(it.aGetPoints().at(0), it.GetFlip().at(0));
        it.aSetPoints(it.aGetPoints().at(1), it.GetFlip().at(1));
        it.aSetPoints(it.aGetPoints().at(2), it.GetFlip().at(2));
    }

    for (auto &it : mTrianglesReverse) {
        it.aSetPoints(it.aGetPoints().at(0), it.GetFlip().at(0));
        it.aSetPoints(it.aGetPoints().at(1), it.GetFlip().at(1));
        it.aSetPoints(it.aGetPoints().at(2), it.GetFlip().at(2));
    }


    T_Point<double> const point_rotate = __CenterShape();
    for (auto &it : mTriangles) {
        it.LeftFlip(point_rotate);
    }

    T_Point<double> const point_rotate2 = __CenterShape(mTrianglesReverse);
    for (auto &it : mTrianglesReverse) {
        it.RightFlip(point_rotate2);
    }

    mUpdate = true;
}

void C_Parallelogram::aReverse() {

    std::vector<C_STriangle> tmp = mTriangles;
    mTriangles = mTrianglesReverse;
    mTrianglesReverse = tmp;
    tmp.clear();
    std::vector<C_STriangle>().swap(tmp);
    mUpdate = true;
    mReverse=!mReverse;
}

void C_Parallelogram::iDraw() {
    for (auto &it : mTriangles) {
        it.iDraw(this->mColor);
    }
}

void C_Parallelogram::iDraw(MLV_Color color) {
    for (auto &it : mTriangles) {
        it.iDraw(color);
    }
}

bool C_Parallelogram::aIsInShape(const T_Point<double> &click) {
    for (auto &it : mTriangles) {
        if (it.IsInSTriangle(click)) {
            return true;
        }
    }
    return false;
}

std::vector<T_Point<double>> C_Parallelogram::aGetPoints() {
    if (mUpdate){
        mPoints.clear();
        mUpdate = false;
        for (auto &it: mTriangles){
            for (auto &it2 : it.aGetPoints()){
                mPoints.push_back(it2);
            }
        }
    }
    std::vector<T_Point<double>> const list_points = mPoints;
    return list_points;
}

bool C_Parallelogram::aSetPoints(const T_Point<double> &ref, const T_Point<double> &changed) {
    bool status = false;
    for (auto &it : mTriangles){
        status |= it.aSetPoints(ref, changed);
    }
    return status;
}

std::string C_Parallelogram::aToString() {
    std::string t;
    for (auto[it, i] = std::tuple{mTriangles.begin(), 1}; it != mTriangles.end(); i++, it++) {
        t += std::string("Triangle ") + std::to_string(i) + std::string(" :\n") + it->aToString();
    }
    return t;
}

T_Point<double> C_Parallelogram::aLeftCorner() {
    const T_Point<double> leftcorner = {mTriangles.at(0).aLeftCorner()};
    return leftcorner;
}

double C_Parallelogram::aCurrentAngular() {
    const double angular = mTriangles.at(0).aCurrentAngular();
    return angular;
}

std::string C_Parallelogram::aGetShape() {
    return std::string("C_Parallelogram");
}

MLV_Color C_Parallelogram::aGetColor() {
    const MLV_Color color = mColor;
    return color;
}

double C_Parallelogram::aGetArea(){
    double area = 0.0;
    for (auto &it : mTriangles){
        area += it.aGetArea();
    }
    return area;
}

bool C_Parallelogram::aGetStatusReverse() const {
    return mReverse;
}
