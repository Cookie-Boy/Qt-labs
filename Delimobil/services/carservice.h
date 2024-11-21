#ifndef CARSERVICE_H
#define CARSERVICE_H

#include <vector>
#include <QString>
#include "../models/car.h"
#include "../repositories/carrepository.h"
#include "../models/authorizeduser.h"

class CarService
{
public:
    static CarService& instance();
    QVector<Car> getAllCars();
    bool changeCar(const Car &oldCar, const Car &newCar);

    bool addCar(QString &name,
                short rating,
                QString &category,
                QString &transmission,
                QString &driveType,
                double engineCapacity,
                double power,
                QString &imagePath,
                bool hasHeatedSeats,
                bool hasHeatedSteeringWheel,
                bool hasParkingSensors,
                bool isBlocked);

    bool deleteCar(const Car &car);

    QVector<QString> getUniqueCarNames();

    Car* getCarByName(QString name);

    double getOptimalPricePerMinute(const Car& car);
    double getOptimalPricePerHour(const Car& car);

    void startRent(Car& car);

private:
    CarRepository& carRepository;
    AuthorizedUser& authorizedUser;
    CarService();
};

#endif // CARSERVICE_H
