#pragma once
#include <cmath>

/**
* @brief Класс точки в трехмерном пространстве
*/
class Point
{
private:
	/**
	* @param x - координата точки по оси x
	*/
	double x;

	/**
	* @param y - координата точки по оси y
	*/
	double y;

	/**
	* @param z - координата точки по оси z
	*/
	double z;

public:
	/**
	* @brief Конструктор, который задаёт точку с координатами (x;y;z)
	* @param x - координата точки по оси x
	* @param y - координата точки по оси y
	* @param z - координата точки по оси z
	*/
	Point(const double x = 0, const double y = 0, const double z = 0);

	/**
	* @brief Выводит значение точки по оси x
	* @return Значение точки по оси x
	*/
	double getX(void) const;

	/**
	* @brief Выводит значение точки по оси y
	* @return Значение точки по оси y
	*/
	double getY(void) const;

	/**
	* @brief Выводит значение точки по оси z
	* @return Значение точки по оси z
	*/
	double getZ(void) const;

	/**
	* @brief Оператор, который присваивает значение одной точки другой
	* @param other - точка
	*/
	void operator = (const Point other);

	/**
	* @brief Оператор, который сравнивает 2 точки (они считаются не равными, если хотя бы 1 пара координат не равна)
	* @param other - точка
	* @return Единица, если точки не совпадают, иначе - ноль
	*/
	bool operator != (const Point other) const;

	/**
	* @brief Оператор, который сравнивает 2 точки (они считаются равными, если координаты попарно равны)
	* @param other - точка
	* @return Единица, если точки совпадают, иначе - ноль
	*/
	bool operator == (const Point other) const;
};