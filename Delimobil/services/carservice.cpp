#include "carservice.h"
#include "../models/authorizeduser.h"

CarService::CarService() : carRepository(CarRepository::instance()),
    authorizedUser(AuthorizedUser::instance()) { }

CarService& CarService::instance() {
    static CarService instance;
    return instance;
}

QVector<Car> CarService::getAllCars() {
    return CarRepository::instance().findAll();
}

bool CarService::changeCar(const Car &oldCar, const Car &newCar) {
    return carRepository.updateCar(oldCar, newCar);
}

bool CarService::addCar(QString &name,
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
                        QPair<QDate, QDate> blockedPeriod) {
    Car car = Car(name, rating, category, transmission, driveType, engineCapacity, power, imagePath,
                  hasHeatedSeats, hasHeatedSteeringWheel, hasParkingSensors, blockedPeriod);
    return carRepository.saveCar(car);
}

bool CarService::deleteCar(const Car &car) {
    return carRepository.deleteCarById(car.getId());
}

QVector<QString> CarService::getUniqueCarNames() {
    return carRepository.getUniqueNames();
}

Car* CarService::getCarByName(QString name) {
    return carRepository.findCarByName(name);
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

    double drivingExp = AuthorizedUser::instance().getUser()->getDrivingExperience();

    return startValue * k * (((10 - drivingExp) * 10 + car.getRating() + 100) / 100);
}

double CarService::getOptimalPricePerHour(const Car &car) {
    double startValue = 6;
    QString category = car.getCategory();
    int k;
    if (category == "Эконом")
        k = 1;
    else if (category == "Комфорт")
        k = 2;
    else
        k = 3;

    double drivingExp = AuthorizedUser::instance().getUser()->getDrivingExperience();

    return startValue * k * (((10 - drivingExp) * 10 + car.getRating() + 100) / 100) * 60;
}

bool CarService::isBlockedOnDate(const Car &car, const QDate &date) {
    auto blockedPeriod = car.getBlockedPeriod();
    if (blockedPeriod.first.isValid() && blockedPeriod.second.isValid()) {
        return date >= blockedPeriod.first && date <= blockedPeriod.second;
    }
    return false;
}

void CarService::startRent(Car& car) {
    authorizedUser.setCar(&car);
}
