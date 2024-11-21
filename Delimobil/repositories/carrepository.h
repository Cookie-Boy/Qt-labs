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
    bool updateCar(const Car &oldCar, const Car &newCar);
    bool deleteCarById(long id);
    QVector<Car> findAll();
    QVector<QString> getUniqueNames();
    Car* findCarByName(QString name);

private:
    long getFreeId();
    Car* getCarByQuery(QSqlQuery& query);
    CarRepository();
};

#endif // CARREPOSITORY_H
