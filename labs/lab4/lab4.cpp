#include "Vector2D.h"
#include <iostream>
#include <string>

using namespace std;

// part 1
ostream& operator<<(ostream& out, const Vector2D& aVector)
{
   out << "<" << aVector.x << "," << aVector.y << ">";
   return out;
}

// part 2
Vector2D Vector2D::operator+(const Vector2D& rhs) const
{
   return Vector2D(x + rhs.x, y + rhs.y);
}

// part 3
Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
{
   return Vector2D(lhs.getX() - rhs.getX()
      , lhs.getY() - rhs.getY());
}

// part 4
int Vector2D::operator*(const Vector2D& rhs) const
{
   return (x * rhs.x + y * rhs.y);
}

// part 5
Vector2D& Vector2D::operator*=(int value)
{
   x *= value;
   y *= value;
   return *this;
}

// part 6
bool Vector2D::operator==(const Vector2D& rhs) const
{
   return (x == rhs.x && y == rhs.y);
}

int main()
{
    return 0;
}