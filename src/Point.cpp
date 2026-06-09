#include "../include/Point.h"
#include <float.h>

Point::Point(const double x, const double y)
{
    this->x = x;
    this->y = y;
}

bool Point::operator == (const Point& other) const
{
    return std::abs(x - other.x) < DBL_EPSILON && std::abs(x - other.y) < DBL_EPSILON;
}

ostream& operator << (ostream& output, const Point& point)
{
    output << '(' << point.x << "; " << point.y << ')';
    return output;
}

istream& operator >> (istream& input, Point& point)
{
    input >> point.x >> point.y;
    return input;
}
