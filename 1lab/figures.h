#ifndef FIGURES_H
#define FIGURES_H

class Figure
{
public:
    virtual ~Figure() { }
protected:
    virtual double getSquare();
};

class Rectangle : public Figure
{
public:
    double width;
    double length;

    double getSquare() override;

protected:

    void setWidth(double width);
    double getWidth();
    void setLength(double length);
    double getLength();
};

class Parallelogram : public Rectangle
{
public:
    double height;
    double getSquare() override;
protected:
    void setHeight(double height);
    double getHeight();
};

class Rhombus : public Parallelogram
{

};

class Triangle : public Figure
{
    double length;
    double height;
    double getSquare() override;

protected:
    void setLength(double length);
    double getLength();
    void setHeight(double height);
    double getHeight();
};

class Circle : public Figure
{
public:
    double radius;
    double getSquare() override;
protected:
    void setRadius(double radius);
    double getRadius();
};

class Sector : public Circle
{
public:
    double angle;
    double getSquare() override;
protected:
    void setAngle(double angle);
    double getAngle();
};

#endif // FIGURES_H
