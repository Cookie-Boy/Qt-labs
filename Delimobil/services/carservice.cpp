#include "carservice.h"
#include "../models/authorizeduser.h"

CarService::CarService() : carRepository(CarRepository::instance()) { }

CarService& CarService::instance() {
    static CarService instance;
    return instance;
}

QVector<Car> CarService::getAllCars() {
    return CarRepository::instance().findAll();
}

bool CarService::addCar(QString name,
                        short rating,
                        QString category,
                        QString transmission,
                        QString driveType,
                        double engineCapacity,
                        double power,
                        bool hasSpaciousTrunk,
                        bool hasHeatedSeats,
                        bool hasHeatedSteeringWheel,
                        bool hasParkingSensors) {
    Car car = Car(name, rating, category, transmission, driveType, engineCapacity, power,
                  hasSpaciousTrunk, hasHeatedSeats, hasHeatedSteeringWheel, hasParkingSensors);
    return carRepository.saveCar(car);
}

double CarService::getOptimalPricePerMinute(const Car &car) {
    double startValue = 8;
    QString category = car.getCategory();
    int k;
    if (category == "Эконом")
        k = 1;
    else if (category == "Комфорт")
        k = 2;
    else
        k = 3;

    double drivingExp = AuthorizedUser::instance().getUser().getDrivingExperience();

    return startValue * k * (((10 - drivingExp) * 10 + car.getRating() + 100) / 100);
}
