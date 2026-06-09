#include "../include/Color.h"

#include <exception>
#include <iostream>
#include <stdexcept>

void Color::CheckColorComponent(const int value)
{
    if (value < 0 || value > 255)
    {
        throw out_of_range("Компоненты цвета должны быть от 0 до 255.");
    }
}

Color::Color(const int red, const int green, const int blue)
{
    CheckColorComponent(red);
    CheckColorComponent(green);
    CheckColorComponent(blue);

    this->red = static_cast<uint8_t>(red);
    this->green = static_cast<uint8_t>(green);
    this->blue = static_cast<uint8_t>(blue);
}

int Color::getRed(void) const
{
    return static_cast<int>(red);
}

int Color::getGreen(void) const
{
    return static_cast<int>(green);
}

int Color::getBlue(void) const
{
    return static_cast<int>(blue);
}

ostream& operator << (ostream& output, const Color& color)
{
    output << color.getRed() << ' ' << color.getGreen() << ' ' << color.getBlue();
    return output;
}

istream& operator >> (istream& input, Color& color)
{
    int red;
    int green;
    int blue;

    input >> red >> green >> blue;

    if (input.fail())
    {
        return input;
    }

    try
    {
        color = Color(red, green, blue);
    }
    catch (const exception& error)
    {
        cerr << "Ошибка: " << error.what() << endl;
        input.setstate(ios::failbit);
    }

    return input;
}
