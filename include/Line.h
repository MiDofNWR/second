#pragma once

#include "Color.h"
#include "LineStyle.h"
#include "Point.h"

/**
* @brief Класс линия.
* Класс хранит две точки, стиль линии и цвет линии.
*/
class Line
{
private:
    /**
    * @brief Первая точка линии.
    */
    Point firstPoint;

    /**
    * @brief Вторая точка линии.
    */
    Point secondPoint;

    /**
    * @brief Стиль линии.
    */
    LineStyle style;

    /**
    * @brief Цвет линии.
    */
    Color color;

public:
    /**
    * @brief Конструктор линии.
    * @param firstPoint Первая точка линии.
    * @param secondPoint Вторая точка линии.
    * @param style Стиль линии. По умолчанию используется сплошная линия толщиной 1.
    * @param color Цвет линии. По умолчанию используется чёрный цвет.
    */
    Line(const Point firstPoint = Point(), const Point secondPoint = Point(),
         const LineStyle style = LineStyle(), const Color color = Color());

    /**
    * @brief Возвращает первую точку линии.
    * @return Первая точка линии.
    */
    Point getFirstPoint(void) const;

    /**
    * @brief Возвращает вторую точку линии.
    * @return Вторая точка линии.
    */
    Point getSecondPoint(void) const;

    /**
    * @brief Возвращает стиль линии.
    * @return Стиль линии.
    */
    LineStyle getStyle(void) const;

    /**
    * @brief Возвращает цвет линии.
    * @return Цвет линии.
    */
    Color getColor(void) const;

    /**
    * @brief Изменяет стиль линии.
    * @param style Новый стиль линии.
    */
    void setStyle(const LineStyle style);

    /**
    * @brief Изменяет цвет линии.
    * @param color Новый цвет линии.
    */
    void setColor(const Color color);

    /**
    * @brief Выводит информацию о линии в поток.
    * @param output Поток вывода.
    */
    void ToString(ostream& output) const;

    /**
    * @brief Считывает линию из потока ввода.
    * Формат ввода: x1 y1 x2 y2; тип линии; толщина; red green blue.
    * @param input Поток ввода.
    * @return Считанная линия.
    * @throw invalid_argument если ввод выполнен неверно.
    */
    static Line Read(istream& input);

    /**
    * @brief Оператор вывода линии в поток.
    * @param output Поток вывода.
    * @param line Выводимая линия.
    * @return Ссылка на поток вывода.
    */
    friend ostream& operator << (ostream& output, const Line& line);
};
