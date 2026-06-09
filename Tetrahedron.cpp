#include "Tetrahedron.h"
#include <float.h>

void Tetrahedron::checkTetrahedron(const Point A, const Point B, const Point C, const Point D)
{
	if (A == B || A == C || A == D || B == C || B == D || C == D)
	{
		cerr << "Некоторые точки совпадают => не образуют тетраэдр!";
		exit(1);
	}

	Vector AB(A, B); 
	Vector AC(A, C); 
	Vector AD(A, D);

	// Если смешанное произведение равно нулю, векторы компланарны (лежат в одной плоскости)
	if (fabs(AB.getMixedProduct(AC, AD)) <= DBL_EPSILON)
	{
		cerr << "Точки лежат в одной плоскости => не образуют тетраэдр!";
		exit(1);
	}
}

Tetrahedron::Tetrahedron() : A(0, 0, 0), B(1, 0, 0), C(0, 1, 0), D(0, 0, 1) 
{
}

Tetrahedron::Tetrahedron(const Point A, const Point B, const Point C, const Point D)
{
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;

	checkTetrahedron(A, B, C, D);
}

double Tetrahedron::getVolume() const
{
	Vector AB(A, B); 
	Vector AC(A, C); 
	Vector AD(A, D);

	// Объем тетраэдра равен 1/6 модуля смешанного произведения трех векторов
	return fabs(AB.getMixedProduct(AC, AD)) / 6.0;
}