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
    bool updateCar(long id,
                   Car& car);

    bool addCar(QString name,
                short rating,
                QString category,
                QString transmission,
                QString driveType,
                double engineCapacity,
                double power,
                bool hasSpaciousTrunk,
                bool hasHeatedSeats,
                bool hasHeatedSteeringWheel,
                bool hasParkingSensors);

    double getOptimalPricePerMinute(const Car& car);
    double getOptimalPricePerHour(const Car& car);

    void startRent(Car& car);

private:
    CarRepository& carRepository;
    AuthorizedUser& authorizedUser;
    CarService();
};

#endif // CARSERVICE_H
