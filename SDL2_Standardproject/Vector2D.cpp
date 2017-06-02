//
// Created by clement on 02/06/17.
//

#include "Vector2D.h"

Vector2D::Vector2D(int x, int y) : _x{x}, _y{y} {}

Vector2D::Vector2D(const Vector2D &v) : Vector2D{v._x, v._y} {}

Vector2D::Vector2D(Vector2D &&v) : _x{0}, _y{0} {
    _x = v._x;
    _y = v._y;
    v._x = 0;
    v._y = 0;
}


Vector2D::~Vector2D() {}


int Vector2D::getX() { return _x; }

int Vector2D::getY() { return _y; }

Vector2D &Vector2D::operator=(const Vector2D &v) {
    _x = v._x;
    _y = v._y;
    return *this;
}

Vector2D &Vector2D::operator=(Vector2D &&v) {
    if (this != &v) {
        _x = v._x;
        _y = v._y;
        v._x = 0;
        v._y = 0;
    }
    return *this;
}

Vector2D Vector2D::operator+(Vector2D &other) {
    return Vector2D{_x + other._x, _y + other._y};
}

template<typename T>
Vector2D Vector2D::operator*(T &scalar) {
    return Vector2D(_x * scalar, _y * scalar);
}

