#include "figures.h"
#include <QtMath>

double Figure::getArea()
{
    return 0;
}

void Figure::setA(double a)
{
    this->a = a;
}

void Figure::setB(double b)
{
    this->b = b;
}

void Figure::setC(double c)
{
    this->c = c;
}

double Figure::getA()
{
    return a;
}

double Figure::getB()
{
    return b;
}

double Figure::getC()
{
    return c;
}

double Square::getArea()
{
    return a * a;
}

double Rectangle::getArea()
{
    return a * b;
}

double Parallelogram::getArea()
{
    return a * b;
}

double Triangle::getArea()
{
    return (a * b) / 2;
}

double Trapezium::getArea()
{
    return (a + b) * c / 2;
}

double Circle::getArea()
{
    return M_PI * (a * a);
}

double Sector::getArea()
{
    return (M_PI * (a * a) * b) / 360;
}
