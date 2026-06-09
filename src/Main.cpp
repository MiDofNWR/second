#include "../include/Line.h"

#include <cstdlib>
#include <exception>
#include <iostream>

using namespace std;

/**
* @brief Считывает линию с проверкой ввода.
* @return Считанная линия.
*/
Line getLine()
{
    try
    {
        return Line::Read(cin);
    }
    catch (const exception& error)
    {
        cerr << "Ошибка: " << error.what() << endl;
        exit(1);
    }
}

/**
* @brief Основной код программы.
* @return 0, если программа завершилась успешно, иначе 1.
*/
int main()
{
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    cout << "Задайте линию: x1 y1 x2 y2; тип_линии; толщина; red green blue" << endl;
    cout << "Типы линии: solid, dash, dot, dash-dot, dashdotdot" << endl;
    cout << "Введите данные: ";

    Line line = getLine();
    line.ToString(cout);

    return 0;
}
