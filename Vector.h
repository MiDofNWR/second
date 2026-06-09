#pragma once
#include "Point.h"

/**
* @brief Класс 3D вектора
*/
class Vector
{
private:
	/**
	* @param x - координата вектора по оси x
	*/
	double x;

	/**
	* @param y - координата вектора по оси y
	*/
	double y;

	/**
	* @param z - координата вектора по оси z
	*/
	double z;

public:
	/**
	* @brief Конструктор, задающий вектор по трем координатам
	*/
	Vector(const double x, const double y, const double z);

	/**
	* @brief Конструктор, задающий вектор по двум точкам (вектор переносится в начало координат)
	*/
	Vector(const Point A, const Point B);

	/**
	* @brief Рассчитывает длину вектора
	* @return Длину вектора
	*/
	double getLen() const;

	/**
	* @brief Вычисляет смешанное произведение трех векторов (текущего и двух переданных)
	* @param b - второй вектор
	* @param c - третий вектор
	* @return Число, результат смешанного произведения
	*/
	double getMixedProduct(const Vector b, const Vector c) const;
};