#pragma once

#include <cstdint>
#include <iostream>

using namespace std;

/**
* @brief Класс цвет.
* Класс хранит три цветовых компонента: red, green, blue.
*/
class Color
{
private:
    /**
    * @brief Красная компонента цвета.
    */
    uint8_t red;

    /**
    * @brief Зелёная компонента цвета.
    */
    uint8_t green;

    /**
    * @brief Синяя компонента цвета.
    */
    uint8_t blue;

    /**
    * @brief Проверяет одну компоненту цвета.
    * @param value Проверяемое значение.
    * @throw out_of_range если значение не входит в диапазон от 0 до 255.
    */
    static void CheckColorComponent(const int value);

public:
    /**
    * @brief Конструктор цвета.
    * @param red Красная компонента цвета.
    * @param green Зелёная компонента цвета.
    * @param blue Синяя компонента цвета.
    * @throw out_of_range если хотя бы одна компонента не входит в диапазон от 0 до 255.
    */
    Color(const int red = 0, const int green = 0, const int blue = 0);

    /**
    * @brief Возвращает красную компоненту цвета.
    * @return Красная компонента цвета.
    */
    int getRed(void) const;

    /**
    * @brief Возвращает зелёную компоненту цвета.
    * @return Зелёная компонента цвета.
    */
    int getGreen(void) const;

    /**
    * @brief Возвращает синюю компоненту цвета.
    * @return Синяя компонента цвета.
    */
    int getBlue(void) const;

    /**
    * @brief Оператор вывода цвета в поток.
    * @param output Поток вывода.
    * @param color Выводимый цвет.
    * @return Ссылка на поток вывода.
    */
    friend ostream& operator << (ostream& output, const Color& color);

    /**
    * @brief Оператор ввода цвета из потока.
    * @param input Поток ввода.
    * @param color Цвет, в который записываются считанные данные.
    * @return Ссылка на поток ввода.
    */
    friend istream& operator >> (istream& input, Color& color);
};
