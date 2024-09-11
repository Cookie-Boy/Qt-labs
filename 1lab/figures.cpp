#include "figures.h"
#include <QtMath>

double Figure::getArea(double a)
{
    return 0;
}

double Figure::getArea(double a, double b)
{
    return 0;
}

double Figure::getArea(double a, double b, double c)
{
    return 0;
}

double Rectangle::getArea(double a, double b)
{
    return a * b;
}

double Triangle::getArea(double a, double b)
{
    return (a * b) / 2;
}

double Trapezium::getArea(double a, double b, double c)
{
    return (a + b) * c / 2;
}

double Circle::getArea(double a)
{
    return M_PI * (a * a);
}

double Sector::getArea(double a, double b)
{
    return (M_PI * (a * a) * b) / 360;
}
