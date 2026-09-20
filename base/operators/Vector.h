#pragma once
#include <iostream>
#include <stdexcept>

class Vector {
private:
    int _x = 0;
    int _y = 0;

public:
    Vector(int x, int y) : _x(x), _y(y) {}

    Vector& operator+=(const Vector& v) {
        _x += v._x;
        _y += v._y;
        return *this;
    }

    Vector& operator-=(const Vector& v) {
        _x -= v._x;
        _y -= v._y;
        return *this;
    }

    Vector& operator*=(const Vector& v) {
        _x *= v._x;
        _y *= v._y;
        return *this;
    }

    Vector& operator/=(const Vector& v) {
        if (v._x == 0 || v._y == 0) {
            throw std::invalid_argument("cannot divide on zero");
        }
        _x /= v._x;
        _y /= v._y;
        return *this;
    }

    int x() const {return _x;}
    int y() const {return _y;}
};

inline Vector operator+(Vector v1, const Vector& v2) {
    v1 += v2;
    return v1;
}

inline Vector operator-(Vector v1, const Vector& v2) {
    v1 -= v2;
    return v1;
}

inline Vector operator*(Vector v1, const Vector& v2) {
    v1 *= v2;
    return v1;
}

inline Vector operator/(Vector v1, const Vector& v2) {
    v1 /= v2;
    return v1;
}

inline std::ostream& operator<<(std::ostream& o, const Vector& v) {
    return o << "Vector{ " << v.x() << ", " << v.y() << " }";
}
