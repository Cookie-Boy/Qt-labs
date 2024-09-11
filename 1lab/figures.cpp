#include "figures.h"
#include <QtMath>

void Rectangle::setWidth(double width)
{
    this->width = width;
}

double Rectangle::getWidth()
{
    return this->width;
}

void Rectangle::setLength(double length)
{
    this->length = length;
}

double Rectangle::getLength()
{
    return this->length;
}

void Parallelogram::setHeight(double height)
{
    this->height = height;
}

double Parallelogram::getHeight()
{
    return this->height;
}

void Triangle::setLength(double length)
{
    this->length = length;
}

double Triangle::getLength()
{
    return this->length;
}

void Triangle::setHeight(double height)
{
    this->height = height;
}

double Triangle::getHeight()
{
    return this->height;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}

double Circle::getRadius()
{
    return this->radius;
}

void Sector::setAngle(double angle)
{
    this->angle = angle;
}

double Sector::getAngle()
{
    return this->angle;
}

double Figure::getSquare()
{
    return 0;
}

double Rectangle::getSquare()
{
    return this->width * this->length;
}

double Parallelogram::getSquare()
{
    return this->width * this->height;
}

double Triangle::getSquare()
{
    return (this->length * this->height) / 2;
}

double Circle::getSquare()
{
    return M_PI * (this->radius * this->radius);
}

double Sector::getSquare()
{
    return (M_PI * (this->radius * this->radius) * this->angle) / 360;
}


