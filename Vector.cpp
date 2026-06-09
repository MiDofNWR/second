#include "Vector.h"
#include <float.h>
#include <iostream>

Vector::Vector(const Point A, const Point B)
{
	this->x = B.getX() - A.getX();
	this->y = B.getY() - A.getY();
	this->z = B.getZ() - A.getZ();
}

Vector::Vector(const double x, const double y, const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector::getLen() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Vector::getMixedProduct(const Vector b, const Vector c) const
{
	// Вычисление определителя матрицы 3x3 для нахождения смешанного произведения
	return this->x * (b.y * c.z - b.z * c.y) -
	       this->y * (b.x * c.z - b.z * c.x) +
	       this->z * (b.x * c.y - b.y * c.x);
}