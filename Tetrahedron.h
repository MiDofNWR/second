#pragma once
#include <iostream>
#include "Vector.h"

using namespace std;

/**
* @brief Класс тетраэдра
*/
class Tetrahedron
{
private:
	/**
	* @param A - первая точка (вершина)
	*/
	Point A;

	/**
	* @param B - вторая точка (вершина)
	*/
	Point B;

	/**
	* @param C - третья точка (вершина)
	*/
	Point C;

	/**
	* @param D - четвертая точка (вершина)
	*/
	Point D;

	/**
	* @brief Функция проверки, образуют ли точки тетраэдр (не лежат ли они в одной плоскости)
	* @param A - первая точка
	* @param B - вторая точка
	* @param C - третья точка
	* @param D - четвертая точка
	*/
	void checkTetrahedron(const Point A, const Point B, const Point C, const Point D);

public:
	/**
	* @brief Конструктор по-умолчанию, задаёт базовый тетраэдр
	*/
	Tetrahedron();

	/**
	* @brief Конструктор, задаёт координаты вершин как переданные значения
	* @param A - значение первой точки
	* @param B - значение второй точки
	* @param C - значение третьей точки
	* @param D - значение четвертой точки
	*/
	Tetrahedron(const Point A, const Point B, const Point C, const Point D);

	/**
	* @brief Рассчитывает объем тетраэдра
	* @return Рассчитанное значение объема
	*/
	double getVolume() const;
};