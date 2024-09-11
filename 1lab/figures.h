#ifndef FIGURES_H
#define FIGURES_H

class Figure
{
public:
    virtual ~Figure() { }
protected:
    virtual double getArea(double a, double b, double c);
    virtual double getArea(double a, double b);
    virtual double getArea(double a);
};

class Rectangle : public Figure
{
public:
    double getArea(double a, double b) override;
};

class Parallelogram : public Rectangle
{

};

class Trapezium : public Figure
{
public:
    double getArea(double a, double b, double c) override;
};

class Rhombus : public Figure
{
public:
    double getArea(double a, double b) override;
};

class Triangle : public Figure
{
public:
    double getArea(double a, double b) override;
};

class Circle : public Figure
{
public:
    double getArea(double a) override;
};

class Sector : public Figure
{
public:
    double getArea(double a, double b) override;
};

#endif // FIGURES_H
