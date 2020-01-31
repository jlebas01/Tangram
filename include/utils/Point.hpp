#ifndef TANGRAM_POINT_H
#define TANGRAM_POINT_H


template<typename T>
class Point {
public:
    T x;
    T y;

    Point() : x(0), y(0) {}

    Point(const T x, const T y) {
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point<T> p) const {
        return this->x == p.x && this->y == p.y;
    }

    Point &operator=(const Point<T> p) {
        this->x = p.x;
        this->y = p.y;
        return *this;
    }

    bool operator!=(const Point<T> p) const {
        return this->x != p.x || this->y != p.y;
    }
};

#endif
