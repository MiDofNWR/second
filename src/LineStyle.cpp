#include "../include/LineStyle.h"

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

/**
* @brief Преобразует тип линии в строку.
* @param type Тип линии.
* @return Строковое название типа линии.
*/
static string LineTypeToString(const LineType type)
{
    if (type == LineType::solid)
    {
        return "solid";
    }
    if (type == LineType::dash)
    {
        return "dash";
    }
    if (type == LineType::dot)
    {
        return "dot";
    }
    if (type == LineType::dash_dot)
    {
        return "dash-dot";
    }
    return "dashdotdot";
}

/**
* @brief Преобразует строку в тип линии.
* @param text Строковое название типа линии.
* @return Тип линии.
* @throw invalid_argument если тип линии задан неверно.
*/
static LineType StringToLineType(const string& text)
{
    if (text == "solid")
    {
        return LineType::solid;
    }
    if (text == "dash")
    {
        return LineType::dash;
    }
    if (text == "dot")
    {
        return LineType::dot;
    }
    if (text == "dash-dot")
    {
        return LineType::dash_dot;
    }
    if (text == "dashdotdot")
    {
        return LineType::dashdotdot;
    }

    throw invalid_argument("Неверно задан тип линии.");
}

void LineStyle::CheckLineStyle(void) const
{
    if (thickness <= 0)
    {
        throw invalid_argument("Толщина линии должна быть больше нуля.");
    }
}

LineStyle::LineStyle(const LineType type, const int thickness)
{
    this->type = type;
    this->thickness = thickness;
    CheckLineStyle();
}

LineType LineStyle::getType(void) const
{
    return type;
}

int LineStyle::getThickness(void) const
{
    return thickness;
}

void LineStyle::setType(const LineType type)
{
    this->type = type;
}

void LineStyle::setThickness(const int thickness)
{
    this->thickness = thickness;
    CheckLineStyle();
}

ostream& operator << (ostream& output, const LineStyle& style)
{
    output << LineTypeToString(style.type) << ' ' << style.thickness;
    return output;
}

istream& operator >> (istream& input, LineStyle& style)
{
    string typeText;
    int thickness;

    input >> typeText >> thickness;

    if (input.fail())
    {
        return input;
    }

    try
    {
        style = LineStyle(StringToLineType(typeText), thickness);
    }
    catch (const exception& error)
    {
        cerr << "Ошибка: " << error.what() << endl;
        input.setstate(ios::failbit);
    }

    return input;
}
