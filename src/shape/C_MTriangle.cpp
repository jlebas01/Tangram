//
// Created by jlebas01 on 15/01/2020.
//

#include <tuple>
#include <string>

#include <shape/C_MTriangle.hpp>


C_MTriangle::~C_MTriangle() {
    mTriangles.clear(); //delete all elements in vector mTriangles (calling destructor of any elements in this vector)
    // create a new (temporary) vector and swap its contents with mTriangles. The temporary vector is then destroyed, freeing the memory along with it.
    std::vector<C_STriangle>().swap(mTriangles);

}

C_MTriangle::C_MTriangle(const std::vector<C_STriangle> &_triangle, const MLV_Color _color) {
    for (auto &it : _triangle) {
        this->mTriangles.push_back(it);
    }
    this->mColor = _color;
    this->mUpdate = true;
}

C_MTriangle::C_MTriangle(const MLV_Color _color) {
    this->mTriangles.emplace_back(C_STriangle(T_Point<double>(0.0, 0.0), T_Point<double>(100.0, 0.0),
                                              T_Point<double>(100.0, 100.0), _color));
    this->mTriangles.emplace_back(C_STriangle(T_Point<double>(200.0, 0.0), T_Point<double>(100.0, 0.0),
                                              T_Point<double>(100.0, 100.0), _color));
    this->mColor = _color;
    this->mUpdate = true;
}

C_MTriangle::C_MTriangle(const T_Point<double> &origin, const double angular, const MLV_Color _color) : C_MTriangle() {
    __Parameter(origin, angular);
    this->mColor = _color;
    this->mUpdate = true;
}

void C_MTriangle::__Parameter(const T_Point<double> &origin, double angular) {
    aRotate(angular);
    aMove({origin.x, origin.y});
}

T_Point<double> C_MTriangle::__CenterShape() {
    std::vector<T_Point<double>> center_points;
    for (auto &it : mTriangles) {
        center_points.push_back(it.GetCenterPoint());
    }
    T_Point<double> const point_rotate = C_STriangle::CenterPoint(center_points);
    center_points.clear();
    return point_rotate;
}


void C_MTriangle::aMove(const T_Point<double> &translation) {
    for (auto &it : mTriangles) {
        it.aMove(translation);
    }
    mUpdate = true;
}

void C_MTriangle::aRotate(const double angular) {
    T_Point<double> const point_rotate = __CenterShape();
    for (auto &it : mTriangles) {
        it.Rotate(angular, point_rotate);
    }
    mUpdate = true;
}

void C_MTriangle::aRightFlip() {
    for (auto &it : mTriangles){
        it.aSetPoints(it.aGetPoints().at(0), it.GetFlip().at(0));
        it.aSetPoints(it.aGetPoints().at(1), it.GetFlip().at(1));
        it.aSetPoints(it.aGetPoints().at(2), it.GetFlip().at(2));
    }
    T_Point<double> const point_rotate = __CenterShape();
    for (auto &it : mTriangles) {
        it.RightFlip(point_rotate);
    }
    mUpdate = true;
}

void C_MTriangle::aLeftFlip() {
    for (auto &it : mTriangles){
        it.aSetPoints(it.aGetPoints().at(0), it.GetFlip().at(0));
        it.aSetPoints(it.aGetPoints().at(1), it.GetFlip().at(1));
        it.aSetPoints(it.aGetPoints().at(2), it.GetFlip().at(2));
    }
    T_Point<double> const point_rotate = __CenterShape();
    for (auto &it : mTriangles) {
        it.LeftFlip(point_rotate);
    }
    mUpdate = true;
}

void C_MTriangle::aReverse() {
    for (auto &it : mTriangles){
        it.aSetPoints(it.aGetPoints().at(0), it.GetFlip().at(0));
        it.aSetPoints(it.aGetPoints().at(1), it.GetFlip().at(1));
        it.aSetPoints(it.aGetPoints().at(2), it.GetFlip().at(2));
    }
    T_Point<double> const point_rotate = __CenterShape();
    for (auto &it : mTriangles) {
        it.Reverse(point_rotate);
    }
    mUpdate = true;
}

void C_MTriangle::iDraw() {
    for (auto &it : mTriangles) {
        it.iDraw(this->mColor);
    }
}

void C_MTriangle::iDraw(MLV_Color color) {
    for (auto &it : mTriangles) {
        it.iDraw(color);
    }
}

bool C_MTriangle::aIsInShape(const T_Point<double> &click) {
    for (auto &it : mTriangles) {
        if (it.IsInSTriangle(click)) {
            return true;
        }
    }
    return false;
}

std::vector<T_Point<double>> C_MTriangle::aGetPoints() {
    if (mUpdate) {
        mPoints.clear();
        mUpdate = false;
        for (auto &it: mTriangles) {
            for (auto &it2 : it.aGetPoints()) {
                mPoints.push_back(it2);
            }
        }
    }
    std::vector<T_Point<double>> const list_points = mPoints;
    return list_points;
}

bool C_MTriangle::aSetPoints(const T_Point<double> &ref, const T_Point<double> &changed) {
    bool status = false;
    for (auto &it : mTriangles) {
        status |= it.aSetPoints(ref, changed);
    }
    return status;
}

std::string C_MTriangle::aToString() {
    std::string t;
    for (auto[it, i] = std::tuple{mTriangles.begin(), 1}; it != mTriangles.end(); i++, it++) {
        t += std::string("Triangle ") + std::to_string(i) + std::string(" :\n") + it->aToString();
    }
    return t;
}

T_Point<double> C_MTriangle::aLeftCorner() {
    const T_Point<double> leftcorner = {mTriangles.at(0).aLeftCorner()};
    return leftcorner;
}

double C_MTriangle::aCurrentAngular() {
    const double angular = mTriangles.at(0).aCurrentAngular();
    return angular;
}

std::string C_MTriangle::aGetShape() {
    return std::string("C_MTriangle");
}

MLV_Color C_MTriangle::aGetColor() {
    const MLV_Color color = mColor;
    return color;
}

double C_MTriangle::aGetArea(){
    double area = 0.0;
    for (auto &it : mTriangles){
        area += it.aGetArea();
    }
    return area;
}
