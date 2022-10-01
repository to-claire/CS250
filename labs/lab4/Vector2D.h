#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D
{
    friend std::ostream& operator<<(std::ostream& out, const Vector2D& aVector);

public:
    Vector2D() : x(0), y(0) {}
    Vector2D(int newX, int newY) : x(newX), y(newY) {}

    int getX() const { return x; }
    int getY() const { return y; }

    Vector2D operator+(const Vector2D& rhs) const;
    int operator*(const Vector2D& rhs) const;
    Vector2D& operator*=(int value);
    bool operator==(const Vector2D& rhs) const;

    ~Vector2D() {}

private:
    int x;    //first vector value
    int y;    //second vector value
};

Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);


#endif