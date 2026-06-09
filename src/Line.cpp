#include "../include/Line.h"

#include <stdexcept>

Line::Line(const Point firstPoint, const Point secondPoint,
           const LineStyle style, const Color color)
{
    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->style = style;
    this->color = color;
}

Point Line::getFirstPoint(void) const
{
    return firstPoint;
}

Point Line::getSecondPoint(void) const
{
    return secondPoint;
}

LineStyle Line::getStyle(void) const
{
    return style;
}

Color Line::getColor(void) const
{
    return color;
}

void Line::setStyle(const LineStyle style)
{
    this->style = style;
}

void Line::setColor(const Color color)
{
    this->color = color;
}

void Line::ToString(ostream& output) const
{
    output << "Информация о линии:" << endl;
    output << "Первая точка: " << firstPoint << endl;
    output << "Вторая точка: " << secondPoint << endl;
    output << "Стиль линии: " << style << endl;
    output << "Цвет линии: " << color << endl;
}

Line Line::Read(istream& input)
{
    Point firstPoint;
    Point secondPoint;
    LineStyle style;
    Color color;

    input >> firstPoint >> secondPoint >> style >> color;

    if (input.fail())
    {
        throw invalid_argument("Линия задана неверно.");
    }

    return Line(firstPoint, secondPoint, style, color);
}

ostream& operator << (ostream& output, const Line& line)
{
    line.ToString(output);
    return output;
}
