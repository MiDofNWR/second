#pragma once

#include <iostream>

using namespace std;

/**
* @brief Структура точка.
* Структура хранит абсциссу и ординату точки на плоскости.
*/
struct Point
{
    /**
    * @brief Абсцисса точки.
    */
    double x;

    /**
    * @brief Ордината точки.
    */
    double y;

    /**
    * @brief Конструктор точки.
    * @param x Абсцисса точки.
    * @param y Ордината точки.
    */
    Point(const double x = 0.0, const double y = 0.0);

    /**
    * @brief Сравнивает две точки на равенство.
    * @param other Точка для сравнения.
    * @return true, если абсциссы и ординаты точек равны, иначе false.
    */
    bool operator == (const Point& other) const;

    /**
    * @brief Оператор вывода точки в поток.
    * @param output Поток вывода.
    * @param point Выводимая точка.
    * @return Ссылка на поток вывода.
    */
    friend ostream& operator << (ostream& output, const Point& point);

    /**
    * @brief Оператор ввода точки из потока.
    * @param input Поток ввода.
    * @param point Точка, в которую записываются считанные данные.
    * @return Ссылка на поток ввода.
    */
    friend istream& operator >> (istream& input, Point& point);
};
