#include "Tetrahedron.h"

/**
* @brief Считывает значения введённые с клавиатуры, преобразуя их в 3D "точку"
* @return Точку, с переданными ей значениями
*/
const Point getPoint(void);

/**
* @brief Точка входа в программу
* @return Возвращает ноль, если программа выполнена корректно, иначе единицу
*/
int main(void)
{
	system("chcp 1251");
	system("CLS");

	cout << "Введите координату первой точки в формате (x y z): ";
	Point A = getPoint();
	cout << "Введите координату второй точки в формате (x y z): ";
	Point B = getPoint();
	cout << "Введите координату третьей точки в формате (x y z): ";
	Point C = getPoint();
	cout << "Введите координату четвертой точки в формате (x y z): ";
	Point D = getPoint();

	Tetrahedron First(A, B, C, D);
	cout << endl << endl << "Объем тетраэдра: " << First.getVolume() << endl;
	
	return 0;
}

const Point getPoint(void)
{
	double x = 0;
	double y = 0;
	double z = 0;
	cin >> x >> y >> z;
	if (cin.fail())
	{
		cout << "Ошибка ввода!";
		exit(1);
	}
	Point A(x, y, z);
	return A;
}