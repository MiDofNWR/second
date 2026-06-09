#pragma once

#include <iostream>
#include <string>

using namespace std;

/**
* @brief Тип линии.
*/
enum class LineType
{
    /**
    * @brief Сплошная линия.
    */
    solid,

    /**
    * @brief Пунктирная линия.
    */
    dash,

    /**
    * @brief Линия точками.
    */
    dot,

    /**
    * @brief Линия точка-тире.
    */
    dash_dot,

    /**
    * @brief Линия две точки тире.
    */
    dashdotdot
};

/**
* @brief Класс стиль линии.
* Класс хранит тип линии и толщину линии.
*/
class LineStyle
{
private:
    /**
    * @brief Тип линии.
    */
    LineType type;

    /**
    * @brief Толщина линии.
    */
    int thickness;

    /**
    * @brief Проверяет корректность стиля линии.
    * @throw invalid_argument если толщина линии меньше или равна нулю.
    */
    void CheckLineStyle(void) const;

public:
    /**
    * @brief Конструктор стиля линии.
    * @param type Тип линии. По умолчанию используется сплошная линия.
    * @param thickness Толщина линии. Должна быть больше нуля. По умолчанию равна 1.
    * @throw invalid_argument если толщина линии меньше или равна нулю.
    */
    LineStyle(const LineType type = LineType::solid, const int thickness = 1);

    /**
    * @brief Возвращает тип линии.
    * @return Тип линии.
    */
    LineType getType(void) const;

    /**
    * @brief Возвращает толщину линии.
    * @return Толщина линии.
    */
    int getThickness(void) const;

    /**
    * @brief Изменяет тип линии.
    * @param type Новый тип линии.
    */
    void setType(const LineType type);

    /**
    * @brief Изменяет толщину линии.
    * @param thickness Новая толщина линии.
    * @throw invalid_argument если толщина линии меньше или равна нулю.
    */
    void setThickness(const int thickness);

    /**
    * @brief Оператор вывода стиля линии в поток.
    * @param output Поток вывода.
    * @param style Выводимый стиль линии.
    * @return Ссылка на поток вывода.
    */
    friend ostream& operator << (ostream& output, const LineStyle& style);

    /**
    * @brief Оператор ввода стиля линии из потока.
    * @param input Поток ввода.
    * @param style Стиль, в который записываются считанные данные.
    * @return Ссылка на поток ввода.
    */
    friend istream& operator >> (istream& input, LineStyle& style);
};
