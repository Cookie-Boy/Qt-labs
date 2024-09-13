#ifndef FIGURES_H
#define FIGURES_H

class Figure
{
public:
    virtual ~Figure() { }
    virtual double getArea();
    void setA(double a);
    void setB(double b);
    void setC(double c);
    double getA();
    double getB();
    double getC();

protected:
    double a = 0;
    double b = 0;
    double c = 0;
};


class Square : public Figure
{
public:
    double getArea() override;
};

class Rectangle : public Figure
{
public:
    double getArea() override;
};

class Parallelogram : public Figure
{
public:
    double getArea() override;
};

class Trapezium : public Figure
{
public:
    double getArea() override;
};

class Rhombus : public Parallelogram
{

};

class Triangle : public Figure
{
public:
    double getArea() override;
};

class Circle : public Figure
{
public:
    double getArea() override;
};

class Sector : public Figure
{
public:
    double getArea() override;
};

#endif // FIGURES_H
