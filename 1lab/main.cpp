#include "mainwindow.h"
#include <QApplication>

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

    double getSquare() override
    {
        return width * length;
    }

private:
    void setWidth(double width)
    {
        this->width = width;
    }

    double getWidth()
    {
        return this->width;
    }

    void setLength(double length)
    {
        this->length = length;
    }

    double getLength()
    {
        return this->length;
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
