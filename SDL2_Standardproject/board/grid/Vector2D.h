//
// Created by clement on 02/06/17.
//

#ifndef SNAKE_PLUSPLUS_VECTOR2D_H
#define SNAKE_PLUSPLUS_VECTOR2D_H

class Vector2D {

public:

    int getX();

    int getY();

    Vector2D(int x, int y);

    Vector2D(const Vector2D &v);

    Vector2D &operator=(const Vector2D &v);

    Vector2D(Vector2D &&v);

    Vector2D &operator=(Vector2D &&v);

    friend bool operator==(Vector2D &lhs, Vector2D &rhs) {
        return lhs._x == rhs._x &&
               lhs._y == rhs._y;
    }

    Vector2D &operator+(Vector2D &other);

    ~Vector2D();


private:
    int _x;
    int _y;

};

#endif //SNAKE_PLUSPLUS_VECTOR2D_H
