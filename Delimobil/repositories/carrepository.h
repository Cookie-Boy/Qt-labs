#ifndef CARREPOSITORY_H
#define CARREPOSITORY_H

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "../models/car.h"

class CarRepository
{
public:
    static CarRepository& instance();

    bool saveCar(const Car& car);
    QVector<Car> findAll();

private:
    long getFreeId();
    CarRepository();
};

#endif // CARREPOSITORY_H
